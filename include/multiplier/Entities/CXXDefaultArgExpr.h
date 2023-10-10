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
class CXXDefaultArgExpr;
class Decl;
class Expr;
class ParmVarDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDefaultArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDefaultArgExpr> in(const Index &index);
  static gap::generator<CXXDefaultArgExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDefaultArgExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXDefaultArgExpr> in(const Fragment &frag);
  static gap::generator<CXXDefaultArgExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEFAULT_ARG_EXPR;
  }

  static gap::generator<CXXDefaultArgExpr> containing(const Decl &decl);
  static gap::generator<CXXDefaultArgExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDefaultArgExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDefaultArgExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDefaultArgExpr> from(const Stmt &parent);

  inline static std::optional<CXXDefaultArgExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDefaultArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDefaultArgExpr> from(const Reference &r);
  static std::optional<CXXDefaultArgExpr> from(const TokenContext &t);

  Expr adjusted_rewritten_expression(void) const;
  Expr expression(void) const;
  ParmVarDecl parameter(void) const;
  Expr rewritten_expression(void) const;
  Token used_token(void) const;
  bool has_rewritten_initializer(void) const;
};

static_assert(sizeof(CXXDefaultArgExpr) == sizeof(Expr));

#endif
} // namespace mx
