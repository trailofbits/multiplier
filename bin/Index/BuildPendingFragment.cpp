// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PendingFragment.h"

#include <clang/AST/Decl.h>

#include "EntityMapper.h"
#include "PASTA.h"
#include "References.h"
#include "TypeMapper.h"
#include "Util.h"
#include <glog/logging.h>

#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ingored "-Wunused-function"

namespace indexer {
namespace {

// Collects all entities that will be stored into the fragment in
// `PendingFragment`. This generally needs to follow all references in the
// same way that the serializer does, hence the use of `Visitor.inc.h`. It is
// also the case that types and pseudos are stored differently than decls and
// statements. Decls/stmts are lexically bound to a fragment, i.e. the decls/
// stmts in a fragment lexically "belong" to the range of code covered by that
// fragment. However, types and pseudos are different. Pseudos are generally
// "owned" by one decl, or one-or-more types. All types referenced by decls/
// stmts/types/pseudos in a fragment are also stored in the fragment, even if it
// ends up being redundant across fragments.
class FragmentBuilder final {
 public:
  EntityMapper &em;
  PendingFragment &fragment;

  // We defer the processing of types as late as possible, as deduplicating
  // types requires us to look up entity IDs in the entity mapper, and so we
  // want to see as many declarations first (thus giving them IDs) prior to
  // us processing types.
  std::vector<pasta::Type> pending_types;

  inline explicit FragmentBuilder(EntityMapper &em_,
                                  PendingFragment &fragment_)
      : em(em_),
        fragment(fragment_) {}

#ifndef __CDT_PARSER__
#define MX_BEGIN_VISIT_DECL(name) void Visit ## name (const pasta::name &);
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_ATTR MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_MACRO MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>
#endif

  void Accept(const pasta::Decl &entity);
  void Accept(const pasta::Stmt &entity);
  void Accept(const pasta::Type &entity);
  void Accept(const pasta::Attr &entity);
  void Accept(const pasta::Macro &entity);

  void MaybeVisitNext(std::optional<pasta::MacroToken>) {}
  void MaybeVisitNext(std::optional<pasta::FileToken>) {}
  void MaybeVisitNext(std::optional<pasta::Token>) {}
  void MaybeVisitNext(const pasta::Token &) {}

  void MaybeVisitNext(const pasta::Decl &entity) {
    if (fragment.TryAdd(entity)) {
      AddParentDeclContexts(entity);
    }
  }

  void MaybeVisitNext(const pasta::Stmt &entity) {
    fragment.TryAdd(entity);
  }

  void MaybeVisitNext(const pasta::Type &entity) {
    pending_types.emplace_back(entity);
  }

  void MaybeVisitNext(const pasta::Attr &entity) {
    fragment.TryAdd(entity);
  }

  void MaybeVisitNext(const pasta::Macro &) {}

  void MaybeVisitNext(const pasta::File &) {}

  void MaybeVisitNext(const pasta::TemplateArgument &pseudo) {
    fragment.TryAdd(pseudo);
  }

  void MaybeVisitNext(const pasta::CXXBaseSpecifier &pseudo) {
    fragment.TryAdd(pseudo);
  }

  void MaybeVisitNext(const pasta::TemplateParameterList &pseudo) {
    fragment.TryAdd(pseudo);
  }

  void MaybeVisitNext(const pasta::Designator &pseudo) {
    fragment.TryAdd(pseudo);
  }

  void MaybeVisitNext(const pasta::CXXCtorInitializer &pseudo) {
    if (fragment.TryAdd(pseudo)) {
      if (auto init = pseudo.Initializer()) {
        MaybeVisitNext(init.value());
      }
    }
  }

  void MaybeVisitDeclContext(const pasta::DeclContext &dc) {
    if (auto dc_decl = pasta::Decl::From(dc)) {
      if (IsSerializableDecl(dc_decl.value())) {
        MaybeVisitNext(dc_decl.value());
      }
    }
  }

  void AddParentDeclContexts(const pasta::Decl &decl) {
    if (auto sdc = decl.DeclarationContext()) {
      MaybeVisitDeclContext(sdc.value());
    }

    if (auto ldc = decl.LexicalDeclarationContext()) {
      MaybeVisitDeclContext(ldc.value());
    }
  }

