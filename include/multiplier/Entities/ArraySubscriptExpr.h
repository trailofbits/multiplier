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
class ArraySubscriptExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArraySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ArraySubscriptExpr> in(const Index &index);
  static gap::generator<ArraySubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArraySubscriptExpr> by_id(const Index &, EntityId);
  static gap::generator<ArraySubscriptExpr> in(const Fragment &frag);
  static gap::generator<ArraySubscriptExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_SUBSCRIPT_EXPR;
  }

  static gap::generator<ArraySubscriptExpr> containing(const Decl &decl);
  static gap::generator<ArraySubscriptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ArraySubscriptExpr> containing(const Stmt &stmt);
  static gap::generator<ArraySubscriptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArraySubscriptExpr> from(const Stmt &parent);

  inline static std::optional<ArraySubscriptExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArraySubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArraySubscriptExpr> from(const Reference &r);
  static std::optional<ArraySubscriptExpr> from(const TokenContext &t);

  Expr base(void) const;
  Expr index(void) const;
  Expr lhs(void) const;
  Token r_bracket_token(void) const;
  Expr rhs(void) const;
};

static_assert(sizeof(ArraySubscriptExpr) == sizeof(Expr));

#endif
} // namespace mx
