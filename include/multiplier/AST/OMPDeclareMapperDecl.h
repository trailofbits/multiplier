// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPDeclarativeDirectiveValueDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class NamedDecl;
class OMPDeclarativeDirectiveValueDecl;
class OMPDeclareMapperDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveValueDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclareMapperDecl> in(const Index &index);
  static gap::generator<OMPDeclareMapperDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclareMapperDecl> by_id(const Index &, EntityId);
  static gap::generator<OMPDeclareMapperDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclareMapperDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_DECLARE_MAPPER;
  }

  static gap::generator<OMPDeclareMapperDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclareMapperDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclareMapperDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclareMapperDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPDeclareMapperDecl canonical_declaration(void) const;
  std::optional<OMPDeclareMapperDecl> definition(void) const;
  gap::generator<OMPDeclareMapperDecl> redeclarations(void) const &;
  static std::optional<OMPDeclareMapperDecl> from_base(const Decl &parent);
  inline static std::optional<OMPDeclareMapperDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDeclareMapperDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPDeclareMapperDecl> from(const Reference &r);
  static std::optional<OMPDeclareMapperDecl> from(const VariantEntity &e);
  static std::optional<OMPDeclareMapperDecl> from(const TokenContext &t);

  Expr mapper_variable_reference(void) const;
  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(OMPDeclareMapperDecl) == sizeof(OMPDeclarativeDirectiveValueDecl));

#endif
} // namespace mx
