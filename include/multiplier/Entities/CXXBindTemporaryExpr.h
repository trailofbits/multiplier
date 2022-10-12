// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXBindTemporaryExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXBindTemporaryExprRange = DerivedEntityRange<StmtIterator, CXXBindTemporaryExpr>;
using CXXBindTemporaryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXBindTemporaryExpr>;
using CXXBindTemporaryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXBindTemporaryExpr>;

class CXXBindTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXBindTemporaryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXBindTemporaryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXBindTemporaryExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BIND_TEMPORARY_EXPR;
  }

  static CXXBindTemporaryExprContainingStmtRange containing(const Decl &decl);
  static CXXBindTemporaryExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXBindTemporaryExpr> from(const TokenContext &c);
  static std::optional<CXXBindTemporaryExpr> from(const Expr &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBindTemporaryExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBindTemporaryExpr> from(const Stmt &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(CXXBindTemporaryExpr) == sizeof(Expr));

#endif
} // namespace mx
