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
class DependentCoawaitExpr;
class Expr;
class Stmt;
class UnresolvedLookupExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentCoawaitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<DependentCoawaitExpr> in(const Fragment &frag);
  static gap::generator<DependentCoawaitExpr> in(const Index &index);
  static gap::generator<DependentCoawaitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentCoawaitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEPENDENT_COAWAIT_EXPR;
  }

  static gap::generator<DependentCoawaitExpr> containing(const Decl &decl);
  static gap::generator<DependentCoawaitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<DependentCoawaitExpr> containing(const Stmt &stmt);
  static gap::generator<DependentCoawaitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<DependentCoawaitExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<DependentCoawaitExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<DependentCoawaitExpr> from(const Expr &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentCoawaitExpr> from(const ValueStmt &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentCoawaitExpr> from(const Stmt &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token keyword_token(void) const;
  Expr operand(void) const;
  UnresolvedLookupExpr operator_coawait_lookup(void) const;
};

static_assert(sizeof(DependentCoawaitExpr) == sizeof(Expr));

#endif
} // namespace mx
