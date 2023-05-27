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

using SeenSet = std::set<mx::PackedFragmentId>;
using WorkList = std::vector<mx::PackedFragmentId>;
using DepGraph = std::set<std::pair<mx::PackedFragmentId,
                                    mx::PackedFragmentId>>;

// Get a good "canonical" decl and def pair.
//
// A good definition is the longest one. A good declaration is the shortest
// one. This latter case is a heuristic, because we might find a `struct foo`
// as our decl, but we don't want it to be inside something else that isn't
// admitted.
static std::pair<mx::Decl, mx::Decl> CanonicalPair(const mx::Decl &decl) {
  size_t num_def_toks = 0u;
  size_t num_decl_toks = ~0u;

  std::optional<mx::Decl> shortest_redecl;
  std::optional<mx::Decl> longest_def;

  for (mx::Decl redecl : decl.redeclarations()) {

    // NOTE(pag): Implicit declarations might not have any tokens.
    auto redecl_num_toks = redecl.tokens().size() + 1u;

    assert(1u < redecl_num_toks || redecl.is_implicit());

    if (redecl.is_definition()) {
      if (redecl_num_toks > num_def_toks) {
        longest_def = std::move(redecl);
        num_def_toks = redecl_num_toks;
      }
    } else if (redecl_num_toks < num_decl_toks) {
      shortest_redecl = std::move(redecl);
      num_decl_toks = redecl_num_toks;
    }
  }

  if (longest_def && !shortest_redecl) {
    shortest_redecl = longest_def;

  } else if (!longest_def && shortest_redecl) {
    longest_def = shortest_redecl;
  }

  // Sometimes we see two separate definitions of an entity, e.g.:
  //
  // `typedef void CURL;` and `typedef struct { ... } CURL;` where the former
  // is an opaque, exported type, and the latter is the internal type. We want
  // to find the internal version.
  if (longest_def->kind() == mx::DeclKind::TYPEDEF ||
      shortest_redecl->is_definition()) {
    shortest_redecl = longest_def;
  }

  return {shortest_redecl.value(), longest_def.value()};
}

// Go and find the entity to be harnessed.
static std::optional<mx::Decl> FindEntity(const mx::Index &index,
                                          std::string_view name,
                                          mx::RawEntityId id) {
  if (!name.empty()) {
    std::string name_s(name.data(), name.size());
    for (mx::NamedEntity ne : index.query_entities(name_s)) {
      if (std::holds_alternative<mx::NamedDecl>(ne)) {
        mx::NamedDecl nd = std::move(std::get<mx::NamedDecl>(ne));
        if (nd.name() == name) {
          return CanonicalPair(nd).second;
        }
      }
    }
  } else if (id != mx::kInvalidEntityId) {
    mx::VariantEntity maybe_entity = index.entity(id);
    if (std::holds_alternative<mx::Decl>(maybe_entity)) {
      mx::Decl d = std::get<mx::Decl>(maybe_entity);
      auto [decl, def] = CanonicalPair(d);
      if (d.is_definition()) {
        return def;
      } else {
        return decl;
      }
    }
  }
  return std::nullopt;
}

