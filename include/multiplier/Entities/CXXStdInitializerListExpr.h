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
class CXXStdInitializerListExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXStdInitializerListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXStdInitializerListExpr> in(const Fragment &frag);
  static gap::generator<CXXStdInitializerListExpr> in(const Index &index);
  static gap::generator<CXXStdInitializerListExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXStdInitializerListExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_STD_INITIALIZER_LIST_EXPR;
  }

  static gap::generator<CXXStdInitializerListExpr> containing(const Decl &decl);
  static gap::generator<CXXStdInitializerListExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXStdInitializerListExpr> containing(const Stmt &stmt);
  static gap::generator<CXXStdInitializerListExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXStdInitializerListExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXStdInitializerListExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXStdInitializerListExpr> from(const Expr &parent);

  inline static std::optional<CXXStdInitializerListExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXStdInitializerListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStdInitializerListExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXStdInitializerListExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXStdInitializerListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStdInitializerListExpr> from(const Stmt &parent);

  inline static std::optional<CXXStdInitializerListExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXStdInitializerListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(CXXStdInitializerListExpr) == sizeof(Expr));

#endif
} // namespace mx
