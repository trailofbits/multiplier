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
class CXXThrowExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXThrowExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXThrowExpr> in(const Fragment &frag);
  static gap::generator<CXXThrowExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_THROW_EXPR;
  }

  static gap::generator<CXXThrowExpr> containing(const Decl &decl);
  static gap::generator<CXXThrowExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXThrowExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXThrowExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXThrowExpr> from(const Expr &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThrowExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThrowExpr> from(const Stmt &parent);

  inline static std::optional<CXXThrowExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXThrowExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> sub_expression(void) const;
  Token throw_token(void) const;
  bool is_thrown_variable_in_scope(void) const;
};

static_assert(sizeof(CXXThrowExpr) == sizeof(Expr));

#endif
} // namespace mx
