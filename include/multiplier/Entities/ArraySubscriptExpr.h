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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class ArraySubscriptExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArraySubscriptExprRange = DerivedEntityRange<StmtIterator, ArraySubscriptExpr>;
using ArraySubscriptExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArraySubscriptExpr>;
using ArraySubscriptExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArraySubscriptExpr>;

class ArraySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArraySubscriptExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArraySubscriptExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ArraySubscriptExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_SUBSCRIPT_EXPR;
  }

  static ArraySubscriptExprContainingStmtRange containing(const Decl &decl);
  static ArraySubscriptExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArraySubscriptExpr> from(const TokenContext &c);
  static std::optional<ArraySubscriptExpr> from(const Expr &parent);

  inline static std::optional<ArraySubscriptExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ArraySubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArraySubscriptExpr> from(const ValueStmt &parent);

  inline static std::optional<ArraySubscriptExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ArraySubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArraySubscriptExpr> from(const Stmt &parent);

  inline static std::optional<ArraySubscriptExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArraySubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Expr index(void) const;
  Expr lhs(void) const;
  Token r_bracket_token(void) const;
  Expr rhs(void) const;
};

static_assert(sizeof(ArraySubscriptExpr) == sizeof(Expr));

#endif
} // namespace mx
