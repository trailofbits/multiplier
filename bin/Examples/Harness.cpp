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
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, mx::kInvalidEntityId, "ID of the entity to harness");
DEFINE_string(entity_name, "", "Name of the entity to harness");

using SeenSet = std::set<mx::RawEntityId>;
using WorkList = std::vector<mx::RawEntityId>;
using DepGraph = std::set<std::pair<mx::RawEntityId, mx::RawEntityId>>;

// Sometimes we see two separate definitions of an entity, e.g.
//
// `typedef void CURL;` and `typedef struct { ... } CURL;` where the former
// is an opaque, exported type, and the latter is the internal type. We want
// to find the internal version.
static mx::Decl LongestDefinition(mx::Decl decl) {
  size_t num_toks = 0u;

  for (mx::Decl redecl : decl.redeclarations()) {
    if (decl.is_definition()) {
      if (auto redecl_num_toks = redecl.tokens().size();
          redecl_num_toks > num_toks) {
        decl = redecl;
        num_toks = redecl_num_toks;
      }
    }
  }

  return decl;
}

// Go and find the entity to be harnessed.
static std::optional<mx::Decl> FindEntity(const mx::Index &index,
                                          std::string_view name,
                                          mx::RawEntityId id) {
  if (!name.empty()) {
    std::string name_s(name.data(), name.size());
    for (mx::DeclCategory cat : mx::EnumerationRange<mx::DeclCategory>()) {
      for (mx::NamedDecl nd : index.query_entities(name_s, cat)) {
        if (nd.name() == name) {
          return LongestDefinition(nd);
        }
      }
    }
  } else if (id != mx::kInvalidEntityId) {
    mx::VariantEntity maybe_entity = index.entity(id);
    if (std::holds_alternative<mx::Decl>(maybe_entity)) {
      return std::get<mx::Decl>(maybe_entity);
    }
  }
  return std::nullopt;
}

