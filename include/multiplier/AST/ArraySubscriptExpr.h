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
class ArraySubscriptExpr;
class Decl;
class Expr;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ArraySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ArraySubscriptExpr> in(const Index &index);
  static gap::generator<ArraySubscriptExpr> in(const Fragment &frag);
  static gap::generator<ArraySubscriptExpr> in(const File &file);
  static gap::generator<ArraySubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ArraySubscriptExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ArraySubscriptExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_SUBSCRIPT_EXPR;
  }

  static gap::generator<ArraySubscriptExpr> containing(const Decl &decl);
  static gap::generator<ArraySubscriptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ArraySubscriptExpr> containing(const Stmt &stmt);
  static gap::generator<ArraySubscriptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArraySubscriptExpr> by_id(const Index &, EntityId);

  static std::optional<ArraySubscriptExpr> from_base(const Stmt &parent);
  inline static std::optional<ArraySubscriptExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ArraySubscriptExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ArraySubscriptExpr> from(const Reference &r);
  static std::optional<ArraySubscriptExpr> from(const VariantEntity &e);
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
