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
class DependentScopeDeclRefExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentScopeDeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<DependentScopeDeclRefExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DependentScopeDeclRefExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DependentScopeDeclRefExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR;
  }

  static gap::generator<DependentScopeDeclRefExpr> containing(const Decl &decl);
  static gap::generator<DependentScopeDeclRefExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DependentScopeDeclRefExpr> from(const TokenContext &c);
  static std::optional<DependentScopeDeclRefExpr> from(const Expr &parent);

  inline static std::optional<DependentScopeDeclRefExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DependentScopeDeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentScopeDeclRefExpr> from(const ValueStmt &parent);

  inline static std::optional<DependentScopeDeclRefExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DependentScopeDeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentScopeDeclRefExpr> from(const Stmt &parent);

  inline static std::optional<DependentScopeDeclRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DependentScopeDeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token l_angle_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

static_assert(sizeof(DependentScopeDeclRefExpr) == sizeof(Expr));

#endif
} // namespace mx
