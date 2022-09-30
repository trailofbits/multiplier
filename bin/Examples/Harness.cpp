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

static void CollectEntities(const mx::Index &index, mx::RawEntityId frag_id,
                            WorkList &wl, DepGraph &deps) {

  mx::Fragment frag = std::get<mx::Fragment>(index.entity(frag_id));

  std::vector<mx::RawEntityId> decl_ids;
  std::vector<mx::RawEntityId> weak_decl_ids;
  std::vector<mx::RawEntityId> curr_decl_ids;

  for (mx::Token tok : frag.parsed_tokens()) {
//    std::cout << tok.data();
    auto seen_type = false;
    for (auto tc = mx::TokenContext::of(tok); tc; tc = tc->parent()) {
      if (std::optional<mx::Type> ty = tc->as_type()) {
        seen_type = true;

        // E.g. `tok(foo_s) -> type(struct foo_s)`
        if (auto tag_ty = mx::TagType::from(ty)) {
//          std::cout << " -> TAG(" << tag_ty->declaration().name() << ")";
          curr_decl_ids.emplace_back(tag_ty->declaration().id());

        } else if (auto typedef_ty = mx::TypedefType::from(ty)) {
//          std::cout << " -> TYPEDEF(" << typedef_ty->declaration().name() << ")";
          curr_decl_ids.emplace_back(typedef_ty->declaration().id());

        // We ascended the token contexts and saw something like:
        //
        //    tok(foo) -> type(foo) -> type(foo *) -> ...
        //
        // Which could correspond to `foo` in `foo *bar;`. We don't require
        // a definition of `foo` or any other decls seen along the way, only
        // a declaration of them, so we move them to the weak decls list.
        } else if (ty->is_any_pointer_type()) {
//          std::cout << " -> POINTER";
          weak_decl_ids.insert(weak_decl_ids.end(), curr_decl_ids.begin(),
                               curr_decl_ids.end());
          curr_decl_ids.clear();
        }

      // E.g. `tok(var) -> decl(var) -> ...` in `int var;`.
      } else if (std::optional<mx::Decl> decl = tc->as_declaration()) {
        if (auto nd = mx::NamedDecl::from(decl)) {
//          std::cout << " -> DECL(" << nd->name() << ")";
          decl_ids.emplace_back(nd->id());  // Strong.
        }
      } else if (std::optional<mx::Stmt> stmt = tc->as_statement()) {
        if (auto ref_decl = stmt->referenced_declaration()) {
          if (auto nd = mx::NamedDecl::from(ref_decl)) {
//            std::cout << " -> STMT_REF(" << nd->name() << ")";
            decl_ids.emplace_back(nd->id());  // Strong.
          }
        }
      }
    }
//    std::cout << '\n';

    decl_ids.insert(decl_ids.end(), curr_decl_ids.begin(), curr_decl_ids.end());
    curr_decl_ids.clear();
  }
//  std::cout << '\n';

  std::sort(decl_ids.begin(), decl_ids.end());
  auto it = std::unique(decl_ids.begin(), decl_ids.end());
  decl_ids.erase(it, decl_ids.end());

  std::sort(weak_decl_ids.begin(), weak_decl_ids.end());
  it = std::unique(weak_decl_ids.begin(), weak_decl_ids.end());
  weak_decl_ids.erase(it, weak_decl_ids.end());

  // A deps connection requires a definition.
  for (mx::RawEntityId id : decl_ids) {
    mx::Decl decl = std::get<mx::Decl>(index.entity(id));
    if (auto def = decl.definition()) {
      decl = std::move(def.value());
    }

    auto strong_frag_id = mx::Fragment::containing(decl).id().Pack();
    if (frag_id != strong_frag_id &&
        deps.emplace(frag_id, strong_frag_id).second) {
      wl.push_back(strong_frag_id);
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
      deps.emplace(frag_id, weak_frag_id);
      wl.push_back(weak_frag_id);
    }
  }
}

struct DAG {
  const mx::RawEntityId frag_id{mx::kInvalidEntityId};
  unsigned depth{0u};
  std::vector<mx::RawEntityId> parents;
  std::vector<mx::RawEntityId> children;

  inline DAG(void) = default;
  inline DAG(mx::RawEntityId frag_id_)
      : frag_id(frag_id_) {}

