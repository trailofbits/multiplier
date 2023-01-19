// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <capnp/common.h>
#include <capnp/message.h>

#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/Database.h>

#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Serialize.h"

namespace indexer {
namespace {

static void DispatchSerializeDecl(const EntityMapper &em,
                                  mx::ast::Decl::Builder builder,
                                  const pasta::Decl &entity) {
  switch (entity.Kind()) {
#define MX_VISIT_DECL(decl) \
    case pasta::DeclKind::k ## decl: \
      Serialize ## decl ## Decl( \
         em, \
         builder, \
         reinterpret_cast<const pasta::decl ## Decl &>(entity)); \
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
          em, \
          builder, \
          reinterpret_cast<const pasta::stmt &>(entity)); \
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
        em, builder, \
        reinterpret_cast<const pasta::type ## Type &>(entity)); \
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
        em, builder, \
        reinterpret_cast<const pasta::type ## Attr &>(entity)); \
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
                            const pasta::Macro &entity, const TokenTree *tt) {

  // Second pass actually does the real serialization.
  switch (entity.Kind()) {
#define MX_VISIT_MACRO(type) \
  case pasta::MacroKind::k ## type: \
    SerializeMacro ## type ( \
        em, builder, \
        reinterpret_cast<const pasta::Macro ## type &>(entity), tt); \
    break;

#define MX_VISIT_DIRECTIVE(type) \
  case pasta::MacroKind::k ## type ## Directive: \
    Serialize ## type ## MacroDirective( \
        em, builder, \
        reinterpret_cast<const pasta::type ## MacroDirective &>(entity), tt); \
    break;

    PASTA_FOR_EACH_MACRO_IMPL(MX_VISIT_MACRO, PASTA_IGNORE_ABSTRACT,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              MX_VISIT_DIRECTIVE, MX_VISIT_DIRECTIVE,
                              PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_ATTR
    default:
      assert(false);
      break;
  }
}

// Serialize all entities into the Cap'n Proto version of the fragment.
void SerializePendingFragment(mx::DatabaseWriter &database,
                              const PendingFragment &pf,
                              const EntityMapper &em,
                              mx::rpc::Fragment::Builder &b,
                              std::deque<EntityBuilder<mx::ast::Decl>> &decls,
                              std::deque<EntityBuilder<mx::ast::Stmt>> &stmts,
                              std::deque<EntityBuilder<mx::ast::Type>> &types,
                              std::deque<EntityBuilder<mx::ast::Attr>> &attrs,
                              std::deque<EntityBuilder<mx::ast::Pseudo>> &pseudos) {

  auto i = 0u;
  for (const pasta::Decl &entity : pf.decls_to_serialize) {
    auto &storage = decls.emplace_back();
    DispatchSerializeDecl(em, storage.builder, entity);
    database.AddAsync(
        mx::DeclEntityRecord{
          pf.fragment_id, i++, GetPackedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Stmt &entity : pf.stmts_to_serialize) {
    auto &storage = stmts.emplace_back();
    DispatchSerializeStmt(em, storage.builder, entity);
    database.AddAsync(
        mx::StmtEntityRecord{
          pf.fragment_id, i++, GetPackedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Type &entity : pf.types_to_serialize) {
    auto &storage = types.emplace_back();
    DispatchSerializeType(em, storage.builder, entity);
    database.AddAsync(
        mx::TypeEntityRecord{
          pf.fragment_id, i++, GetPackedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Attr &entity : pf.attrs_to_serialize) {
    auto &storage = attrs.emplace_back();
    DispatchSerializeAttr(em, storage.builder, entity);
    database.AddAsync(
        mx::AttrEntityRecord{
          pf.fragment_id, i++, GetPackedData(storage.message)});
  }

  i = 0u;
  for (const Pseudo &pseudo : pf.pseudos_to_serialize) {
    auto &storage = pseudos.emplace_back();
    if (std::holds_alternative<pasta::TemplateArgument>(pseudo)) {
      SerializeTemplateArgument(
          em, storage.builder, std::get<pasta::TemplateArgument>(pseudo));
    } else if (std::holds_alternative<pasta::CXXBaseSpecifier>(pseudo)) {
      SerializeCXXBaseSpecifier(
          em, storage.builder, std::get<pasta::CXXBaseSpecifier>(pseudo));
    } else if (std::holds_alternative<pasta::TemplateParameterList>(pseudo)) {
      SerializeTemplateParameterList(
          em, storage.builder,
          std::get<pasta::TemplateParameterList>(pseudo));
    } else if (std::holds_alternative<pasta::Designator>(pseudo)) {
      SerializeDesignator(
          em, storage.builder,
          std::get<pasta::Designator>(pseudo));
    } else {
      assert(false);
    }
    database.AddAsync(
        mx::PseudoEntityRecord{
          pf.fragment_id, i++, GetPackedData(storage.message)});
  }
}

}  // namespace indexer
