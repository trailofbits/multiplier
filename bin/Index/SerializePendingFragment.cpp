// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <capnp/common.h>
#include <capnp/message.h>

#include "EntityMapper.h"
#include "PendingFragment.h"
#include "Serialize.h"

namespace indexer {
namespace {

static void DispatchSerializeDecl(EntityMapper &em,
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

static void DispatchSerializeStmt(EntityMapper &em,
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

static void DispatchSerializeType(EntityMapper &em,
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

static void DispatchSerializeAttr(EntityMapper &em,
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

void DispatchSerializeMacro(EntityMapper &em,
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
                              MX_VISIT_DIRECTIVE, PASTA_IGNORE_ABSTRACT)
#undef MX_VISIT_ATTR
    default:
      assert(false);
      break;
  }
}

void PendingFragment::Serialize(EntityMapper &em,
                                mx::rpc::Fragment::Builder &b) {

  auto i = 0u;
  auto decl_builder = b.initDeclarations(
      static_cast<unsigned>(decls_to_serialize.size()));
  for (const pasta::Decl &entity : decls_to_serialize) {
    DispatchSerializeDecl(em, decl_builder[i++], entity);
  }

  i = 0u;
  auto stmt_builder = b.initStatements(
      static_cast<unsigned>(stmts_to_serialize.size()));
  for (const pasta::Stmt &entity : stmts_to_serialize) {
    DispatchSerializeStmt(em, stmt_builder[i++], entity);
  }

  i = 0u;
  auto type_builder = b.initTypes(
      static_cast<unsigned>(types_to_serialize.size()));
  for (const pasta::Type &entity : types_to_serialize) {
    DispatchSerializeType(em, type_builder[i++], entity);
  }

  i = 0u;
  auto attr_builder = b.initAttributes(
      static_cast<unsigned>(attrs_to_serialize.size()));
  for (const pasta::Attr &entity : attrs_to_serialize) {
    DispatchSerializeAttr(em, attr_builder[i++], entity);
  }

  i = 0u;
  auto pseudo_builder = b.initOthers(
      static_cast<unsigned>(pseudos_to_serialize.size()));
  for (const Pseudo &pseudo : pseudos_to_serialize) {
    if (std::holds_alternative<pasta::TemplateArgument>(pseudo)) {
      SerializeTemplateArgument(
          em, pseudo_builder[i++], std::get<pasta::TemplateArgument>(pseudo));
    } else if (std::holds_alternative<pasta::CXXBaseSpecifier>(pseudo)) {
      SerializeCXXBaseSpecifier(
          em, pseudo_builder[i++], std::get<pasta::CXXBaseSpecifier>(pseudo));
    } else if (std::holds_alternative<pasta::TemplateParameterList>(pseudo)) {
      SerializeTemplateParameterList(
          em, pseudo_builder[i++],
          std::get<pasta::TemplateParameterList>(pseudo));
    } else if (std::holds_alternative<pasta::Designator>(pseudo)) {
      SerializeDesignator(
          em, pseudo_builder[i++],
          std::get<pasta::Designator>(pseudo));
    } else {
      assert(false);
      ++i;
    }
  }
}

}  // namespace indexer
