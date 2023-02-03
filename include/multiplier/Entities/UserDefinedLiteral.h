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

#include "CallExpr.h"
#include "StmtKind.h"
#include "UserDefinedLiteralLiteralOperatorKind.h"

namespace mx {
class CallExpr;
class Expr;
class Stmt;
class UserDefinedLiteral;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UserDefinedLiteral : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<UserDefinedLiteral> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UserDefinedLiteral> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UserDefinedLiteral::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::USER_DEFINED_LITERAL;
  }

  static gap::generator<UserDefinedLiteral> containing(const Decl &decl);
  static gap::generator<UserDefinedLiteral> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UserDefinedLiteral> from(const TokenContext &c);
  static std::optional<UserDefinedLiteral> from(const CallExpr &parent);

  inline static std::optional<UserDefinedLiteral> from(const std::optional<CallExpr> &parent) {
    if (parent) {
      return UserDefinedLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UserDefinedLiteral> from(const Expr &parent);

  inline static std::optional<UserDefinedLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UserDefinedLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UserDefinedLiteral> from(const ValueStmt &parent);

  inline static std::optional<UserDefinedLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UserDefinedLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UserDefinedLiteral> from(const Stmt &parent);

  inline static std::optional<UserDefinedLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UserDefinedLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr cooked_literal(void) const;
  UserDefinedLiteralLiteralOperatorKind literal_operator_kind(void) const;
  Token ud_suffix_token(void) const;
};

static_assert(sizeof(UserDefinedLiteral) == sizeof(CallExpr));

#endif
} // namespace mx
