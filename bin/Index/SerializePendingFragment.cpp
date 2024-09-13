// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <capnp/common.h>
#include <capnp/message.h>
#include <deque>
#include <multiplier/AST.capnp.h>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Database.h>
#include <unordered_set>

#include "EntityMapper.h"
#include "PASTA.h"
#include "PendingFragment.h"
#include "Serialize.h"
#include "TypeMapper.h"

namespace indexer {
namespace {

static void DispatchSerializeEntity(const PendingFragment &pf,
                                    const EntityMapper &em,
                                    mx::ast::Decl::Builder builder,
                                    const pasta::Decl &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: \
      Serialize ## decl ## Decl( \
         pf, em, builder, \
         reinterpret_cast<const pasta::decl ## Decl &>(entity), \
         nullptr); \
      break;

    PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_DECL
    default:
      assert(false);
      return;
  }
}

static void DispatchSerializeEntity(const PendingFragment &pf,
                                    const EntityMapper &em,
                                    mx::ast::Stmt::Builder builder,
                                    const pasta::Stmt &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: \
      Serialize ## stmt( \
          pf, em, builder, reinterpret_cast<const pasta::stmt &>(entity), \
          nullptr); \
      break;

    PASTA_FOR_EACH_STMT_IMPL(MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             MX_VISIT_STMT,
                             PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_STMT
    default:
      assert(false);
      break;
  }
}

static void DispatchSerializeEntity(const PendingFragment &pf,
                                    const EntityMapper &em,
                                    mx::ast::Type::Builder builder,
                                    const pasta::Type &entity) {

  // Second pass actually does the real serialization.
  switch (entity.Kind()) {
#define MX_VISIT_TYPE(type) \
  case pasta::TypeKind::k ## type: \
    Serialize ## type ## Type ( \
        pf, em, builder, \
        reinterpret_cast<const pasta::type ## Type &>(entity), \
        nullptr); \
    break;

    PASTA_FOR_EACH_TYPE_IMPL(MX_VISIT_TYPE,
                             PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_TYPE
    default:
      assert(false);
      break;
  }
}

static void DispatchSerializeEntity(const PendingFragment &pf,
                                    const EntityMapper &em,
                                    mx::ast::Attr::Builder builder,
                                    const pasta::Attr &entity) {

  // Second pass actually does the real serialization.
  switch (entity.Kind()) {
#define MX_VISIT_ATTR(type) \
  case pasta::AttrKind::k ## type: \
    Serialize ## type ## Attr ( \
        pf, em, builder, \
        reinterpret_cast<const pasta::type ## Attr &>(entity), \
        nullptr); \
    break;

    PASTA_FOR_EACH_ATTR_IMPL(MX_VISIT_ATTR,
                             PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_ATTR
    default:
      assert(false);
      break;
  }
}

#define MAKE_DISPATCHER(pseudo_kind) \
    inline static void DispatchSerializeEntity( \
        const PendingFragment &pf, const EntityMapper &em, \
        mx::ast::pseudo_kind::Builder builder, \
        const pasta::pseudo_kind &entity) { \
      Serialize ## pseudo_kind(pf, em, std::move(builder), entity, nullptr); \
    }

MAKE_DISPATCHER(TemplateArgument)
MAKE_DISPATCHER(TemplateParameterList)
MAKE_DISPATCHER(CXXBaseSpecifier)
MAKE_DISPATCHER(Designator)
MAKE_DISPATCHER(CXXCtorInitializer)

#undef MAKE_DISPATCHER

template <typename IdType, typename Kind>
static void CheckFragOffsetKind(const PendingFragment &pf, mx::RawEntityId eid,
                                Kind kind, mx::EntityOffset i) {
  auto vid = mx::EntityId(eid).Extract<IdType>();
  assert(vid.has_value());
  assert(vid->fragment_id == pf.fragment_index);
  assert(vid->offset == i);
  assert(vid->kind == kind);
  (void) vid;
  (void) pf;
  (void) kind;
  (void) i;
}

template <typename IdType>
static void CheckFragOffset(const PendingFragment &pf, mx::RawEntityId eid,
                            unsigned /* dummy kind */, mx::EntityOffset i) {
  auto vid = mx::EntityId(eid).Extract<IdType>();
  assert(vid.has_value());
  assert(vid->fragment_id == pf.fragment_index);
  assert(vid->offset == i);
  (void) vid;
  (void) pf;
  (void) i;
}

}  // namespace

