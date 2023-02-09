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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
  static gap::generator<OpaqueValueExpr> in(const Fragment &frag);
  static gap::generator<OpaqueValueExpr> in(const Index &index);
  static gap::generator<OpaqueValueExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpaqueValueExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OPAQUE_VALUE_EXPR;
  }

  static gap::generator<OpaqueValueExpr> containing(const Decl &decl);
  static gap::generator<OpaqueValueExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OpaqueValueExpr> containing(const Stmt &stmt);
  static gap::generator<OpaqueValueExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OpaqueValueExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OpaqueValueExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
