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
class GenericSelectionExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GenericSelectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<GenericSelectionExpr> in(const Fragment &frag);
  static gap::generator<GenericSelectionExpr> in(const Index &index);
  static gap::generator<GenericSelectionExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<GenericSelectionExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GENERIC_SELECTION_EXPR;
  }

  static gap::generator<GenericSelectionExpr> containing(const Decl &decl);
  static gap::generator<GenericSelectionExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<GenericSelectionExpr> containing(const Stmt &stmt);
  static gap::generator<GenericSelectionExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<GenericSelectionExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<GenericSelectionExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<GenericSelectionExpr> from(const Expr &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GenericSelectionExpr> from(const ValueStmt &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GenericSelectionExpr> from(const Stmt &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> nth_association_expression(unsigned n) const;
  gap::generator<Expr> association_expressions(void) const;
  Expr controlling_expression(void) const;
  Token default_token(void) const;
  Token generic_token(void) const;
  Token r_paren_token(void) const;
  Expr result_expression(void) const;
  bool is_result_dependent(void) const;
};

static_assert(sizeof(GenericSelectionExpr) == sizeof(Expr));

#endif
} // namespace mx
