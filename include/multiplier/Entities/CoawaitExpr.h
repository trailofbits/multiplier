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

#include "CoroutineSuspendExpr.h"
#include "StmtKind.h"

namespace mx {
class CoawaitExpr;
class CoroutineSuspendExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CoawaitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoawaitExpr>;

class CoawaitExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CoawaitExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CoawaitExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CoawaitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COAWAIT_EXPR;
  }

  static CoawaitExprContainingStmtRange containing(const Decl &decl);
  static CoawaitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoawaitExpr> from(const TokenContext &c);
  static std::optional<CoawaitExpr> from(const CoroutineSuspendExpr &parent);

  inline static std::optional<CoawaitExpr> from(const std::optional<CoroutineSuspendExpr> &parent) {
    if (parent) {
      return CoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoawaitExpr> from(const Expr &parent);

  inline static std::optional<CoawaitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoawaitExpr> from(const ValueStmt &parent);

  inline static std::optional<CoawaitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoawaitExpr> from(const Stmt &parent);

  inline static std::optional<CoawaitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_implicit(void) const;
};

static_assert(sizeof(CoawaitExpr) == sizeof(CoroutineSuspendExpr));

#endif
} // namespace mx
