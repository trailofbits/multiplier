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
class CXXBoolLiteralExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXBoolLiteralExpr> in(const Fragment &frag);
  static gap::generator<CXXBoolLiteralExpr> in(const File &file);
  static gap::generator<CXXBoolLiteralExpr> in(const Index &index);
  static gap::generator<CXXBoolLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXBoolLiteralExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BOOL_LITERAL_EXPR;
  }

  static gap::generator<CXXBoolLiteralExpr> containing(const Decl &decl);
  static gap::generator<CXXBoolLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXBoolLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<CXXBoolLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXBoolLiteralExpr> from(const Stmt &parent);

  inline static std::optional<CXXBoolLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBoolLiteralExpr> from(const Reference &r);
  static std::optional<CXXBoolLiteralExpr> from(const TokenContext &t);

  Token token(void) const;
  bool value(void) const;
};

static_assert(sizeof(CXXBoolLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
