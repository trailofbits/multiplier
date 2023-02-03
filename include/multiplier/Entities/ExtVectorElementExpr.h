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

namespace mx {
class Expr;
class ExtVectorElementExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ExtVectorElementExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ExtVectorElementExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ExtVectorElementExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
  }

  static gap::generator<ExtVectorElementExpr> containing(const Decl &decl);
  static gap::generator<ExtVectorElementExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExtVectorElementExpr> from(const TokenContext &c);
  static std::optional<ExtVectorElementExpr> from(const Expr &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const ValueStmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const Stmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

#endif
} // namespace mx
