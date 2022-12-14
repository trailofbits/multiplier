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
class CXXDefaultArgExpr;
class Expr;
class ParmVarDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXDefaultArgExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDefaultArgExpr>;

class CXXDefaultArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CXXDefaultArgExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXDefaultArgExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXDefaultArgExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEFAULT_ARG_EXPR;
  }

  static CXXDefaultArgExprContainingStmtRange containing(const Decl &decl);
  static CXXDefaultArgExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDefaultArgExpr> from(const TokenContext &c);
  static std::optional<CXXDefaultArgExpr> from(const Expr &parent);

  inline static std::optional<CXXDefaultArgExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXDefaultArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDefaultArgExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXDefaultArgExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXDefaultArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDefaultArgExpr> from(const Stmt &parent);

  inline static std::optional<CXXDefaultArgExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDefaultArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr expression(void) const;
  ParmVarDecl parameter(void) const;
  Token used_token(void) const;
};

static_assert(sizeof(CXXDefaultArgExpr) == sizeof(Expr));

#endif
} // namespace mx
