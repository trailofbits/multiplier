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
class Decl;
class Expr;
class ParenExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ParenExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ParenExpr> in(const Fragment &frag);
  static gap::generator<ParenExpr> in(const File &file);
  static gap::generator<ParenExpr> in(const Index &index);
  static gap::generator<ParenExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParenExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PAREN_EXPR;
  }

  static gap::generator<ParenExpr> containing(const Decl &decl);
  static gap::generator<ParenExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ParenExpr> containing(const Stmt &stmt);
  static gap::generator<ParenExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ParenExpr> from(const Stmt &parent);

  inline static std::optional<ParenExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ParenExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParenExpr> from(const Reference &r);
  static std::optional<ParenExpr> from(const TokenContext &t);

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Expr sub_expression(void) const;
};

static_assert(sizeof(ParenExpr) == sizeof(Expr));

#endif
} // namespace mx
