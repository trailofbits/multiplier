// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <capnp/common.h>
#include <capnp/message.h>
#include <deque>

#include <multiplier/AST.capnp.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Database.h>

#ifndef NDEBUG
# include <unordered_set>
#endif

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

#undef MAKE_DISPATCHER

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

  // Used to check if an entity ID is new.
  std::unordered_set<mx::RawEntityId> seen_eids;
  auto is_new_eid = [&seen_eids] (mx::RawEntityId eid) {
    return seen_eids.emplace(eid).second;
  };

  // Serialize a list of entities.
  auto serialize_list = [&] (auto list_builder, const auto &list,
                             auto check_id, unsigned kind) {
    mx::EntityOffset i = 0u;
    for (const auto &entity : list) {
      mx::RawEntityId eid = em.EntityId(entity);
      db.AsyncIndexFragmentSpecificEntity(eid);

#ifndef NDEBUG
      check_id(eid, kind, i);
#endif

      DispatchSerializeEntity(pf, pf.em, list_builder[i++], entity);
    }
  };

  // Serialize a map of entity lists. The index of the map is the integral
  // representation of the entity kind.
  auto serialize_map = [&] (auto map_builder, const auto &map, auto check_id) {
    for (const auto &[kind, entities] : map) {
      serialize_list(
          map_builder.init(kind, static_cast<unsigned>(entities.size())),
          entities,
          check_id,
          kind);
    }
  };

  em.tm.EnterReadOnly();

  serialize_map(
      fb.initDeclarations(SerializationListSize(pf.decls_to_serialize)),
      pf.decls_to_serialize,
      [&] (mx::RawEntityId eid, unsigned kind, mx::EntityOffset i) {
        auto vid = std::get<mx::DeclId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(unsigned(vid.kind) == kind);
        assert(is_new_eid(eid));
      });

  serialize_map(
      fb.initStatements(SerializationListSize(pf.stmts_to_serialize)),
      pf.stmts_to_serialize,
      [&] (mx::RawEntityId eid, unsigned kind, mx::EntityOffset i) {
        auto vid = std::get<mx::StmtId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(unsigned(vid.kind) == kind);
        assert(is_new_eid(eid));
      });

  serialize_map(
      fb.initAttributes(SerializationListSize(pf.attrs_to_serialize)),
      pf.attrs_to_serialize,
      [&] (mx::RawEntityId eid, unsigned kind, mx::EntityOffset i) {
        auto vid = std::get<mx::AttrId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(unsigned(vid.kind) == kind);
        assert(is_new_eid(eid));
      });

  serialize_list(
      fb.initDesignators(
          static_cast<unsigned>(pf.designators_to_serialize.size())),
      pf.designators_to_serialize,
      [&] (mx::RawEntityId eid, unsigned, mx::EntityOffset i) {
        auto vid = std::get<mx::DesignatorId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(is_new_eid(eid));
      },
      0u);

  serialize_list(
      fb.initCXXBaseSpecifiers(
          static_cast<unsigned>(pf.cxx_base_specifiers_to_serialize.size())),
      pf.cxx_base_specifiers_to_serialize,
      [&] (mx::RawEntityId eid, unsigned, mx::EntityOffset i) {
        auto vid = std::get<mx::CXXBaseSpecifierId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(is_new_eid(eid));
      },
      0u);

  serialize_list(
      fb.initTemplateArguments(
          static_cast<unsigned>(pf.template_arguments_to_serialize.size())),
      pf.template_arguments_to_serialize,
      [&] (mx::RawEntityId eid, unsigned, mx::EntityOffset i) {
        auto vid = std::get<mx::TemplateArgumentId>(mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(is_new_eid(eid));
      },
      0u);

  serialize_list(
      fb.initTemplateParameterLists(
          static_cast<unsigned>(pf.template_parameter_lists_to_serialize.size())),
      pf.template_parameter_lists_to_serialize,
      [&] (mx::RawEntityId eid, unsigned, mx::EntityOffset i) {
        auto vid = std::get<mx::TemplateParameterListId>(
            mx::EntityId(eid).Unpack());
        assert(vid.fragment_id == pf.fragment_index);
        assert(vid.offset == i);
        assert(is_new_eid(eid));
      },
      0u);

  em.tm.ExitReadOnly();
}

void SerializeType(const pasta::Type &entity,
                   const PendingFragment &pf,
                   mx::RawEntityId type_id,
                   mx::ast::Type::Builder builder) {
  const EntityMapper &em = pf.em;
  mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
  auto vid = std::get<mx::TypeId>(mx::EntityId(eid).Unpack());
  assert(vid.type_id == type_id);
#endif

  em.tm.EnterReadOnly();
  DispatchSerializeEntity(pf, em, builder, entity);
  em.tm.ExitReadOnly();

  (void) eid;
  (void) type_id;
}

}  // namespace indexer