  template <typename T>
  void Accept(const T &pseudo) {
    MaybeVisitNext(pseudo);
  }
};

#ifndef __CDT_PARSER__
#define MX_VISIT_BASE(derived_type, base_type) \
    Visit ## base_type(entity);

#define MX_VISIT_ENTITY(cls, api_method, storage, apply, method, entity_type, \
                        get_storage_list) \
    MaybeVisitNext(apply(entity, method));


#define MX_VISIT_ENTITY_LIST(cls, api_method, storage, apply, method, \
                             entity_type, get_storage_list) \
    for (auto sub_entity : apply(entity, method)) { \
      MaybeVisitNext(sub_entity); \
    }

#define MX_VISIT_OPTIONAL_ENTITY(cls, api_method, storage, apply, method, \
                                 entity_type, ...) \
    if (auto sub_entity = apply(entity, method); sub_entity.has_value()) { \
      MaybeVisitNext(sub_entity.value()); \
    }

#define MX_VISIT_OPTIONAL_ENTITY_LIST(cls, api_method, storage, apply, method, \
                                      entity_type, get_storage_list) \
    if (auto sub_entities = apply(entity, method); sub_entities.has_value()) { \
      for (const auto &sub_entity : sub_entities.value()) { \
        MaybeVisitNext(sub_entity); \
      } \
    }

#define MX_VISIT_PSEUDO MX_VISIT_ENTITY
#define MX_VISIT_PSEUDO_LIST MX_VISIT_ENTITY_LIST
#define MX_VISIT_OPTIONAL_PSEUDO MX_VISIT_OPTIONAL_ENTITY
#define MX_VISIT_OPTIONAL_PSEUDO_LIST MX_VISIT_OPTIONAL_ENTITY_LIST

#define MX_BEGIN_VISIT_DECL(name) \
    void FragmentBuilder::Visit ## name(const pasta::name &entity) { \
      (void) entity;

#define MX_END_VISIT_DECL(name) }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_ATTR MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL

// NOTE(pag): Macro visitors are never reached, so trick the compiler into
//            dead code elimination.
#define MX_BEGIN_VISIT_MACRO(name) MX_BEGIN_VISIT_DECL(name) if (1) return;
#define MX_END_VISIT_MACRO MX_END_VISIT_DECL

#include <multiplier/Visitor.inc.h>
#endif

void FragmentBuilder::Accept(const pasta::Decl &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: { \
      Visit ## decl ## Decl( \
         reinterpret_cast<const pasta::decl ## Decl &>(entity)); \
      return; \
    }

    PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_DECL
  }
}

void FragmentBuilder::Accept(const pasta::Stmt &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: { \
      Visit ## stmt( \
         reinterpret_cast<const pasta::stmt &>(entity)); \
      break; \
    }

    PASTA_FOR_EACH_STMT_IMPL(MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_STMT
  }
}

void FragmentBuilder::Accept(const pasta::Type &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_TYPE(type) \
    case pasta::TypeKind::k ## type: { \
      Visit ## type ## Type( \
         reinterpret_cast<const pasta::type ## Type &>(entity)); \
      break; \
    }

    PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE,
                             PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_TYPE
  }
}

void FragmentBuilder::Accept(const pasta::Attr &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_ATTR(type) \
    case pasta::AttrKind::k ## type: { \
      Visit ## type ## Attr( \
         reinterpret_cast<const pasta::type ## Attr &>(entity)); \
      break; \
    }

    PASTA_FOR_EACH_ATTR_IMPL(MX_VISIT_ATTR,
                             PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_ATTR
  }
}

// NOTE(pag): We visit macros in `Persist.cpp`, as it has to also correlate
//            macro nodes with `TokenTree` nodes.
void FragmentBuilder::Accept(const pasta::Macro &) {}

}  // namespace

