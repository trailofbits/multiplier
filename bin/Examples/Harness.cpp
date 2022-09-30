// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <set>
#include <vector>
#include <unordered_map>

#include "Index.h"

DEFINE_uint64(entity_id, 0, "ID of the entity to harness");
DEFINE_string(entity_name, "", "Name of the entity to harness");

using SeenSet = std::set<mx::RawEntityId>;
using WorkList = std::vector<mx::RawEntityId>;
using DepGraph = std::set<std::pair<mx::RawEntityId, mx::RawEntityId>>;

// Go and find the entity to be harnessed.
static std::optional<mx::Decl> FindEntity(const mx::Index &index) {
  if (!FLAGS_entity_name.empty()) {
    for (mx::DeclCategory cat : {mx::DeclCategory::FUNCTION,
                                 mx::DeclCategory::INSTANCE_METHOD,
                                 mx::DeclCategory::CLASS_METHOD,
                                 mx::DeclCategory::PARAMETER_VARIABLE,
                                 mx::DeclCategory::LOCAL_VARIABLE,
                                 mx::DeclCategory::GLOBAL_VARIABLE,
                                 mx::DeclCategory::CLASS_MEMBER,
                                 mx::DeclCategory::INSTANCE_MEMBER,
                                 mx::DeclCategory::ENUMERATOR}) {
      for (mx::NamedDecl nd : index.query_entities(FLAGS_entity_name, cat)) {
        if (nd.name() == FLAGS_entity_name) {
          return nd;
        }
      }
    }
  } else if (FLAGS_entity_id) {
    mx::VariantEntity maybe_entity = index.entity(FLAGS_entity_id);
    if (std::holds_alternative<mx::Decl>(maybe_entity)) {
      auto decl = std::get<mx::Decl>(maybe_entity);
      if (auto def = decl.definition()) {
        return def.value();
      } else {
        return decl;
      }
    }
  }
  return std::nullopt;
}

static mx::RawEntityId CanonicalId(const mx::Decl &decl) {
  for (mx::Decl redecl : decl.redeclarations()) {
    return redecl.id();
  }
  return decl.id();
}

static void CollectEntities(const mx::Index &index, mx::RawEntityId frag_id,
                            WorkList &wl, DepGraph &strong, DepGraph &weak) {

  mx::Fragment frag = std::get<mx::Fragment>(index.entity(frag_id));

  std::vector<mx::RawEntityId> decl_ids;
  std::vector<mx::RawEntityId> weak_decl_ids;
  std::vector<mx::RawEntityId> curr_decl_ids;

  for (mx::Token tok : frag.parsed_tokens()) {
    for (auto tc = mx::TokenContext::of(tok); tc; tc = tc->parent()) {
      if (std::optional<mx::Type> ty = tc->as_type()) {

        // We ascended the token contexts and saw something like:
        //
        //    tok(foo) -> type(foo) -> type(foo *) -> ...
        //
        // Which could correspond to `foo` in `foo *bar;`. We don't require
        // a definition of `foo` or any other decls seen along the way, only
        // a declaration of them, so we move them to the weak decls list.
        if (ty->is_any_pointer_type()) {
          weak_decl_ids.insert(weak_decl_ids.end(), curr_decl_ids.begin(),
                               curr_decl_ids.end());
          curr_decl_ids.clear();

        // E.g. `tok(foo_s) -> type(struct foo_s)`
        } else if (std::optional<mx::TagDecl> tag_decl =
                      ty->as_tag_declaration()) {
          curr_decl_ids.emplace_back(tag_decl->id());

        } else if (std::optional<mx::TypedefType> typedef_ty =
                       mx::TypedefType::from(ty)) {
          curr_decl_ids.emplace_back(typedef_ty->declaration().id());
        }

      // E.g. `tok(var) -> decl(var) -> ...` in `int var;`.
      } else if (std::optional<mx::Decl> decl = tc->as_declaration()) {
        decl_ids.emplace_back(decl->id());  // Strong.

      } else if (std::optional<mx::Stmt> stmt = tc->as_statement()) {
        if (auto ref_decl = stmt->referenced_declaration()) {
          decl_ids.emplace_back(ref_decl->id());  // Strong.
        }
      }
    }

    decl_ids.insert(decl_ids.end(), curr_decl_ids.begin(), curr_decl_ids.end());
    curr_decl_ids.clear();
  }

  std::sort(decl_ids.begin(), decl_ids.end());
  std::sort(weak_decl_ids.begin(), weak_decl_ids.end());

  // A strong connection requires a definition.
  if (&strong != &weak) {
    for (mx::RawEntityId id : decl_ids) {
      mx::Decl decl = std::get<mx::Decl>(index.entity(id));
      if (auto def = decl.definition()) {
        decl = std::move(def.value());
      }

      auto decl_frag_id = mx::Fragment::containing(decl).id().Pack();
      if (frag_id != decl_frag_id &&
          strong.emplace(frag_id, decl_frag_id).second) {
        wl.push_back(decl_frag_id);
      }
    }
  }

  // A weak connection only requires a declaration; go get the first non-
  // definition declaration.
  for (mx::RawEntityId id : weak_decl_ids) {
    mx::Decl decl = std::get<mx::Decl>(index.entity(id));
    for (mx::Decl redecl : decl.redeclarations()) {
      if (!redecl.is_definition()) {
        decl = redecl;
        break;
      }
    }

    auto weak_frag_id = mx::Fragment::containing(decl).id().Pack();
    if (frag_id != weak_frag_id) {
      weak.emplace(frag_id, weak_frag_id);
    }
  }
}

