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
class GNUNullExpr;
class Stmt;
class Token;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GNUNullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<GNUNullExpr> in(const Fragment &frag);
  static gap::generator<GNUNullExpr> in(const File &file);
  static gap::generator<GNUNullExpr> in(const Index &index);
  static gap::generator<GNUNullExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<GNUNullExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GNU_NULL_EXPR;
  }

  static gap::generator<GNUNullExpr> containing(const Decl &decl);
  static gap::generator<GNUNullExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<GNUNullExpr> containing(const Stmt &stmt);
  static gap::generator<GNUNullExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GNUNullExpr> from(const Stmt &parent);

  inline static std::optional<GNUNullExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GNUNullExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GNUNullExpr> from(const Reference &r);
  static std::optional<GNUNullExpr> from(const TokenContext &t);

  Token token_token(void) const;
};

static_assert(sizeof(GNUNullExpr) == sizeof(Expr));

#endif
} // namespace mx
