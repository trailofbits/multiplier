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
#include "../Use.h"

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
using UserDefinedLiteralRange = DerivedEntityRange<StmtIterator, UserDefinedLiteral>;
using UserDefinedLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, UserDefinedLiteral>;
using UserDefinedLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UserDefinedLiteral>;

class UserDefinedLiteral : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UserDefinedLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UserDefinedLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UserDefinedLiteral::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::USER_DEFINED_LITERAL;
  }

  static UserDefinedLiteralContainingStmtRange containing(const Decl &decl);
  static UserDefinedLiteralContainingStmtRange containing(const Stmt &stmt);

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
