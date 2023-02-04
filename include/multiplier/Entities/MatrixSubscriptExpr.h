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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class MatrixSubscriptExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MatrixSubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MatrixSubscriptExpr> in(const Fragment &frag);
  static gap::generator<MatrixSubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MATRIX_SUBSCRIPT_EXPR;
  }

  static gap::generator<MatrixSubscriptExpr> containing(const Decl &decl);
  static gap::generator<MatrixSubscriptExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<MatrixSubscriptExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<MatrixSubscriptExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<MatrixSubscriptExpr> from(const Expr &parent);

  inline static std::optional<MatrixSubscriptExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return MatrixSubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MatrixSubscriptExpr> from(const ValueStmt &parent);

  inline static std::optional<MatrixSubscriptExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return MatrixSubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MatrixSubscriptExpr> from(const Stmt &parent);

  inline static std::optional<MatrixSubscriptExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MatrixSubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Expr column_index(void) const;
  Token r_bracket_token(void) const;
  Expr row_index(void) const;
  bool is_incomplete(void) const;
};

static_assert(sizeof(MatrixSubscriptExpr) == sizeof(Expr));

#endif
} // namespace mx
