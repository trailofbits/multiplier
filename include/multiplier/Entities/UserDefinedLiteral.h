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

#include "CallExpr.h"
#include "UserDefinedLiteralLiteralOperatorKind.h"

namespace mx {
class CallExpr;
class Decl;
class Expr;
class Stmt;
class Token;
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
  static gap::generator<UserDefinedLiteral> in(const Fragment &frag);
  static gap::generator<UserDefinedLiteral> in(const File &file);
  static gap::generator<UserDefinedLiteral> in(const Index &index);
  static gap::generator<UserDefinedLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UserDefinedLiteral> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::USER_DEFINED_LITERAL;
  }

  static gap::generator<UserDefinedLiteral> containing(const Decl &decl);
  static gap::generator<UserDefinedLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<UserDefinedLiteral> containing(const Stmt &stmt);
  static gap::generator<UserDefinedLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UserDefinedLiteral> from(const Stmt &parent);

  inline static std::optional<UserDefinedLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UserDefinedLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<UserDefinedLiteral> from(const Reference &r) {
    return UserDefinedLiteral::from(r.as_statement());
  }

  inline static std::optional<UserDefinedLiteral> from(const TokenContext &t) {
    return UserDefinedLiteral::from(t.as_statement());
  }

  Expr cooked_literal(void) const;
  UserDefinedLiteralLiteralOperatorKind literal_operator_kind(void) const;
  Token ud_suffix_token(void) const;
};

static_assert(sizeof(UserDefinedLiteral) == sizeof(CallExpr));

#endif
} // namespace mx
