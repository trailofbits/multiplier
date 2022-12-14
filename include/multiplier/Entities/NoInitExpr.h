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
class Expr;
class NoInitExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, NoInitExpr>;

class NoInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<NoInitExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<NoInitExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NoInitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::NO_INIT_EXPR;
  }

  static NoInitExprContainingStmtRange containing(const Decl &decl);
  static NoInitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NoInitExpr> from(const TokenContext &c);
  static std::optional<NoInitExpr> from(const Expr &parent);

  inline static std::optional<NoInitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return NoInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoInitExpr> from(const ValueStmt &parent);

  inline static std::optional<NoInitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return NoInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoInitExpr> from(const Stmt &parent);

  inline static std::optional<NoInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return NoInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(NoInitExpr) == sizeof(Expr));

#endif
} // namespace mx