struct DAG {
  const mx::RawEntityId frag_id{mx::kInvalidEntityId};
  unsigned depth{0u};
  std::vector<mx::RawEntityId> strong_children;
  std::vector<mx::RawEntityId> weak_children;

  inline DAG(void) = default;
  inline DAG(mx::RawEntityId frag_id_)
      : frag_id(frag_id_) {}
};

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--entity_id ID | --entity_name NAME]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  std::optional<mx::Decl> entity = FindEntity(index);
  if (!entity) {
    std::cerr << "Unable to locate entity by id or name.\n";
    return EXIT_FAILURE;
  }

  SeenSet seen;
  WorkList wl;
  DepGraph strong;
  DepGraph weak;

  auto initial_frag_id = mx::Fragment::containing(entity.value()).id().Pack();
  wl.push_back(initial_frag_id);

  // Collect the strong fragments that we need.
  while (!wl.empty()) {
    mx::RawEntityId frag_id = wl.back();
    wl.pop_back();
    if (seen.emplace(frag_id).second) {
      CollectEntities(index, frag_id, wl, strong, weak);
    }
  }

  // Fill out the weak links for declarations.
  for (auto changed = true; changed; ) {
    changed = false;

    // Enqueue all weak ones.
    for (auto [from_frag_id, frag_id] : weak) {
      if (!seen.count(frag_id)) {
        wl.push_back(frag_id);
      }
    }

    // Find all weak ones.
    while (!wl.empty()) {
      mx::RawEntityId frag_id = wl.back();
      wl.pop_back();
      if (seen.emplace(frag_id).second) {
        changed = true;
        CollectEntities(index, frag_id, wl, weak, weak);
      }
    }
  }

  std::unordered_map<mx::RawEntityId, DAG> dag;
  for (auto frag_id : seen) {
    dag.emplace(frag_id, frag_id);
  }

  // Collect the strong children first.
  for (auto [from_frag_id, to_frag_id] : strong) {
    DAG &from_dag = dag[from_frag_id];
    DAG &to_dag = dag[to_frag_id];
    to_dag.depth = std::max(from_dag.depth + 1u, to_dag.depth);

    if (std::find(from_dag.strong_children.begin(),
                  from_dag.strong_children.end(), to_frag_id) ==
        from_dag.strong_children.end()) {
      from_dag.strong_children.push_back(to_frag_id);
    }
  }

  for (auto [from_frag_id, to_frag_id] : weak) {
    DAG &from_dag = dag[from_frag_id];
    DAG &to_dag = dag[to_frag_id];
    to_dag.depth = std::max(from_dag.depth + 1u, to_dag.depth);

    if ((std::find(from_dag.strong_children.begin(),
                   from_dag.strong_children.end(), to_frag_id) ==
         from_dag.strong_children.end()) &&
        (std::find(from_dag.weak_children.begin(),
                   from_dag.weak_children.end(), to_frag_id) ==
         from_dag.weak_children.end())) {
      from_dag.weak_children.push_back(to_frag_id);
    }
  }


  std::vector<mx::RawEntityId> frags;
  frags.insert(frags.end(), seen.begin(), seen.end());

  // Sketchy loop to encourage the fragments into a proper topological order.
  for (auto i = 0u; i < 10; ++i) {
    std::sort(frags.begin(), frags.end(),
              [&dag] (mx::RawEntityId a, mx::RawEntityId b) {
                return dag[b].depth < dag[a].depth;
              });

    for (mx::RawEntityId frag_id : frags) {
      DAG &parent = dag[frag_id];

      for (mx::RawEntityId child_frag_id : parent.strong_children) {
        DAG &child = dag[child_frag_id];
        child.depth = std::max(parent.depth + 1u, child.depth);
      }

      for (mx::RawEntityId child_frag_id : parent.weak_children) {
        DAG &child = dag[child_frag_id];
        child.depth = std::max(parent.depth + 1u, child.depth);
      }
    }
  }

  for (mx::RawEntityId frag_id : frags) {
    mx::Fragment frag = std::get<mx::Fragment>(index.entity(frag_id));
    auto sep = "";
    for (mx::Token tok : frag.parsed_tokens()) {
      std::cout << sep << tok.data();
      sep = " ";
    }
    std::cout << "\n\n";
  }

  return EXIT_SUCCESS;
}
