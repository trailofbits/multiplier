// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PendingFragment.h"

#include "EntityMapper.h"
#include "PASTA.h"
#include "TypeMapper.h"
#include "Util.h"

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
    fragment.Add(entity);
  }

  void MaybeVisitNext(const pasta::Stmt &entity) {
    fragment.Add(entity);
  }

  void MaybeVisitNext(const pasta::Type &entity) {
    pending_types.emplace_back(entity);
  }

  void MaybeVisitNext(const pasta::Attr &entity) {
    fragment.Add(entity);
  }

  void MaybeVisitNext(const pasta::Macro &) {}

  void MaybeVisitNext(const pasta::File &) {}

  void MaybeVisitNext(const pasta::TemplateArgument &pseudo) {
    fragment.Add(pseudo);
  }

  void MaybeVisitNext(const pasta::CXXBaseSpecifier &pseudo) {
    fragment.Add(pseudo);
  }

  void MaybeVisitNext(const pasta::TemplateParameterList &pseudo) {
    fragment.Add(pseudo);
  }

  void MaybeVisitNext(const pasta::Designator &pseudo) {
    fragment.Add(pseudo);
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
// The `read_entity_ids` map, which we use to decide if globally we should
// ignore this entity without formulating an ID. If our entity isn't in
// `read_entity_ids`, then we opportunistically create an id and try to add
// it to `write_entity_ids`.

bool PendingFragment::Add(const pasta::Decl &entity) {

  EntityIdMap &entity_ids = em.entity_ids;

  auto locator = entity.RawDecl();
  if (entity_ids.contains(locator)) {
    return false;
  }

  if (ShouldHideFromIndexer(entity))  {
    return false;
  }

  auto kind = entity.Kind();
  mx::DeclId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(decls_to_serialize.size());
  id.kind = mx::FromPasta(kind);
  id.is_definition = IsDefinition(entity);

  entity_ids.emplace(locator, id);
  decls_to_serialize.emplace_back(entity);  // New decl found.
  return true;
}

bool PendingFragment::Add(const pasta::Stmt &entity) {

  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawStmt();
  if (entity_ids.contains(locator)) {
    return false;
  }

  if (auto expr = pasta::Expr::From(entity)) {
    if (expr->ContainsErrors()) {
      return false;
    }
  }

  auto kind = entity.Kind();
  mx::StmtId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(stmts_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  entity_ids.emplace(locator, id);
  stmts_to_serialize.emplace_back(entity);  // New stmt found.
  return true;
}

bool PendingFragment::Add(pasta::Type entity) {
  if (!em.tm.AddEntityId(em, &entity)) {
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

bool PendingFragment::Add(const pasta::Attr &entity) {

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
  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawAttr();
  if (entity_ids.contains(locator)) {
    return false;
  }

  auto kind = entity.Kind();
  mx::AttrId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(attrs_to_serialize.size());
  id.kind = mx::FromPasta(kind);

  if (auto tok = entity.Token(); auto raw_tok = tok.RawToken()) {
    auto it = em.attr_ids.find(raw_tok);
    if (it != em.attr_ids.end()) {
      entity_ids.emplace(locator, it->second);
      return false;  // We've seen this.
    }

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

    em.attr_ids.emplace(raw_tok, id);

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
    for (const pasta::Attr &prev_entity : attrs_to_serialize) {
      if (prev_entity == entity) {
        id.offset = i;
        entity_ids.emplace(locator, id);
        return false;
      }
      ++i;
    }
  }

  entity_ids.emplace(locator, id);
  attrs_to_serialize.emplace_back(entity);  // New attribute found.
  return true;
}

bool PendingFragment::Add(const pasta::TemplateArgument &entity) {

  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawTemplateArgument();
  if (entity_ids.contains(locator)) {
    return false;
  }

  mx::TemplateArgumentId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(
      template_arguments_to_serialize.size());

  entity_ids.emplace(locator, id);
  template_arguments_to_serialize.emplace_back(entity);
  return true;
}

bool PendingFragment::Add(const pasta::TemplateParameterList &entity) {

  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawTemplateParameterList();
  if (entity_ids.contains(locator)) {
    return false;
  }

  mx::TemplateParameterListId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(
      template_parameter_lists_to_serialize.size());

  entity_ids.emplace(locator, id);
  template_parameter_lists_to_serialize.emplace_back(entity);
  return true;
}

bool PendingFragment::Add(const pasta::CXXBaseSpecifier &entity) {

  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawCXXBaseSpecifier();
  if (entity_ids.contains(locator)) {
    return false;
  }

  mx::CXXBaseSpecifierId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(
      cxx_base_specifiers_to_serialize.size());

  entity_ids.emplace(locator, id);
  cxx_base_specifiers_to_serialize.emplace_back(entity);
  return true;
}

bool PendingFragment::Add(const pasta::Designator &entity) {

  EntityIdMap &entity_ids = em.token_tree_ids;

  auto locator = entity.RawDesignator();
  if (entity_ids.contains(locator)) {
    return false;
  }

  mx::DesignatorId id;
  id.fragment_id = fragment_index;
  id.offset = static_cast<mx::EntityOffset>(designators_to_serialize.size());

  entity_ids.emplace(locator, id);
  designators_to_serialize.emplace_back(entity);
  return true;
}

// Build the fragment. This fills out the decls/stmts/types to serialize.
void BuildPendingFragment(PendingFragment &pf) {
  EntityMapper &em = pf.em;

  size_t prev_num_decls = 0ul;
  size_t prev_num_stmts = 0ul;
  size_t prev_num_types = 0ul;
  size_t prev_num_attrs = 0ul;
  size_t prev_num_designators = 0ul;
  size_t prev_num_template_args = 0ul;
  size_t prev_num_template_params = 0ul;
  size_t prev_num_cxx_base_specifiers = 0ul;

  FragmentBuilder builder(em, pf);

  // Make sure to collect everything reachable from token contexts.
  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    for (auto context = tok.Context(); context;
         context = context->Parent()) {
      if (auto decl = pasta::Decl::From(*context)) {
        builder.MaybeVisitNext(*decl);

      } else if (auto stmt = pasta::Stmt::From(*context)) {
        builder.MaybeVisitNext(*stmt);

      } else if (auto type = pasta::Type::From(*context)) {
        builder.MaybeVisitNext(*type);

      } else if (auto attr = pasta::Attr::From(*context)) {
        builder.MaybeVisitNext(*attr);

      } else if (auto designator = pasta::Designator::From(*context)) {
        builder.MaybeVisitNext(*designator);

      } else if (auto arg = pasta::TemplateArgument::From(*context)) {
        builder.MaybeVisitNext(*arg);
      
      } else if (auto params = pasta::TemplateParameterList::From(*context)) {
        builder.MaybeVisitNext(*params);
      
      } else if (auto spec = pasta::CXXBaseSpecifier::From(*context)) {
        builder.MaybeVisitNext(*spec);
      }
    }
  }

  for (auto has_new_types = true; has_new_types; ) {
    has_new_types = false;

    for (auto changed = true; changed; ) {
      changed = false;

      size_t num_decls = pf.decls_to_serialize.size();
      size_t num_stmts = pf.stmts_to_serialize.size();
      size_t num_types = pf.types_to_serialize.size();
      size_t num_attrs = pf.attrs_to_serialize.size();
      size_t num_designators = pf.designators_to_serialize.size();
      size_t num_template_args = pf.template_arguments_to_serialize.size();
      size_t num_template_params =
          pf.template_parameter_lists_to_serialize.size();
      size_t num_cxx_base_specifiers =
          pf.cxx_base_specifiers_to_serialize.size();

      for (size_t i = prev_num_decls; i < num_decls; ++i) {
        changed = true;
        pasta::Decl entity = pf.decls_to_serialize[i];
        builder.Accept(entity);
      }

      for (size_t i = prev_num_stmts; i < num_stmts; ++i) {
        changed = true;
        pasta::Stmt entity = pf.stmts_to_serialize[i];
        builder.Accept(entity);
      }

      for (size_t i = prev_num_types; i < num_types; ++i) {
        changed = true;
        pasta::Type entity = pf.types_to_serialize[i];
        builder.Accept(entity);
      }

      for (size_t i = prev_num_attrs; i < num_attrs; ++i) {
        changed = true;
        pasta::Attr entity = pf.attrs_to_serialize[i];
        builder.Accept(entity);
      }

      for (size_t i = prev_num_designators; i < num_designators; ++i) {
        changed = true;
        pasta::Designator entity = pf.designators_to_serialize[i];
        builder.VisitDesignator(entity);
      }

      for (size_t i = prev_num_template_args; i < num_template_args; ++i) {
        changed = true;
        pasta::TemplateArgument entity = pf.template_arguments_to_serialize[i];
        builder.VisitTemplateArgument(entity);
      }

      for (size_t i = prev_num_template_params; i < num_template_params; ++i) {
        changed = true;
        pasta::TemplateParameterList entity =
            pf.template_parameter_lists_to_serialize[i];
        builder.VisitTemplateParameterList(entity);
      }

      for (size_t i = prev_num_cxx_base_specifiers;
           i < num_cxx_base_specifiers; ++i) {
        changed = true;
        pasta::CXXBaseSpecifier entity = pf.cxx_base_specifiers_to_serialize[i];
        builder.VisitCXXBaseSpecifier(entity);
      }

      prev_num_decls = num_decls;
      prev_num_stmts = num_stmts;
      prev_num_types = num_types;
      prev_num_attrs = num_attrs;
      prev_num_designators = num_designators;
      prev_num_template_args = num_template_args;
      prev_num_template_params = num_template_params;
      prev_num_cxx_base_specifiers = num_cxx_base_specifiers;
    }

    // We defer the processing of types as late as possible, as deduplicating
    // types requires us to look up entity IDs in the entity mapper, and so we
    // want to see as many declarations first (thus giving them IDs) prior to
    // us processing types.
    for (const pasta::Type &entity : builder.pending_types) {
      if (pf.Add(entity)) {
        has_new_types = true;
      }
    }

    builder.pending_types.clear();
  }
}

}  // namespace indexer

#pragma GCC diagnostic pop
