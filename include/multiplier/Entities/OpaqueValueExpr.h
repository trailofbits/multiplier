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
class OpaqueValueExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpaqueValueExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<OpaqueValueExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OpaqueValueExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OpaqueValueExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OPAQUE_VALUE_EXPR;
  }

  static gap::generator<OpaqueValueExpr> containing(const Decl &decl);
  static gap::generator<OpaqueValueExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OpaqueValueExpr> from(const TokenContext &c);
  static std::optional<OpaqueValueExpr> from(const Expr &parent);

  inline static std::optional<OpaqueValueExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return OpaqueValueExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpaqueValueExpr> from(const ValueStmt &parent);

  inline static std::optional<OpaqueValueExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return OpaqueValueExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpaqueValueExpr> from(const Stmt &parent);

  inline static std::optional<OpaqueValueExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OpaqueValueExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
  Expr source_expression(void) const;
  bool is_unique(void) const;
};

static_assert(sizeof(OpaqueValueExpr) == sizeof(Expr));

#endif
} // namespace mx
