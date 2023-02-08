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
class CXXBindTemporaryExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXBindTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXBindTemporaryExpr> in(const Fragment &frag);
  static gap::generator<CXXBindTemporaryExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BIND_TEMPORARY_EXPR;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<CXXBindTemporaryExpr> containing(const Decl &decl);
  static gap::generator<CXXBindTemporaryExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXBindTemporaryExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXBindTemporaryExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXBindTemporaryExpr> from(const Expr &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBindTemporaryExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBindTemporaryExpr> from(const Stmt &parent);

  inline static std::optional<CXXBindTemporaryExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXBindTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(CXXBindTemporaryExpr) == sizeof(Expr));

#endif
} // namespace mx
