// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ArrayInitLoopExpr;
class Decl;
class Expr;
class OpaqueValueExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArrayInitLoopExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ArrayInitLoopExpr> in(const Index &index);
  static gap::generator<ArrayInitLoopExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArrayInitLoopExpr> by_id(const Index &, EntityId);
  static gap::generator<ArrayInitLoopExpr> in(const Fragment &frag);
  static gap::generator<ArrayInitLoopExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_INIT_LOOP_EXPR;
  }

  static gap::generator<ArrayInitLoopExpr> containing(const Decl &decl);
  static gap::generator<ArrayInitLoopExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ArrayInitLoopExpr> containing(const Stmt &stmt);
  static gap::generator<ArrayInitLoopExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArrayInitLoopExpr> from_base(const Stmt &parent);
  inline static std::optional<ArrayInitLoopExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ArrayInitLoopExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ArrayInitLoopExpr> from(const Reference &r);
  static std::optional<ArrayInitLoopExpr> from(const VariantEntity &e);
  static std::optional<ArrayInitLoopExpr> from(const TokenContext &t);

  OpaqueValueExpr common_expression(void) const;
  Expr sub_expression(void) const;
};

static_assert(sizeof(ArrayInitLoopExpr) == sizeof(Expr));

#endif
} // namespace mx