static void CollectEntities(const mx::Index &index, mx::RawEntityId frag_id,
                            WorkList &wl, DepGraph &deps) {

  mx::Fragment frag = std::get<mx::Fragment>(index.entity(frag_id));

  std::vector<mx::RawEntityId> strong_decl_ids;
  std::vector<mx::RawEntityId> weak_decl_ids;
  std::vector<mx::RawEntityId> pending_decl_ids;

  for (mx::Token tok : frag.parsed_tokens()) {
    if (tok.kind() != mx::TokenKind::IDENTIFIER) {
      continue;
    }

    bool in_const_array_size = false;
    bool found_entities = false;
    for (auto tc = tok.context(); tc; tc = tc->parent()) {

      if (std::optional<mx::Type> ty = tc->as_type()) {

        // E.g. `tok(foo_s) -> type(struct foo_s)`. We can't yet decide if a
        // tag is a strong or weak dependency, because it might be `tag x;`
        // which needs to be strong, or `tag *x;` which can be weak.
        if (auto tag_ty = mx::TagType::from(ty)) {
          mx::TagDecl td = tag_ty->declaration();
          if (td.name() == tok.data()) {
            pending_decl_ids.emplace_back(td.id());
            found_entities = true;
          }

        // Typedefs always need strong declarations, even if we have
        // `typedef_name *foo;` because we need to see what the typedef is.
        //
        // However, a typedef itself may include a forward declaration, and so
        // for that thing, we need to decide if we need a strong or weak
        // declaration, and so we defer that to the pending decls.
        } else if (auto typedef_ty = mx::TypedefType::from(ty)) {
          mx::TypedefNameDecl td = typedef_ty->declaration();
          if (td.name() != tok.data()) {
            continue;
          }

          found_entities = true;
          strong_decl_ids.emplace_back(td.id());

          // If we have something like:
          //
          //    typedef struct foo_s foo;
          //
          // Then in the following, we only need a weak link to `struct foo_s`:
          //
          //    foo *bar;
          //
          // But in the following, we need a strong link to `struct foo_s`:
          //
          //    foo bar;
          //
          // So we defer to the pending list to figure that out. In practice,
          // it's perfectly okay for a typedef to be defined in terms of a
          // forward-declared tag type, but if we need the size of the typedef,
          // then we also need the size of the tag type.
          auto dty = td.underlying_type().desugared_type();
          if (auto dtag_ty = mx::TagType::from(dty)) {
            pending_decl_ids.emplace_back(dtag_ty->declaration().id());
          }

        // If we have a constant array type, then the calculation of the size
        // of the array could introduce strong dependencies.
        } else if (auto arr_ty = mx::ConstantArrayType::from(ty)) {

          in_const_array_size = true;

          if (auto size = arr_ty->size_expression()) {
            if (auto size_decl = size->referenced_declaration()) {
              strong_decl_ids.emplace_back(size_decl->id());
              found_entities = true;
            }
          }

        // We ascended the token contexts and saw something like:
        //
        //    tok(foo) -> type(foo) -> type(foo *) -> ...
        //
        // Which could correspond to `foo` in `foo *bar;`. We don't require
        // a definition of `foo` or any other decls seen along the way, only
        // a declaration of them, so we move them to the weak decls list.
        } else if (ty->is_any_pointer_type()) {
          weak_decl_ids.insert(weak_decl_ids.end(), pending_decl_ids.begin(),
                               pending_decl_ids.end());
          pending_decl_ids.clear();
        }

      // E.g. `tok(var) -> decl(var) -> ...` in `int var;`.
      } else if (std::optional<mx::Decl> decl = tc->as_declaration()) {
        auto nd = mx::NamedDecl::from(decl);
        if (!nd || nd->name() != tok.data()) {
          continue;
        }

        found_entities = true;

        // A usage of a field, enum constant, or typedef requires a strong
        // definition.
        if (mx::FieldDecl::from(decl) ||
            mx::EnumConstantDecl::from(decl) ||
            mx::TypedefNameDecl::from(decl)) {
          strong_decl_ids.emplace_back(decl->id());

        } else {
          weak_decl_ids.emplace_back(decl->id());
        }

      } else if (std::optional<mx::Stmt> stmt = tc->as_statement()) {
        auto ref_decl = stmt->referenced_declaration();
        if (!ref_decl) {
          continue;
        }

        auto nd = mx::NamedDecl::from(ref_decl);
        if (!nd || nd->name() != tok.data()) {
          continue;
        }

        found_entities = true;

        // These can be forward-declared.
        if (mx::FunctionDecl::from(ref_decl) ||
            mx::VarDecl::from(ref_decl)) {
          weak_decl_ids.emplace_back(ref_decl->id());

        } else if (mx::FieldDecl::from(ref_decl) ||
                   mx::EnumConstantDecl::from(ref_decl) ||
                   mx::TypedefNameDecl::from(ref_decl) ||
                   mx::DeclRefExpr::from(stmt) ||
                   mx::MemberExpr::from(stmt)) {
          strong_decl_ids.emplace_back(ref_decl->id());

        } else {
          weak_decl_ids.emplace_back(ref_decl->id());
        }
      }
    }

    // Clang has issues recording the size expression of constant arrays.
    // So here we'll try to special case that an opportunistically look
    // for symbols with matching names.
    if (in_const_array_size && !found_entities) {
      if (auto ent = FindEntity(index, tok.data(), mx::kInvalidEntityId)) {
        strong_decl_ids.emplace_back(ent->id());
      }
    }

    strong_decl_ids.insert(strong_decl_ids.end(), pending_decl_ids.begin(),
                           pending_decl_ids.end());
    pending_decl_ids.clear();
  }

  // Sort and unique the strong and weak dependencies.
  std::sort(strong_decl_ids.begin(), strong_decl_ids.end());
  auto it = std::unique(strong_decl_ids.begin(), strong_decl_ids.end());
  strong_decl_ids.erase(it, strong_decl_ids.end());

  std::sort(weak_decl_ids.begin(), weak_decl_ids.end());
  it = std::unique(weak_decl_ids.begin(), weak_decl_ids.end());
  weak_decl_ids.erase(it, weak_decl_ids.end());

  // A strong connection requires a definition.
  for (mx::RawEntityId id : strong_decl_ids) {
    mx::Decl decl = std::get<mx::Decl>(index.entity(id));

    // A strong connection back into our own fragment, ignore it.
    if (mx::Fragment::containing(decl).id() == frag_id) {
      continue;
    }

    decl = LongestDefinition(decl);

    auto strong_frag_id = mx::Fragment::containing(decl).id().Pack();
    if (frag_id != strong_frag_id) {
      deps.emplace(frag_id, strong_frag_id);
      wl.push_back(strong_frag_id);
    }
  }

  // A weak connection requires a declaration, and ideally also brings in
  // a definition.
  for (mx::RawEntityId id : weak_decl_ids) {

    // We've already added it as a strong declaration; skip it.
    if (std::find(strong_decl_ids.begin(), strong_decl_ids.end(), id) !=
        strong_decl_ids.end()) {
      continue;
    }

    mx::Decl decl = std::get<mx::Decl>(index.entity(id));

    // A weak connection back into our own fragment, ignore it.
    if (mx::Fragment::containing(decl).id() == frag_id) {
      continue;
    }

    mx::Decl def = LongestDefinition(decl);
    for (mx::Decl redecl : def.redeclarations()) {
      if (!redecl.is_definition()) {
        decl = redecl;
      }
    }

    auto strong_frag_id = mx::Fragment::containing(def).id().Pack();
    auto weak_frag_id = mx::Fragment::containing(decl).id().Pack();

    // E.g. `typedef struct foo_s` { struct foo_s *x; ... } foo;`
    if (strong_frag_id == frag_id || weak_frag_id == frag_id) {
      continue;
    }

    // If we have a separate definition and declaration, and if we only need
    // to maintain a weak link then we want a strong link between this fragment
    // and the (forward) declaration, and then a strong link between the
    // definition and the declaration. This organization helps to break cycles.
    wl.push_back(strong_frag_id);
    if (strong_frag_id != weak_frag_id) {
      deps.emplace(strong_frag_id, weak_frag_id);
      deps.emplace(frag_id, weak_frag_id);
      wl.push_back(weak_frag_id);

    } else {
      deps.emplace(frag_id, weak_frag_id);
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

    // First get a non-recursive estimate.
    for (mx::RawEntityId parent_id : parents) {
      depth = std::max(dag[parent_id].depth + 1u, depth);
    }

    if (!depth) {
      depth = 1u;
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
    << " [--db DATABASE] [--entity_id ID | --entity_name NAME]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  std::optional<mx::Decl> entity = FindEntity(
      index, FLAGS_entity_name, FLAGS_entity_id);
  if (!entity) {
    std::cerr << "Unable to locate entity by id or name.\n";
    return EXIT_FAILURE;
  }

  SeenSet seen;
  WorkList wl;
  DepGraph deps;
  std::unordered_map<mx::RawEntityId, DAG> dag;

  auto initial_frag_id = mx::Fragment::containing(entity.value()).id().Pack();
  wl.push_back(initial_frag_id);

  // Collect the strong fragments that we need.
  for (auto i = 0u; i < wl.size(); ++i) {
    mx::RawEntityId frag_id = wl[i];
    if (seen.emplace(frag_id).second) {
      dag.emplace(frag_id, frag_id);
      CollectEntities(index, frag_id, wl, deps);
    }
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

  // Sort the fragments in reverse order of their depth.
  std::vector<mx::RawEntityId> frags;
  for (mx::RawEntityId frag_id : seen) {
    frags.push_back(frag_id);
    dag[frag_id].Depth(dag);
  }
  std::sort(frags.begin(), frags.end(),
            [&dag] (mx::RawEntityId a, mx::RawEntityId b) {
              return dag[b].depth < dag[a].depth;
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
        if (d.is_definition()) {
          std::cerr << " (def)";
        }
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
      mx::TokenRange file_toks;
      if (auto file = mx::File::containing(last_frag_file_tok)) {
        file_toks = file->tokens();
      }
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

