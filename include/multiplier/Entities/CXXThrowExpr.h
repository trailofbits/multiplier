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
#include "StmtUseSelector.h"

namespace mx {
class CXXThrowExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXThrowExprRange = DerivedEntityRange<StmtIterator, CXXThrowExpr>;
using CXXThrowExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXThrowExpr>;
using CXXThrowExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXThrowExpr>;

class CXXThrowExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXThrowExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXThrowExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXThrowExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_THROW_EXPR;
  }

  static CXXThrowExprContainingStmtRange containing(const Decl &decl);
  static CXXThrowExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXThrowExpr> from(const TokenContext &c);
  static std::optional<CXXThrowExpr> from(const Expr &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThrowExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThrowExpr> from(const Stmt &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> sub_expression(void) const;
  Token throw_token(void) const;
  bool is_thrown_variable_in_scope(void) const;
};

static_assert(sizeof(CXXThrowExpr) == sizeof(Expr));

#endif
} // namespace mx