// Possibly add an entity to this fragment. We have two entity ID maps:
// 1) The `EntityMapper::entity_ids` map, which we use to decide if globally we
// should ignore this entity without formulating an ID, and; 2) the
// `EntityMapper::token_tree_ids`, which is a fragment-local entity id tracker.
template <typename Entity, typename MakeId>
bool PendingFragment::DoTryAdd(const Entity &entity, EntityIdMap &entity_ids,
                               MakeId make_id) {
  auto locator = RawEntity(entity);
  if (entity_ids.contains(locator)) {
    return false;
  }

  if (ShouldHideFromIndexer(entity))  {
    return false;
  }

  auto &entity_list = EntityListFor(entity);
  auto id = make_id(static_cast<mx::EntityOffset>(entity_list.size()));
  entity_ids.emplace(locator, id);
  entity_list.emplace_back(entity);  // New entity found.
  return true;
}

bool PendingFragment::TryAdd(const pasta::Decl &entity) {
  auto &entity_or_token_map =
      ShouldInternalizeDeclContextIntoFragment(entity) ?
      em.token_tree_ids : em.entity_ids;

  return DoTryAdd(
      entity,
      entity_or_token_map,
      [&, this] (mx::EntityOffset offset) {
        mx::DeclId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        id.kind = mx::FromPasta(entity.Kind());
        id.is_definition = IsDefinition(entity);
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::Stmt &entity) {
  return DoTryAdd(
      entity,
      em.generate_source_ir ? em.entity_ids : em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::StmtId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        id.kind = mx::FromPasta(entity.Kind());
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::TemplateArgument &entity) {
  return DoTryAdd(
      entity,
      em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::TemplateArgumentId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::TemplateParameterList &entity) {
  return DoTryAdd(
      entity,
      em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::TemplateParameterListId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::CXXBaseSpecifier &entity) {
  return DoTryAdd(
      entity,
      em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::CXXBaseSpecifierId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::Designator &entity) {
  return DoTryAdd(
      entity,
      em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::DesignatorId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::CXXCtorInitializer &entity) {
  return DoTryAdd(
      entity,
      em.token_tree_ids,
      [&, this] (mx::EntityOffset offset) {
        mx::CXXCtorInitializerId id;
        id.fragment_id = fragment_index;
        id.offset = offset;
        return id;
      });
}

bool PendingFragment::TryAdd(const pasta::Attr &entity) {

  // Attributes can be inherited, and can be pushed by pragmas, e.g.
  //
  //    #pragma attribute push(__attribute__((....)), apply_to = (...))
  //
  // This complicates things, hence why we try to deduplicate inherited
  // attributes.
  //
  // NOTE(pag): We can't rely on `attr.IsInherited()`, as Clang doesn't
  //            properly set this attribute for attributes inherited from
  //            pragmas.
  EntityIdMap &entity_ids =
      em.generate_source_ir ? em.entity_ids : em.token_tree_ids;

  auto locator = RawEntity(entity);
  if (entity_ids.contains(locator)) {
    return false;
  }

  auto &entity_list = EntityListFor(entity);
  mx::AttrId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(entity_list.size());
  id.kind = mx::FromPasta(entity.Kind());

  if (auto tok = entity.Token(); auto raw_tok = RawEntity(tok)) {
    // If we have something like:
    //
    //      struct CGPoint { int x; int y; };
    //      typedef struct __attribute__((objc_boxable)) CGPoint CGPoint;
    //
    // Then the attribute will apply to the structure definition rather than
    // the declaration embedded in the declarator of the `typedef`. In these
    // cases, we opt to defer our attribute merging logic to later.
    const uint64_t tok_index = tok.Index();
    if (first_parsed_token_index > tok_index ||
        last_parsed_token_index < tok_index) {
      return false;
    }

    // NOTE(kumarak): Deduplicating inherited attributes becomes complex with
    //                templates and its specialization. The attributes for
    //                templates and all its specialization will have same
    //                RawToken but used in different context and we want to
    //                assign different entity ids to them.
    //                e.g:
    //                        template <typename T>
    //                        struct AlignedStorage {
    //                          __attribute__((aligned(alignof(T)))) char data[sizeof(T)];
    //                        };
    //
    //                        AlignedStorage<int> aligned_int_storage;
    //                        AlignedStorage<double> aligned_double_storage;
    //
    //                In the example above, the AlignedAttr for both the specialization will
    //                be different entity and we don't want to de-duplicate them.
    //
    //                The updated approach creates a map of raw token with the fragment
    //                parsed token location and identify if the attribute is used in the
    //                specialization or inherited to another fragment.

    auto it = em.attr_ids.find(locator);
    if (it != em.attr_ids.end()) {
      entity_ids.emplace(locator, it->second);
      return false;  // We've seen this.
    }

    auto loc_it = em.attr_token_locs.find(raw_tok);
    if (loc_it != em.attr_token_locs.end()) {
      auto begin_index = loc_it->second.first;
      auto end_index = loc_it->second.second;

      if (first_parsed_token_index != begin_index ||
          last_parsed_token_index != end_index) {

        // The fragment is not specialization. Get the entity ids
        // for the raw token and add it to the entity_ids map
        auto it = em.attr_token_ids.find(raw_tok);
        if (it != em.attr_token_ids.end()) {
          entity_ids.emplace(locator, it->second);
          return false;  // We've seen this.
        }
      }
    } else {
      // If the raw_tok is not in `attr_token_locs`, we have not
      // seen it. Go ahead and add the fragment parse token indices
      // to the map and also update the attr_token_ids map;
      em.attr_token_locs.emplace(raw_tok,
        std::pair(first_parsed_token_index, last_parsed_token_index));
      em.attr_token_ids.emplace(raw_tok, id);
    }

    em.attr_ids.emplace(locator, id);

  // NOTE(pag): This is pretty ugly, but we need to label the attributes
  //            when we're processing all fragments, as the attributes may
  //            be shared/inherited. However, the attributes are fragment-local,
  //            and so `EntityMapper::ResetForFragment` wipes out our memory
  //            of what attributes we've already found. Thus, we need to double
  //            check things. Mostly this just happens with implicit attributes
  //            on builtin types, e.g. `TypeVisibilityAttr` on
  //            `__NSConstantString_tag`.
  } else {
    mx::EntityOffset i = 0u;
    for (const pasta::Attr &prev_entity : entity_list) {
      if (prev_entity == entity) {
        id.offset = i;
        entity_ids.emplace(locator, id);
        return false;
      }
      ++i;
    }
  }

  entity_ids.emplace(locator, id);
  entity_list.emplace_back(entity);  // New attribute found.
  return true;
}

bool PendingFragment::TryAdd(pasta::Type entity) {
  if (!em.tm.AddEntityId(*this, &entity)) {
    return false;
  }

  // Types are global but we still need to store them in pending fragment
  // to build it during the iterative process and discover the references
  // of other decls and statements by the type and logically belongs to the
  // fragment. It would otherwise be hard to do "outside" pending fragment
  // build process.
  //
  // For example, AdjustedTypes are a big example, where you might have a
  // function with a body like:
  //      `int x;`
  //      `int y[sizeof(x)];`
  //
  // The adjusted type here references a sized array type that references
  // `sizeof(x)`, and we should capture `sizeof(x)` and the reference to x
  // in this in the fragment, as it can't be properly captured outside / after
  // the fragment is serialized.

  types_to_serialize.emplace_back(entity);
  return true;
}

// Build the fragment. This fills out the decls/stmts/types to serialize.
void BuildPendingFragment(const pasta::AST &ast, PendingFragment &pf) {
  EntityMapper &em = pf.em;

  std::unordered_map<mx::DeclKind, size_t, HashKind<mx::DeclKind>> prev_num_decls;
  std::unordered_map<mx::StmtKind, size_t, HashKind<mx::StmtKind>> prev_num_stmts;
  std::unordered_map<mx::AttrKind, size_t, HashKind<mx::AttrKind>> prev_num_attrs;
  size_t prev_num_types = 0ul;
  size_t prev_num_designators = 0ul;
  size_t prev_num_template_args = 0ul;
  size_t prev_num_template_params = 0ul;
  size_t prev_num_cxx_base_specifiers = 0ul;
  size_t prev_num_cxx_ctor_initializers = 0ul;

  FragmentBuilder builder(em, pf);

  std::vector<pasta::TokenContext> contexts;

  // Make sure to collect everything reachable from token contexts.
  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    for (pasta::TokenContext context : TokenContexts(tok)) {
      
      // The contexts go from the tokens back into the AST. When we pretty
      // print things like class templates, we end up with a situation where
      // we print the bodies of nested templates / other things that go in
      // floating fragments. So, if we come across something that should go in
      // such a fragment, then exclude it from here.
      auto eid = mx::EntityId(em.EntityId(context.Data())).Unpack();
      if (std::holds_alternative<mx::InvalidId>(eid)) {
        // Do nothing.

      } else if (std::holds_alternative<mx::DeclId>(eid) &&
                 std::get<mx::DeclId>(eid).fragment_id != pf.fragment_index) {
        contexts.clear();
      
      } else if (std::holds_alternative<mx::StmtId>(eid) &&
                 std::get<mx::StmtId>(eid).fragment_id != pf.fragment_index) {
        contexts.clear();

      } else if (std::holds_alternative<mx::AttrId>(eid) &&
                 std::get<mx::AttrId>(eid).fragment_id != pf.fragment_index) {
        contexts.clear();
      }

      contexts.emplace_back(std::move(context));
    }

    for (const auto &context : contexts) {
      if (auto decl = pasta::Decl::From(context)) {
        builder.MaybeVisitNext(decl.value());

      } else if (auto stmt = pasta::Stmt::From(context)) {
        builder.MaybeVisitNext(stmt.value());

      } else if (auto type = pasta::Type::From(context)) {
        builder.MaybeVisitNext(type.value());

      } else if (auto attr = pasta::Attr::From(context)) {
        builder.MaybeVisitNext(attr.value());

      } else if (auto designator = pasta::Designator::From(context)) {
        builder.MaybeVisitNext(designator.value());

      } else if (auto arg = pasta::TemplateArgument::From(context)) {
        builder.MaybeVisitNext(arg.value());
      
      } else if (auto params = pasta::TemplateParameterList::From(context)) {
        builder.MaybeVisitNext(params.value());
      
      } else if (auto spec = pasta::CXXBaseSpecifier::From(context)) {
        builder.MaybeVisitNext(spec.value());
      
      } else if (auto init = pasta::CXXCtorInitializer::From(context)) {
        builder.MaybeVisitNext(init.value());
      }
    }

    contexts.clear();
  }

  // Get the decl context of the top-level declarations and add them
  // to token_tree_ids. This will help internally serialize them in
  // the fragments.
  for (auto &tld : pf.top_level_decls) {
    builder.AddParentDeclContexts(tld);
  }

  auto do_on_list = [&] (auto &list, size_t &prev_size, bool &changed) {
    const size_t size = list.size();
    for (size_t i = prev_size; i < size; ++i) {
      changed = true;
      auto entity = list[i];  // Copy, not by ref, just in cast `list` resizes.
      builder.Accept(entity);
    }
    prev_size = size;
  };

  auto do_on_map = [&] (auto &map, auto &prev_sizes, bool &changed) {
    for (auto &[id, list] : map) {
      do_on_list(list, prev_sizes[id], changed);
    }
  };

  for (auto on_new_types = 2u; on_new_types > 0; ) {
    on_new_types--;

    for (auto changed = true; changed; ) {
      changed = false;

      do_on_map(pf.decls_to_serialize, prev_num_decls, changed);
      do_on_map(pf.stmts_to_serialize, prev_num_stmts, changed);
      do_on_map(pf.attrs_to_serialize, prev_num_attrs, changed);
      do_on_list(pf.types_to_serialize, prev_num_types, changed);
      
      // NOTE(pag): Keep these up-to-date with `PendingFragment`.
      do_on_list(pf.template_arguments_to_serialize, prev_num_template_args,
                 changed);
      do_on_list(pf.template_parameter_lists_to_serialize,
                 prev_num_template_params, changed);
      do_on_list(pf.designators_to_serialize, prev_num_designators, changed);
      do_on_list(pf.cxx_base_specifiers_to_serialize,
                 prev_num_cxx_base_specifiers, changed);
      do_on_list(pf.cxx_ctor_initializers_to_serialize,
                 prev_num_cxx_ctor_initializers, changed);
    }

    // We defer the processing of types as late as possible, as deduplicating
    // types requires us to look up entity IDs in the entity mapper, and so we
    // want to see as many declarations first (thus giving them IDs) prior to
    // us processing types.
    for (const pasta::Type &entity : builder.pending_types) {
      if (pf.TryAdd(entity)) {
        on_new_types = 2;
      }
    }

    builder.pending_types.clear();
  }
}

}  // namespace indexer

#pragma GCC diagnostic pop
