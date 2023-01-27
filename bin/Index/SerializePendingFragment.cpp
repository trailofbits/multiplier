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
#include "PASTA.h"

#include <deque>

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

// Identify all unique entity IDs used by this fragment, and map them to the
// fragment ID in the data store.
extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Decl> &entity);

extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Stmt> &entity);

extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Type> &entity);

extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Attr> &entity);

extern void LinkExternalUsesInFragment(
    mx::DatabaseWriter &database, const PendingFragment &pf,
    EntityBuilder<mx::ast::Pseudo> &entity);

// Serialize all entities into the Cap'n Proto version of the fragment.
void SerializePendingFragment(mx::DatabaseWriter &database,
                              const PendingFragment &pf,
                              const EntityMapper &em) {

  auto i = 0u;
  for (const pasta::Decl &entity : pf.decls_to_serialize) {
    EntityBuilder<mx::ast::Decl> storage;
    DispatchSerializeDecl(em, storage.builder, entity);
    LinkExternalUsesInFragment(database, pf, storage);
    mx::DeclarationId id;
    id.fragment_id = pf.fragment_index;
    id.offset = i++;
    id.kind = mx::FromPasta(entity.Kind());
    id.is_definition = IsDefinition(entity);
    database.AddAsync(
        mx::DeclEntityRecord{
          id, GetSerializedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Stmt &entity : pf.stmts_to_serialize) {
    EntityBuilder<mx::ast::Stmt> storage;
    DispatchSerializeStmt(em, storage.builder, entity);
    LinkExternalUsesInFragment(database, pf, storage);
    mx::StatementId id;
    id.fragment_id = pf.fragment_index;
    id.offset = i++;
    id.kind = mx::FromPasta(entity.Kind());
    database.AddAsync(
        mx::StmtEntityRecord{
          id, GetSerializedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Type &entity : pf.types_to_serialize) {
    EntityBuilder<mx::ast::Type> storage;
    DispatchSerializeType(em, storage.builder, entity);
    LinkExternalUsesInFragment(database, pf, storage);
    mx::TypeId id;
    id.fragment_id = pf.fragment_index;
    id.offset = i++;
    id.kind = mx::FromPasta(entity.Kind());
    database.AddAsync(
        mx::TypeEntityRecord{
          id, GetSerializedData(storage.message)});
  }

  i = 0u;
  for (const pasta::Attr &entity : pf.attrs_to_serialize) {
    EntityBuilder<mx::ast::Attr> storage;
    DispatchSerializeAttr(em, storage.builder, entity);
    LinkExternalUsesInFragment(database, pf, storage);
    mx::AttributeId id;
    id.fragment_id = pf.fragment_id.Unpack().fragment_id;
    id.offset = i++;
    id.kind = mx::FromPasta(entity.Kind());
    database.AddAsync(
        mx::AttrEntityRecord{
          id, GetSerializedData(storage.message)});
  }

  i = 0u;
  for (const Pseudo &pseudo : pf.pseudos_to_serialize) {
    EntityBuilder<mx::ast::Pseudo> storage;
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

    LinkExternalUsesInFragment(database, pf, storage);
    mx::DesignatorId id;
    id.fragment_id = pf.fragment_index;
    id.offset = i++;
    database.AddAsync(
        mx::PseudoEntityRecord{
          id, GetSerializedData(storage.message)});
  }
}

}  // namespace indexer
