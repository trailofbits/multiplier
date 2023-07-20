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
class CXXPseudoDestructorExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXPseudoDestructorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXPseudoDestructorExpr> in(const Index &index);
  static gap::generator<CXXPseudoDestructorExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXPseudoDestructorExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXPseudoDestructorExpr> in(const Fragment &frag);
  static gap::generator<CXXPseudoDestructorExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
  }

  static gap::generator<CXXPseudoDestructorExpr> containing(const Decl &decl);
  static gap::generator<CXXPseudoDestructorExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXPseudoDestructorExpr> containing(const Stmt &stmt);
  static gap::generator<CXXPseudoDestructorExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXPseudoDestructorExpr> from(const Stmt &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXPseudoDestructorExpr> from(const Reference &r);
  static std::optional<CXXPseudoDestructorExpr> from(const TokenContext &t);

  Expr base(void) const;
  Token colon_colon_token(void) const;
  Type destroyed_type(void) const;
  Token destroyed_type_token(void) const;
  Token operator_token(void) const;
  std::optional<Type> scope_type(void) const;
  Token tilde_token(void) const;
  bool has_qualifier(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(CXXPseudoDestructorExpr) == sizeof(Expr));

#endif
} // namespace mx
