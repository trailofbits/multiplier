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

#include "Expr.h"
#include "StmtKind.h"
#include "TypeTrait.h"

namespace mx {
class Expr;
class Stmt;
class Type;
class TypeTraitExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<TypeTraitExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<TypeTraitExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeTraitExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPE_TRAIT_EXPR;
  }

  static gap::generator<TypeTraitExpr> containing(const Decl &decl);
  static gap::generator<TypeTraitExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeTraitExpr> from(const TokenContext &c);
  static std::optional<TypeTraitExpr> from(const Expr &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTraitExpr> from(const ValueStmt &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TypeTrait trait(void) const;
  std::optional<bool> value(void) const;
  std::optional<Type> nth_argument(unsigned n) const;
  gap::generator<Type> arguments(void) const;
};

static_assert(sizeof(TypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
