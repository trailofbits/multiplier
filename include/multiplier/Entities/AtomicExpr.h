// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AtomicExprAtomicOp.h"
#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class AtomicExpr;
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
class AtomicExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AtomicExpr> in(const Index &index);
  static gap::generator<AtomicExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AtomicExpr> by_id(const Index &, EntityId);
  static gap::generator<AtomicExpr> in(const Fragment &frag);
  static gap::generator<AtomicExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ATOMIC_EXPR;
  }

  static gap::generator<AtomicExpr> containing(const Decl &decl);
  static gap::generator<AtomicExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<AtomicExpr> containing(const Stmt &stmt);
  static gap::generator<AtomicExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AtomicExpr> from(const Stmt &parent);

  inline static std::optional<AtomicExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AtomicExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AtomicExpr> from(const Reference &r);
  static std::optional<AtomicExpr> from(const TokenContext &t);

  Token builtin_token(void) const;
  AtomicExprAtomicOp operation(void) const;
  Expr order(void) const;
  std::optional<Expr> order_fail(void) const;
  Expr pointer(void) const;
  Token r_paren_token(void) const;
  std::optional<Expr> scope(void) const;
  std::optional<Expr> value1(void) const;
  std::optional<Expr> value2(void) const;
  Type value_type(void) const;
  std::optional<Expr> weak(void) const;
  bool is_cmp_x_chg(void) const;
  bool is_open_cl(void) const;
  bool is_volatile(void) const;
  std::optional<Expr> nth_sub_expression(unsigned n) const;
  unsigned num_sub_expressions(void) const;
  gap::generator<Expr> sub_expressions(void) const &;
};

static_assert(sizeof(AtomicExpr) == sizeof(Expr));

#endif
} // namespace mx
