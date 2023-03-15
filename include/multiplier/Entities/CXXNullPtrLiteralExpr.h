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
class CXXNullPtrLiteralExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXNullPtrLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXNullPtrLiteralExpr> in(const Fragment &frag);
  static gap::generator<CXXNullPtrLiteralExpr> in(const File &file);
  static gap::generator<CXXNullPtrLiteralExpr> in(const Index &index);
  static gap::generator<CXXNullPtrLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXNullPtrLiteralExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_NULL_PTR_LITERAL_EXPR;
  }

  static gap::generator<CXXNullPtrLiteralExpr> containing(const Decl &decl);
  static gap::generator<CXXNullPtrLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXNullPtrLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<CXXNullPtrLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXNullPtrLiteralExpr> from(const Stmt &parent);

  inline static std::optional<CXXNullPtrLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXNullPtrLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXNullPtrLiteralExpr> from(const Reference &r);
  static std::optional<CXXNullPtrLiteralExpr> from(const TokenContext &t);

  Token token(void) const;
};

static_assert(sizeof(CXXNullPtrLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
