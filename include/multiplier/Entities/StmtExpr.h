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
class CompoundStmt;
class Decl;
class Expr;
class Stmt;
class StmtExpr;
class Token;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StmtExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<StmtExpr> in(const Fragment &frag);
  static gap::generator<StmtExpr> in(const File &file);
  static gap::generator<StmtExpr> in(const Index &index);
  static gap::generator<StmtExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<StmtExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::STMT_EXPR;
  }

  static gap::generator<StmtExpr> containing(const Decl &decl);
  static gap::generator<StmtExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<StmtExpr> containing(const Stmt &stmt);
  static gap::generator<StmtExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<StmtExpr> from(const Stmt &parent);

  inline static std::optional<StmtExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return StmtExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<StmtExpr> from(const Reference &r);
  static std::optional<StmtExpr> from(const TokenContext &t);

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  CompoundStmt sub_statement(void) const;
};

static_assert(sizeof(StmtExpr) == sizeof(Expr));

#endif
} // namespace mx
