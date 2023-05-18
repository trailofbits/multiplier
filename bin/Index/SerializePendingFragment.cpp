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

static void DispatchSerializeDecl(const EntityMapper &em,
                                  mx::ast::Decl::Builder builder,
                                  const pasta::Decl &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: \
      Serialize ## decl ## Decl( \
         em, builder, reinterpret_cast<const pasta::decl ## Decl &>(entity), \
         nullptr); \
      break;

    PASTA_FOR_EACH_DECL_IMPL(MX_VISIT_DECL, PASTA_IGNORE_ABSTRACT)

#undef MX_VISIT_DECL
    default:
      assert(false);
      return;
  }
}

static void DispatchSerializeStmt(const EntityMapper &em,
                                  mx::ast::Stmt::Builder builder,
                                  const pasta::Stmt &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_STMT(stmt) \
    case pasta::StmtKind::k ## stmt: \
      Serialize ## stmt( \
          em, builder, reinterpret_cast<const pasta::stmt &>(entity), \
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

static void DispatchSerializeType(const EntityMapper &em,
                                  mx::ast::Type::Builder builder,
                                  const pasta::Type &entity) {

  // Second pass actually does the real serialization.
  switch (entity.Kind()) {
#define MX_VISIT_TYPE(type) \
  case pasta::TypeKind::k ## type: \
    Serialize ## type ## Type ( \
        em, builder, reinterpret_cast<const pasta::type ## Type &>(entity), \
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

static void DispatchSerializeAttr(const EntityMapper &em,
                                  mx::ast::Attr::Builder builder,
                                  const pasta::Attr &entity) {

  // Second pass actually does the real serialization.
  switch (entity.Kind()) {
#define MX_VISIT_ATTR(type) \
  case pasta::AttrKind::k ## type: \
    Serialize ## type ## Attr ( \
        em, builder, reinterpret_cast<const pasta::type ## Attr &>(entity), \
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

}  // namespace

// Dispatch to the right macro serializer.
void DispatchSerializeMacro(const EntityMapper &em,
                            mx::ast::Macro::Builder builder,
                            const pasta::Macro &entity,
                            const TokenTree *tt) {

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
        em, builder, reinterpret_cast<const pasta::Macro ## type &>(entity), \
        tt); \

#define MX_VISIT_DIRECTIVE(type) \
  } else if (kind == mx::FromPasta(pasta::MacroKind::k ## type ## Directive)) { \
    Serialize ## type ## MacroDirective( \
        em, builder, \
        reinterpret_cast<const pasta::type ## MacroDirective &>(entity), tt); \

    PASTA_FOR_EACH_MACRO_IMPL(MX_VISIT_MACRO, PASTA_IGNORE_ABSTRACT,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_DIRECTIVE
  }
}

// Serialize all entities into the Cap'n Proto version of the fragment.
void SerializePendingFragment(mx::DatabaseWriter &database,
                              const PendingFragment &pf,
                              const EntityMapper &em) {
#ifndef NDEBUG
  std::unordered_set<mx::RawEntityId> seen_eids;
  auto is_new_eid = [&seen_eids] (mx::RawEntityId eid) {
    auto old_size = seen_eids.size();
    seen_eids.insert(eid);
    return old_size != seen_eids.size();
  };
#endif

  for (const pasta::Decl &entity : pf.decls_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::DeclId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::Decl> storage;
    em.tm.EnterReadOnly();
    DispatchSerializeDecl(em, storage.builder, entity);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  for (const pasta::Stmt &entity : pf.stmts_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::StmtId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::Stmt> storage;
    em.tm.EnterReadOnly();
    DispatchSerializeStmt(em, storage.builder, entity);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  // Note: We don't serialize types to the same fragments. They are
  //       serialized as different fragment in the database. This
  //       will avoid duplication of the types in each fragments.

  for (const pasta::Attr &entity : pf.attrs_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::AttrId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::Attr> storage;
    em.tm.EnterReadOnly();
    DispatchSerializeAttr(em, storage.builder, entity);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  for (const pasta::Designator &entity : pf.designators_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::DesignatorId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::Designator> storage;
    em.tm.EnterReadOnly();
    SerializeDesignator(em, storage.builder, entity, nullptr);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  for (const pasta::CXXBaseSpecifier &entity :
           pf.cxx_base_specifiers_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::CXXBaseSpecifierId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::CXXBaseSpecifier> storage;
    em.tm.EnterReadOnly();
    SerializeCXXBaseSpecifier(em, storage.builder, entity, nullptr);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  for (const pasta::TemplateArgument &entity :
           pf.template_arguments_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::TemplateArgumentId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::TemplateArgument> storage;
    em.tm.EnterReadOnly();
    SerializeTemplateArgument(em, storage.builder, entity, nullptr);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }

  for (const pasta::TemplateParameterList &entity :
           pf.template_parameter_lists_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::TemplateParameterListId>(
        mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(is_new_eid(eid));
#endif

    EntityBuilder<mx::ast::TemplateParameterList> storage;
    em.tm.EnterReadOnly();
    SerializeTemplateParameterList(em, storage.builder, entity, nullptr);
    em.tm.ExitReadOnly();
    database.AddAsync(
        mx::EntityRecord{eid, GetSerializedData(storage.message)});
  }
}

void SerializeType(mx::DatabaseWriter &database, const pasta::Type &entity,
                   const EntityMapper &em, mx::RawEntityId fragment_index) {
  mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
  auto vid = std::get<mx::TypeId>(mx::EntityId(eid).Unpack());
  assert(vid.fragment_id == fragment_index);
#endif

  EntityBuilder<mx::ast::Type> storage;
  em.tm.EnterReadOnly();
  DispatchSerializeType(em, storage.builder, entity);
  em.tm.ExitReadOnly();
  database.AddAsync(
      mx::EntityRecord{eid, GetSerializedData(storage.message)});
  (void)fragment_index;
}

}  // namespace indexer
