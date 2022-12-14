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
class CoroutineSuspendExpr;
class Expr;
class OpaqueValueExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CoroutineSuspendExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoroutineSuspendExpr>;

class CoroutineSuspendExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CoroutineSuspendExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CoroutineSuspendExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CoroutineSuspendExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static CoroutineSuspendExprContainingStmtRange containing(const Decl &decl);
  static CoroutineSuspendExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoroutineSuspendExpr> from(const TokenContext &c);
  static std::optional<CoroutineSuspendExpr> from(const Expr &parent);

  inline static std::optional<CoroutineSuspendExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CoroutineSuspendExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoroutineSuspendExpr> from(const ValueStmt &parent);

  inline static std::optional<CoroutineSuspendExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CoroutineSuspendExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoroutineSuspendExpr> from(const Stmt &parent);

  inline static std::optional<CoroutineSuspendExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoroutineSuspendExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr common_expression(void) const;
  Token keyword_token(void) const;
  OpaqueValueExpr opaque_value(void) const;
  Expr operand(void) const;
  Expr ready_expression(void) const;
  Expr resume_expression(void) const;
  Expr suspend_expression(void) const;
};

static_assert(sizeof(CoroutineSuspendExpr) == sizeof(Expr));

#endif
} // namespace mx
