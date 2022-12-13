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
class ArrayInitLoopExpr;
class Expr;
class OpaqueValueExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArrayInitLoopExprRange = DerivedEntityRange<StmtIterator, ArrayInitLoopExpr>;
using ArrayInitLoopExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayInitLoopExpr>;
using ArrayInitLoopExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayInitLoopExpr>;

class ArrayInitLoopExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayInitLoopExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayInitLoopExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ArrayInitLoopExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_INIT_LOOP_EXPR;
  }

  static ArrayInitLoopExprContainingStmtRange containing(const Decl &decl);
  static ArrayInitLoopExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArrayInitLoopExpr> from(const TokenContext &c);
  static std::optional<ArrayInitLoopExpr> from(const Expr &parent);

  inline static std::optional<ArrayInitLoopExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ArrayInitLoopExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayInitLoopExpr> from(const ValueStmt &parent);

  inline static std::optional<ArrayInitLoopExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ArrayInitLoopExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayInitLoopExpr> from(const Stmt &parent);

  inline static std::optional<ArrayInitLoopExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArrayInitLoopExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OpaqueValueExpr common_expression(void) const;
  Expr sub_expression(void) const;
};

static_assert(sizeof(ArrayInitLoopExpr) == sizeof(Expr));

#endif
} // namespace mx
