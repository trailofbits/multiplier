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
class Decl;
class Expr;
class Stmt;
class Token;
class VAArgExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VAArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<VAArgExpr> in(const Index &index);
  static gap::generator<VAArgExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VAArgExpr> by_id(const Index &, EntityId);
  static gap::generator<VAArgExpr> in(const Fragment &frag);
  static gap::generator<VAArgExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::VA_ARG_EXPR;
  }

  static gap::generator<VAArgExpr> containing(const Decl &decl);
  static gap::generator<VAArgExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<VAArgExpr> containing(const Stmt &stmt);
  static gap::generator<VAArgExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VAArgExpr> from_base(const Stmt &parent);
  inline static std::optional<VAArgExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<VAArgExpr> from(const std::optional<Stmt> &parent);
  static std::optional<VAArgExpr> from(const Reference &r);
  static std::optional<VAArgExpr> from(const VariantEntity &e);
  static std::optional<VAArgExpr> from(const TokenContext &t);

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr sub_expression(void) const;
  bool is_microsoft_abi(void) const;
};

static_assert(sizeof(VAArgExpr) == sizeof(Expr));

#endif
} // namespace mx
