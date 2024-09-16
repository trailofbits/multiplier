// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class Decl;
class Expr;
class File;
class MSPropertySubscriptExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MSPropertySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MSPropertySubscriptExpr> in(const Index &index);
  static gap::generator<MSPropertySubscriptExpr> in(const Fragment &frag);
  static gap::generator<MSPropertySubscriptExpr> in(const File &file);
  static gap::generator<MSPropertySubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<MSPropertySubscriptExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<MSPropertySubscriptExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR;
  }

  static gap::generator<MSPropertySubscriptExpr> containing(const Decl &decl);
  static gap::generator<MSPropertySubscriptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MSPropertySubscriptExpr> containing(const Stmt &stmt);
  static gap::generator<MSPropertySubscriptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSPropertySubscriptExpr> by_id(const Index &, EntityId);

  static std::optional<MSPropertySubscriptExpr> from_base(const Stmt &parent);
  inline static std::optional<MSPropertySubscriptExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<MSPropertySubscriptExpr> from(const std::optional<Stmt> &parent);
  static std::optional<MSPropertySubscriptExpr> from(const Reference &r);
  static std::optional<MSPropertySubscriptExpr> from(const VariantEntity &e);
  static std::optional<MSPropertySubscriptExpr> from(const TokenContext &t);

  Expr base(void) const;
  Expr index(void) const;
  Token r_bracket_token(void) const;
};

static_assert(sizeof(MSPropertySubscriptExpr) == sizeof(Expr));

#endif
} // namespace mx