static void CollectEntities(
    const mx::Index &index, const mx::PackedFragmentId frag_id,
    WorkList &wl, DepGraph &deps) {

  mx::Fragment frag = index.fragment(frag_id).value();

  std::vector<mx::PackedDeclId> strong_decl_ids;
  std::vector<mx::PackedDeclId> weak_decl_ids;
  std::vector<mx::PackedDeclId> pending_decl_ids;

  // Track the last decl in the token context chain for the sake of
  // `UnaryExprOrTypeTraitExpr`s, e.g. `sizeof` or `offsetof`.
  std::optional<mx::Decl> last_decl_for_uett;

  for (mx::Token tok : frag.parsed_tokens()) {
    if (tok.kind() != mx::TokenKind::IDENTIFIER) {
      continue;
    }

    last_decl_for_uett.reset();

    bool in_const_array_size = false;
    bool found_entities = false;
    std::optional<mx::TokenContext> next_tc;
    for (auto tc = tok.context(); tc; tc = std::move(next_tc)) {
      next_tc = tc->parent();

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

          // `__builtin_va_list`, `__int128_t`, etc.
          if (td.is_implicit()) {
            assert(td.name().starts_with("__"));
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
          mx::Type dty = td.underlying_type().desugared_type();
          if (auto dtag_ty = mx::TagType::from(dty)) {
            mx::TagDecl td_in_tt = dtag_ty->declaration();
            pending_decl_ids.emplace_back(td_in_tt.id());
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
        last_decl_for_uett = decl;

        auto nd = mx::NamedDecl::from(decl);
        if (!nd || nd->name() != tok.data()) {
          continue;
        }

        // A usage of a field, enum constant requires a strong definition.
        if (mx::FieldDecl::from(decl) ||
            mx::EnumConstantDecl::from(decl)) {
          strong_decl_ids.emplace_back(decl->id());

        // Typedefs always required strong definitions.
        } else if (auto td = mx::TypedefNameDecl::from(decl)) {

          // `__builtin_va_list`, `__int128_t`, etc.
          if (td->is_implicit()) {
            assert(td->name().starts_with("__"));
            continue;
          }

          strong_decl_ids.emplace_back(decl->id());

          // If we have something like `typedef struct list_s list;`, then
          // `struct list_s` will be added to `strong_decl_ids`, but really, we
          // want it to be in the `weak_decl_id`s, otherwise if `list_s`
          // contains a `list *`, then we'll have a circular reference.
          if (!next_tc) {  // This is a top-level `typedef`.
            mx::Type dty = td->underlying_type().desugared_type();
            if (auto dtag_ty = mx::TagType::from(dty)) {
              mx::TagDecl tag = dtag_ty->declaration();

              auto it = std::remove(strong_decl_ids.begin(),
                                    strong_decl_ids.end(), tag.id());
              strong_decl_ids.erase(it, strong_decl_ids.end());

              auto it2 = std::remove(pending_decl_ids.begin(),
                                     pending_decl_ids.end(), tag.id());
              pending_decl_ids.erase(it2, pending_decl_ids.end());

              weak_decl_ids.emplace_back(tag.id());
            }
          }

        // E.g. `VarDecl`, `FunctionDecl`.
        } else {
          weak_decl_ids.emplace_back(decl->id());
        }

        found_entities = true;

      } else if (std::optional<mx::Stmt> stmt = tc->as_statement()) {

        // E.g. `sizeof`, `offsetof`, etc.
        if (last_decl_for_uett && mx::UnaryExprOrTypeTraitExpr::from(stmt)) {
          strong_decl_ids.emplace_back(last_decl_for_uett->id());
          continue;
        }

        auto ref_decl = stmt->referenced_declaration();
        if (!ref_decl) {
          continue;
        }

        auto nd = mx::NamedDecl::from(ref_decl);
        if (!nd || nd->name() != tok.data()) {
          continue;
        }

        found_entities = true;

        // These can be forward-declared. These would normally be used via
        // a `DeclRefExpr`, which would trigger the subsequent condition.
        if (mx::FunctionDecl::from(ref_decl)) {
          weak_decl_ids.emplace_back(ref_decl->id());

        // Vars might participate in `sizeof`.
        } else if (mx::VarDecl::from(ref_decl) ||
                   mx::TagDecl::from(ref_decl)) {
          last_decl_for_uett = ref_decl;
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

    // If we have leftover pending declarations, then we didn't convert them
    // to weak declarations because of their use in a pointer type, and so we
    // treat them as strong declarations.
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
  for (mx::PackedDeclId id : strong_decl_ids) {
    auto decl_def = CanonicalPair(index.entity(id).value());
    mx::Fragment decl_frag = mx::Fragment::containing(decl_def.first);
    mx::Fragment def_frag = mx::Fragment::containing(decl_def.second);
    mx::PackedFragmentId weak_frag_id = decl_frag.id();
    mx::PackedFragmentId strong_frag_id = def_frag.id();

    // E.g. `typedef struct foo_s` { struct foo_s *x; ... } foo;`
    if (strong_frag_id == frag_id || weak_frag_id == frag_id) {
      continue;
    }

    deps.emplace(frag_id, strong_frag_id);
    wl.push_back(strong_frag_id);
  }

  // A weak connection requires a declaration, and ideally also brings in
  // a definition.
  for (mx::PackedDeclId id : weak_decl_ids) {

    auto decl_def = CanonicalPair(index.entity(id).value());
    mx::Fragment decl_frag = mx::Fragment::containing(decl_def.first);
    mx::Fragment def_frag = mx::Fragment::containing(decl_def.second);
    mx::PackedFragmentId weak_frag_id = decl_frag.id();
    mx::PackedFragmentId strong_frag_id = def_frag.id();

    // E.g. `typedef struct foo_s` { struct foo_s *x; ... } foo;`
    if (strong_frag_id == frag_id || weak_frag_id == frag_id) {
      continue;
    }

    // If we have a separate definition and declaration, and if we only need
    // to maintain a weak link then we want a strong link between this fragment
    // and the (forward) declaration, and then a strong link between the
    // definition and the declaration. This organization helps to break cycles.
    wl.push_back(weak_frag_id);
    deps.emplace(frag_id, weak_frag_id);

    if (strong_frag_id != weak_frag_id) {
      deps.emplace(strong_frag_id, weak_frag_id);
      wl.push_back(strong_frag_id);
    }
  }
}

struct DAG {
  const mx::RawEntityId frag_id{mx::kInvalidEntityId};
  unsigned depth{0u};
  std::vector<mx::PackedFragmentId> parents;
  std::vector<mx::PackedFragmentId> children;

  inline DAG(void) = default;

  inline DAG(mx::PackedFragmentId frag_id_)
      : frag_id(frag_id_.Pack()) {}

  inline DAG(mx::RawEntityId frag_id_)
      : frag_id(frag_id_) {}

  unsigned Depth(std::unordered_map<mx::PackedFragmentId, DAG> &dag) {
    if (depth) {
      return depth;
    }

    // First get a non-recursive estimate.
    for (mx::PackedFragmentId parent_id : parents) {
      depth = std::max(dag[parent_id].depth + 1u, depth);
    }

    if (!depth) {
      depth = 1u;
    }

    // Next, get a better version via recursion.
    for (mx::PackedFragmentId parent_id : parents) {
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

  mx::Index index = InitExample(true);

  // Label for a fragment in the DOT digraph.
  auto frag_label = [&] (std::ostream &os, mx::PackedFragmentId frag_id) {
    for (mx::Decl decl : index.fragment(frag_id)->top_level_declarations()) {
      if (auto nd = mx::NamedDecl::from(decl); nd && !nd->name().empty()) {
        os << nd->name();
        if (decl.is_definition()) {
          os << " (def)";
        }
        break;
      }
    }
  };

  std::optional<mx::Decl> entity = FindEntity(
      index, FLAGS_entity_name, FLAGS_entity_id);
  if (!entity) {
    std::cerr << "Unable to locate entity by id or name.\n";
    return EXIT_FAILURE;
  }

  SeenSet seen;
  WorkList wl;
  DepGraph deps;
  std::unordered_map<mx::PackedFragmentId, DAG> dag;

  mx::PackedFragmentId initial_frag_id =
      mx::Fragment::containing(entity.value()).id();
  wl.push_back(initial_frag_id);

  // Collect the strong fragments that we need.
  for (auto i = 0u; i < wl.size(); ++i) {
    mx::PackedFragmentId frag_id = wl[i];
    if (!seen.emplace(frag_id).second) {
      continue;
    }

    // Find redundant fragments. This helps us prevent spitting out two
    // definitions if we have two or more.
    auto is_of_interest = false;
    for (mx::Decl tld : index.fragment(frag_id)->top_level_declarations()) {

      // Implicit declarations might make a fragment with a non-canonical
      // pair "look" interesting.
      if (tld.is_implicit()) {
        continue;
      }

      // TODO(pag): Tomorrow, check all of interest vs. any of interest.
      // Probably what is happening is there is a decl that is inside of
      // a non-canonical def/decl, e.g. `struct foo *bar();`. Could add
      // a remapping layer on frag ids to resolve these issues.

      auto [decl, def] = CanonicalPair(tld);
      mx::PackedDeclId decl_id = decl.id();
      mx::PackedDeclId def_id = def.id();
      mx::PackedDeclId tld_id = tld.id();
      if (tld_id == decl_id || tld_id == def_id) {
        is_of_interest = true;
        break;
      }
    }

    // If this fragment won't be of interest, or will generate redundant
    // definitions, then never visit it.
    if (!is_of_interest) {
      std::cout << "// Skipping fragment " << frag_id << ": ";
      frag_label(std::cout, frag_id);
      std::cout << '\n';
      continue;
    }

    dag.emplace(frag_id, frag_id);
    CollectEntities(index, frag_id, wl, deps);
  }

  assert(dag.contains(initial_frag_id));

  auto link_in_graph = [&dag] (mx::PackedFragmentId from_frag_id,
                               mx::PackedFragmentId to_frag_id) {
    DAG &from_dag = dag[from_frag_id];
    DAG &to_dag = dag[to_frag_id];

    if (std::find(to_dag.parents.begin(),
                  to_dag.parents.end(), from_frag_id) ==
        to_dag.parents.end()) {
      from_dag.children.push_back(to_frag_id);
      to_dag.parents.push_back(from_frag_id);
    }
  };

  // Convert the edges of `deps` into parent-child relations in a (hopefully)
  // directed acyclic graph.
  for (auto [from_frag_id, to_frag_id] : deps) {

    if (dag.contains(to_frag_id)) {
      assert(dag.contains(from_frag_id));
      link_in_graph(from_frag_id, to_frag_id);
      continue;
    }

    // The `CanonicalPair` stuff doesn't guarantee that all pairs will work
    // happily together. This is especially likely to come up with structures,
    // which can be forward-declared inside other things, or inside function
    // prototypes. We deal with the case of structures here.
    mx::Fragment to_frag = index.fragment(to_frag_id).value();
    for (mx::Decl tld : to_frag.top_level_declarations()) {

      for (mx::Decl tld_redecl : tld.redeclarations()) {
        if (tld.is_definition() != tld_redecl.is_definition()) {
          continue;
        }

        mx::Fragment alt_to_frag = mx::Fragment::containing(tld_redecl);
        mx::PackedFragmentId alt_to_frag_id = alt_to_frag.id();
        if (dag.contains(alt_to_frag_id)) {
          link_in_graph(from_frag_id, alt_to_frag_id);
        }
      }
    }
  }

  // Sort the fragments in reverse order of their depth.
  std::vector<mx::PackedFragmentId> frags;
  for (auto &frag_dag : dag) {
    mx::PackedFragmentId frag_id = frag_dag.first;
    DAG &d = frag_dag.second;
    frags.push_back(frag_id);
    (void) d.Depth(dag);
  }

  std::sort(frags.begin(), frags.end(),
            [&dag] (mx::PackedFragmentId a, mx::PackedFragmentId b) {
              return dag[b].depth < dag[a].depth;
            });

  std::unordered_set<mx::RawEntityId> needs_rename;
  std::unordered_map<std::string, mx::RawEntityId> canon_id;

  // Figure out what top-level entities need to be renamed.
  for (mx::PackedFragmentId frag_id : frags) {
    for (mx::Decl tld : index.fragment(frag_id)->top_level_declarations()) {
      tld = tld.canonical_declaration();
      std::optional<mx::NamedDecl> nd = mx::NamedDecl::from(tld);
      if (!nd) {
        continue;
      }

      std::string_view name_view = nd->name();
      if (name_view.empty()) {
        continue;
      }

      std::string name(name_view.data(), name_view.size());
      mx::RawEntityId eid = nd->id().Pack();
      mx::RawEntityId stored_eid = canon_id.emplace(name, eid).first->second;
      if (eid != stored_eid) {
        std::cout << "// Renaming " << name_view << '\n';
        needs_rename.insert(eid);
        needs_rename.insert(stored_eid);
      }
    }
  }

  // Make sure our original entity isn't subject to renaming.
  for (mx::Decl redecl : entity->redeclarations()) {
    needs_rename.erase(redecl.id().Pack());
  }

  std::cerr
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  auto i = 0u;
  for (mx::PackedFragmentId frag_id : frags) {
    assert(dag.contains(frag_id));

    DAG &d = dag[frag_id];
    std::cerr << "f" << d.frag_id << " [label=<<TABLE><TR><TD>";
    frag_label(std::cerr, frag_id);
    std::cerr
        << "</TD></TR><TR><TD>depth=" << d.depth << " order="
        << i << "</TD></TR></TABLE>>];\n";
    for (mx::PackedFragmentId to_frag_id : d.children) {
      std::cerr << "f" << frag_id << " -> f" << to_frag_id;
      if (d.depth >= dag[to_frag_id].depth) {
//        std::cerr << "\n!!! " << frag_id.Pack() << ' ';
//        frag_label(frag_id);
//        std::cerr << "  <-> " << to_frag_id.Pack() << ' ';
//        frag_label(to_frag_id);
//        std::cerr << '\n';
//        assert(false);
        std::cerr << " [color=red]";  // Probable circular dependency.
      }
      std::cerr << ";\n";
    }
    ++i;
  }

  std::cerr << "}\n";

  // The `CanonicalPair` stuff doesn't guarantee that all pairs will work
  // happily together. This is especially likely to come up with structures,
  // which can be forward-declared inside other things, or inside function
  // prototypes. We deal with the case of structures here.
  for (mx::PackedFragmentId frag_id : frags) {
    for (mx::Decl tld : index.fragment(frag_id)->top_level_declarations()) {
      if (auto tag = mx::TagDecl::from(tld); tag && !tag->name().empty()) {
        switch (tag->tag_kind()) {
          case mx::TagTypeKind::CLASS: std::cout << "class "; break;
          case mx::TagTypeKind::STRUCT: std::cout << "struct "; break;
          case mx::TagTypeKind::UNION: std::cout << "union "; break;
          default: continue;
        }

        std::cout << tag->name();
        if (mx::RawEntityId eid = tld.canonical_declaration().id().Pack();
            needs_rename.contains(eid)) {
          std::cout << '_' << eid;
        }
        std::cout << ";\n";
      }
    }
  }

  auto print_frag = [&] (const mx::Fragment &frag) {
    auto sep = "";

    // Nifty info to tie the outputs back to the index.
    std::cout << "// Fragment ID: " << frag.id() << '\n';
    if (auto file = mx::File::containing(frag)) {
      std::cout << "// File ID: " << file->id() << '\n';
      for (std::filesystem::path fp : file->paths()) {
        std::cout << "// File path: " << fp.generic_string() << '\n';
      }
    }
    if (auto loc = frag.file_tokens().front().location(location_cache)) {
      std::cout << "// Line: " << loc->first << '\n'
                << "// Column: " << loc->second << '\n';
    }

    // Print out the space-separated parsed tokens. Some tokens might need to
    // be renamed; this is done by appending a `_<canonical id>` to them.
    for (mx::Token tok : frag.parsed_tokens()) {
      std::cout << sep << tok.data();
      sep = " ";

      // Do renaming of the entities that might conflict.
      if (tok.kind() != mx::TokenKind::IDENTIFIER) {
        continue;
      }

      mx::VariantEntity ent = tok.related_entity();
      if (!std::holds_alternative<mx::Decl>(ent)) {
        continue;
      }

      mx::Decl decl = std::get<mx::Decl>(ent).canonical_declaration();
      mx::RawEntityId eid = decl.id().Pack();
      if (needs_rename.contains(eid)) {
        std::cout << '_' << eid;
      }
    }

    std::cout << "\n\n";
  };

  for (mx::PackedFragmentId frag_id : frags) {

    mx::Fragment frag = index.entity(frag_id).value();
    print_frag(frag);

    // It could be that through aliased attributes we have another name for
    // this function, and we might need to expose this name.
    for (mx::Decl tld : frag.top_level_declarations()) {
      auto func = mx::FunctionDecl::from(tld);
      if (!func || func->is_definition()) {
        continue;
      }

      for (mx::FunctionDecl redecl : func->redeclarations()) {
        if (redecl.name() == func->name() || redecl.is_definition()) {
          continue;
        }

        auto redecl_frag = mx::Fragment::containing(redecl);
        if (!dag.contains(redecl_frag.id())) {
          print_frag(redecl_frag);
        }
      }
    }
  }

  return EXIT_SUCCESS;
}