  unsigned Depth(std::unordered_map<mx::RawEntityId, DAG> &dag) {
    if (depth) {
      return depth;
    }

    // NOTE(pag): We pre-initialize the depth of the initial/target fragment
    //            with `1`, and everything should come after it. So this is
    //            a safe forcing function for that.
    depth = 2u;

    // First get a non-recursive estimate.
    for (mx::RawEntityId parent_id : parents) {
      depth = std::max(dag[parent_id].depth + 1u, depth);
    }

    // Next, get a better version via recursion.
    for (mx::RawEntityId parent_id : parents) {
      depth = std::max(dag[parent_id].Depth(dag) + 1u, depth);
    }

    return depth;
  }
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
  DepGraph deps;

  auto initial_frag_id = mx::Fragment::containing(entity.value()).id().Pack();
  wl.push_back(initial_frag_id);

  // Collect the strong fragments that we need.
  while (!wl.empty()) {
    mx::RawEntityId frag_id = wl.back();
    wl.pop_back();
    if (seen.emplace(frag_id).second) {
      CollectEntities(index, frag_id, wl, deps);
    }
  }

  // Make sure every seen node is represented with a DAG.
  std::unordered_map<mx::RawEntityId, DAG> dag;
  for (auto frag_id : seen) {
    dag.emplace(frag_id, frag_id);
  }

  // Convert the edges of `deps` into parent-child relations in a (hopefully)
  // DAG.
  for (auto [from_frag_id, to_frag_id] : deps) {
    DAG &from_dag = dag[from_frag_id];
    DAG &to_dag = dag[to_frag_id];

    if (std::find(to_dag.parents.begin(),
                  to_dag.parents.end(), from_frag_id) ==
        to_dag.parents.end()) {
      from_dag.children.push_back(to_frag_id);
      to_dag.parents.push_back(from_frag_id);
    }
  }

  // Pre-initialize the initial fragment to have depth 1. It is what we want
  // to have appear last in our file.
  dag[initial_frag_id].depth = 1u;

  // Sort the fragments in reverse order of their depth.
  std::vector<mx::RawEntityId> frags;
  frags.insert(frags.end(), seen.begin(), seen.end());
  std::sort(frags.begin(), frags.end(),
            [&dag] (mx::RawEntityId a, mx::RawEntityId b) {
              return dag[b].Depth(dag) < dag[a].Depth(dag);
            });

  std::cerr
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  auto i = 0u;
  for (mx::RawEntityId frag_id : frags) {
    DAG &d = dag[frag_id];
    std::cerr << "f" << d.frag_id << " [label=<<TABLE><TR><TD>";
    for (mx::Decl d : index.fragment(frag_id)->top_level_declarations()) {
      if (auto nd = mx::NamedDecl::from(d)) {
        std::cerr << nd->name();
        break;
      }
    }
    std::cerr
        << "</TD></TR><TR><TD>depth=" << d.depth << " order="
        << i << "</TD></TR></TABLE>>];\n";
    for (auto to_frag_id : d.children) {
      std::cerr << "f" << frag_id << " -> f" << to_frag_id;
      if (d.depth >= dag[to_frag_id].depth) {
        std::cerr << " [color=red]";
      }
      std::cerr << ";\n";
    }
    ++i;
  }

  std::cerr << "}\n";

  for (mx::RawEntityId frag_id : frags) {
    mx::Fragment frag = std::get<mx::Fragment>(index.entity(frag_id));
    auto sep = "";

    for (mx::Token tok : frag.parsed_tokens()) {
      std::cout << sep << tok.data();
      sep = " ";
    }

    // Add any missing semi-colons.
    mx::TokenRange frag_file_toks = frag.file_tokens();
    if (frag_file_toks.size()) {
      mx::Token last_frag_file_tok = frag_file_toks.back();
      mx::TokenRange file_toks =
          mx::File::containing(last_frag_file_tok)->tokens();
      mx::FileTokenId lti = std::get<mx::FileTokenId>(
          mx::EntityId(last_frag_file_tok.id()).Unpack());

      if (lti.offset + 1u < file_toks.size()) {
        mx::Token pt = file_toks[lti.offset + 1u];
        if (pt.kind() == mx::TokenKind::SEMI) {
          std::cout << pt.data();
        }
      }
    }

    std::cout << "\n\n";
  }

  return EXIT_SUCCESS;
}

