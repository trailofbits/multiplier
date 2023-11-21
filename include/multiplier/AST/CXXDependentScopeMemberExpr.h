// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class CXXDependentScopeMemberExpr;
class Decl;
class Expr;
class NamedDecl;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDependentScopeMemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDependentScopeMemberExpr> in(const Index &index);
  static gap::generator<CXXDependentScopeMemberExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDependentScopeMemberExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXDependentScopeMemberExpr> in(const Fragment &frag);
  static gap::generator<CXXDependentScopeMemberExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR;
  }

  static gap::generator<CXXDependentScopeMemberExpr> containing(const Decl &decl);
  static gap::generator<CXXDependentScopeMemberExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDependentScopeMemberExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDependentScopeMemberExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDependentScopeMemberExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXDependentScopeMemberExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXDependentScopeMemberExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXDependentScopeMemberExpr> from(const Reference &r);
  static std::optional<CXXDependentScopeMemberExpr> from(const VariantEntity &e);
  static std::optional<CXXDependentScopeMemberExpr> from(const TokenContext &t);

  std::optional<Expr> base(void) const;
  Type base_type(void) const;
  std::optional<NamedDecl> first_qualifier_found_in_scope(void) const;
  Token l_angle_token(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

static_assert(sizeof(CXXDependentScopeMemberExpr) == sizeof(Expr));

#endif
} // namespace mx
