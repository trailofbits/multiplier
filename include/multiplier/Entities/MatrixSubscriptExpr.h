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

namespace mx {
class Decl;
class Expr;
class MatrixSubscriptExpr;
class Stmt;
class Token;
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
  static gap::generator<MatrixSubscriptExpr> in(const File &file);
  static gap::generator<MatrixSubscriptExpr> in(const Index &index);
  static gap::generator<MatrixSubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MatrixSubscriptExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MATRIX_SUBSCRIPT_EXPR;
  }

  static gap::generator<MatrixSubscriptExpr> containing(const Decl &decl);
  static gap::generator<MatrixSubscriptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MatrixSubscriptExpr> containing(const Stmt &stmt);
  static gap::generator<MatrixSubscriptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MatrixSubscriptExpr> from(const Stmt &parent);

  inline static std::optional<MatrixSubscriptExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MatrixSubscriptExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<MatrixSubscriptExpr> from(const Reference &r) {
    return MatrixSubscriptExpr::from(r.as_statement());
  }

  inline static std::optional<MatrixSubscriptExpr> from(const TokenContext &t) {
    return MatrixSubscriptExpr::from(t.as_statement());
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
