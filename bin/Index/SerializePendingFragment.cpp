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

static void DispatchSerializeDecl(const PendingFragment &pf,
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

static void DispatchSerializeStmt(const PendingFragment &pf,
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

static void DispatchSerializeType(const PendingFragment &pf,
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

static void DispatchSerializeAttr(const PendingFragment &pf,
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
                              const PendingFragment &pf) {
  const EntityMapper &em = pf.em;

#ifndef NDEBUG
  std::unordered_set<mx::RawEntityId> seen_eids;
  auto is_new_eid = [&seen_eids] (mx::RawEntityId eid) {
    return seen_eids.emplace(eid).second;
  };
#endif

  em.tm.EnterReadOnly();
  mx::EntityOffset i = 0u;

  auto decls_list =
      fb.initDeclarations(SerializationListSize(pf.decls_to_serialize));
  for (const auto &[kind, entities] : pf.decls_to_serialize) {
    auto kl = decls_list.init(kind, static_cast<unsigned>(entities.size()));

    i = 0u;
    for (const pasta::Decl &entity : entities) {
      mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
      auto vid = std::get<mx::DeclId>(mx::EntityId(eid).Unpack());
      assert(vid.fragment_id == pf.fragment_index);
      assert(vid.offset == i);
      assert(unsigned(vid.kind) == kind);
      assert(is_new_eid(eid));
#endif

      DispatchSerializeDecl(pf, pf.em, kl[i], entity);
      ++i;
    }
  }

  auto stmts_list =
      fb.initStatements(SerializationListSize(pf.stmts_to_serialize));
  for (const auto &[kind, entities] : pf.stmts_to_serialize) {
    auto kl = stmts_list.init(kind, static_cast<unsigned>(entities.size()));

    i = 0u;
    for (const pasta::Stmt &entity : entities) {
      mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
      auto vid = std::get<mx::StmtId>(mx::EntityId(eid).Unpack());
      assert(vid.fragment_id == pf.fragment_index);
      assert(vid.offset == i);
      assert(unsigned(vid.kind) == kind);
      assert(is_new_eid(eid));
#endif

      DispatchSerializeStmt(pf, pf.em, kl[i], entity);
      ++i;
    }
  }

  auto attrs_list =
      fb.initAttributes(SerializationListSize(pf.attrs_to_serialize));
  for (const auto &[kind, entities] : pf.attrs_to_serialize) {
    auto kl = attrs_list.init(kind, static_cast<unsigned>(entities.size()));

    i = 0u;
    for (const pasta::Attr &entity : entities) {
      mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
      auto vid = std::get<mx::AttrId>(mx::EntityId(eid).Unpack());
      assert(vid.fragment_id == pf.fragment_index);
      assert(vid.offset == i);
      assert(unsigned(vid.kind) == kind);
      assert(is_new_eid(eid));
#endif

      DispatchSerializeAttr(pf, pf.em, kl[i], entity);
      ++i;
    }
  }

  auto designators_list = fb.initDesignators(
      static_cast<unsigned>(pf.designators_to_serialize.size()));
  i = 0u;
  for (const pasta::Designator &entity : pf.designators_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::DesignatorId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(vid.offset == i);
    assert(is_new_eid(eid));
#endif

    SerializeDesignator(pf, pf.em, designators_list[i], entity, nullptr);
    ++i;
  }

  auto cxx_base_specifiers_list = fb.initCXXBaseSpecifiers(
      static_cast<unsigned>(pf.cxx_base_specifiers_to_serialize.size()));
  i = 0u;
  for (const pasta::CXXBaseSpecifier &entity :
           pf.cxx_base_specifiers_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::CXXBaseSpecifierId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(vid.offset == i);
    assert(is_new_eid(eid));
#endif

    SerializeCXXBaseSpecifier(pf, pf.em, cxx_base_specifiers_list[i], entity,
                              nullptr);
    ++i;
  }

  auto template_arguments_list = fb.initTemplateArguments(
      static_cast<unsigned>(pf.template_arguments_to_serialize.size()));
  i = 0u;
  for (const pasta::TemplateArgument &entity :
           pf.template_arguments_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::TemplateArgumentId>(mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(vid.offset == i);
    assert(is_new_eid(eid));
#endif

    SerializeTemplateArgument(pf, pf.em, template_arguments_list[i], entity,
                              nullptr);
    ++i;
  }

  auto template_parameter_lists_list = fb.initTemplateParameterLists(
      static_cast<unsigned>(pf.template_parameter_lists_to_serialize.size()));
  i = 0u;
  for (const pasta::TemplateParameterList &entity :
           pf.template_parameter_lists_to_serialize) {
    mx::RawEntityId eid = em.EntityId(entity);

#ifndef NDEBUG
    auto vid = std::get<mx::TemplateParameterListId>(
        mx::EntityId(eid).Unpack());
    assert(vid.fragment_id == pf.fragment_index);
    assert(vid.offset == i);
    assert(is_new_eid(eid));
#endif

    SerializeTemplateParameterList(pf, pf.em, template_parameter_lists_list[i],
                                   entity, nullptr);
    ++i;
  }

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
  DispatchSerializeType(pf, em, builder, entity);
  em.tm.ExitReadOnly();

  (void) eid;
  (void) type_id;
}

}  // namespace indexer
