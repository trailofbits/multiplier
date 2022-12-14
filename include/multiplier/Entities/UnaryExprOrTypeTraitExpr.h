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
#include "StmtUseSelector.h"
#include "TypeUseSelector.h"
#include "UnaryExprOrTypeTrait.h"

namespace mx {
class Expr;
class Stmt;
class Type;
class UnaryExprOrTypeTraitExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnaryExprOrTypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnaryExprOrTypeTraitExpr>;

class UnaryExprOrTypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<UnaryExprOrTypeTraitExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnaryExprOrTypeTraitExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnaryExprOrTypeTraitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR;
  }

  static UnaryExprOrTypeTraitExprContainingStmtRange containing(const Decl &decl);
  static UnaryExprOrTypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnaryExprOrTypeTraitExpr> from(const TokenContext &c);
  static std::optional<UnaryExprOrTypeTraitExpr> from(const Expr &parent);

  inline static std::optional<UnaryExprOrTypeTraitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UnaryExprOrTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnaryExprOrTypeTraitExpr> from(const ValueStmt &parent);

  inline static std::optional<UnaryExprOrTypeTraitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UnaryExprOrTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnaryExprOrTypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<UnaryExprOrTypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnaryExprOrTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> argument_expression(void) const;
  std::optional<Type> argument_type(void) const;
  UnaryExprOrTypeTrait expression_or_trait_kind(void) const;
  Token operator_token(void) const;
  Token r_paren_token(void) const;
  Type type_of_argument(void) const;
  bool is_argument_type(void) const;
};

static_assert(sizeof(UnaryExprOrTypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