// Dispatch to the right macro serializer.
void DispatchSerializeMacro(const PendingFragment &pf,
                            mx::ast::Macro::Builder builder,
                            const pasta::Macro &entity,
                            const TokenTree *tt) {

  const EntityMapper &em = pf.em;

  // NOTE(pag): If we have `tt`, then trust it, and not `entity`. Due to evil
  //            sketchiness, `entity`, might be an invalid pointer.
  mx::MacroKind kind = mx::MacroKind::SUBSTITUTION;
  if (tt) {
    kind = tt->Kind();
  } else {
    kind = mx::FromPasta(entity.Kind());
  }

  // Second pass actually does the real serialization.
  if (false) {
#define MX_VISIT_MACRO(type) \
  } else if (kind == mx::FromPasta(pasta::MacroKind::k ## type)) { \
    SerializeMacro ## type ( \
        pf, em, builder, \
        reinterpret_cast<const pasta::Macro ## type &>(entity), \
        tt); \

#define MX_VISIT_DIRECTIVE(type) \
  } else if (kind == mx::FromPasta(pasta::MacroKind::k ## type ## Directive)) { \
    Serialize ## type ## MacroDirective( \
        pf, em, builder, \
        reinterpret_cast<const pasta::type ## MacroDirective &>(entity), tt); \

    PASTA_FOR_EACH_MACRO_IMPL(MX_VISIT_MACRO, PASTA_IGNORE_ABSTRACT,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_DIRECTIVE
  }
}

// Serialize all entities into the Cap'n Proto version of the fragment.
//
// NOTE: We don't serialize types to the same fragments. They are
//       serialized as different fragment in the database. This
//       will avoid duplication of the types in each fragments.
void SerializePendingFragment(mx::rpc::Fragment::Builder &fb,
                              mx::DatabaseWriter &db,
                              const PendingFragment &pf) {
  const EntityMapper &em = pf.em;

#ifndef NDEBUG
  // Used to check if an entity ID is new.
  std::unordered_set<mx::RawEntityId> seen_eids;
  auto is_new_eid = [&seen_eids] (mx::RawEntityId eid) {
    return seen_eids.emplace(eid).second;
  };
#endif

  // Serialize a list of entities.
  auto serialize_list = [&] (auto list_builder, const auto &list,
                             auto check_id, auto kind) {
    mx::EntityOffset i = 0u;
    for (const auto &entity : list) {
      mx::RawEntityId eid = em.EntityId(entity);
      db.AsyncIndexFragmentSpecificEntity(eid);

#ifndef NDEBUG
      assert(is_new_eid(eid));
      check_id(pf, eid, kind, i);
#endif
      (void) kind;

      DispatchSerializeEntity(pf, pf.em, list_builder[i++], entity);
    }

    (void) check_id;
  };

  // Serialize a map of entity lists. The index of the map is the integral
  // representation of the entity kind.
  //
  // TODO(pag): Do we need to initialize the intermediate lists for kinds
  //            that we don't have?
  auto serialize_map = [&] (auto map_builder, const auto &map, auto check_id) {
    for (const auto &[kind, entities] : map) {
      serialize_list(
          map_builder.init(static_cast<unsigned>(kind), NumEntities(entities)),
          entities,
          check_id,
          kind);
    }
  };

  em.tm.EnterReadOnly();

  serialize_map(
      fb.initDecls(SerializationListSize(pf.decls_to_serialize)),
      pf.decls_to_serialize,
      CheckFragOffsetKind<mx::DeclId, mx::DeclKind>);

  serialize_map(
      fb.initStmts(SerializationListSize(pf.stmts_to_serialize)),
      pf.stmts_to_serialize,
      CheckFragOffsetKind<mx::StmtId, mx::StmtKind>);

  serialize_map(
      fb.initAttrs(SerializationListSize(pf.attrs_to_serialize)),
      pf.attrs_to_serialize,
      CheckFragOffsetKind<mx::AttrId, mx::AttrKind>);

  // NOTE(pag): Keep these up-to-date with `PendingFragment`.

  serialize_list(
      fb.initDesignators(NumEntities(pf.designators_to_serialize)),
      pf.designators_to_serialize,
      CheckFragOffset<mx::DesignatorId>,
      0u);

  serialize_list(
      fb.initCXXBaseSpecifiers(
          NumEntities(pf.cxx_base_specifiers_to_serialize)),
      pf.cxx_base_specifiers_to_serialize,
      CheckFragOffset<mx::CXXBaseSpecifierId>,
      0u);

  serialize_list(
      fb.initTemplateArguments(
          NumEntities(pf.template_arguments_to_serialize)),
      pf.template_arguments_to_serialize,
      CheckFragOffset<mx::TemplateArgumentId>,
      0u);

  serialize_list(
      fb.initTemplateParameterLists(
          NumEntities(pf.template_parameter_lists_to_serialize)),
      pf.template_parameter_lists_to_serialize,
      CheckFragOffset<mx::TemplateParameterListId>,
      0u);

  serialize_list(
      fb.initCXXCtorInitializers(
          NumEntities(pf.cxx_ctor_initializers_to_serialize)),
      pf.cxx_ctor_initializers_to_serialize,
      CheckFragOffset<mx::CXXCtorInitializerId>,
      0u);

  // Issue #480: Index macros. Persist.cpp manages the serialization of the
  //             macros separately, but we still need to index them here so that
  //             we can identify uses of macros across the codebase.
  for (const auto &[kind, entities] : pf.macros_to_serialize) {
    for (const auto &maybe_tt : entities) {
      if (maybe_tt) {
        mx::RawEntityId eid = em.EntityId(maybe_tt.value());
        db.AsyncIndexFragmentSpecificEntity(eid);
      } 
    }
  }

  em.tm.ExitReadOnly();
}

void SerializeType(const pasta::Type &entity,
                   const PendingFragment &pf,
                   mx::RawEntityId type_index,
                   mx::ast::Type::Builder builder) {
  const EntityMapper &em = pf.em;
  auto eid = em.SpecificEntityId<mx::TypeId>(entity);
  assert(eid.has_value());
  assert(eid->type_id == type_index);

  (void) eid;
  (void) type_index;

  em.tm.EnterReadOnly();
  DispatchSerializeEntity(pf, em, builder, entity);
  em.tm.ExitReadOnly();
}

}  // namespace indexer
