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

#include "CallExpr.h"
#include "OverloadedOperatorKind.h"
#include "StmtKind.h"

namespace mx {
class CXXOperatorCallExpr;
class CallExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXOperatorCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXOperatorCallExpr> in(const Fragment &frag);
  static gap::generator<CXXOperatorCallExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_OPERATOR_CALL_EXPR;
  }

  static gap::generator<CXXOperatorCallExpr> containing(const Decl &decl);
  static gap::generator<CXXOperatorCallExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXOperatorCallExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXOperatorCallExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXOperatorCallExpr> from(const CallExpr &parent);

  inline static std::optional<CXXOperatorCallExpr> from(const std::optional<CallExpr> &parent) {
    if (parent) {
      return CXXOperatorCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXOperatorCallExpr> from(const Expr &parent);

  inline static std::optional<CXXOperatorCallExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXOperatorCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXOperatorCallExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXOperatorCallExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXOperatorCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXOperatorCallExpr> from(const Stmt &parent);

  inline static std::optional<CXXOperatorCallExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXOperatorCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OverloadedOperatorKind operator_(void) const;
  Token operator_token(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_infix_binary_operation(void) const;
};

static_assert(sizeof(CXXOperatorCallExpr) == sizeof(CallExpr));

#endif
} // namespace mx
