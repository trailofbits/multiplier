// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CallExpr.h"
#include "UserDefinedLiteralLiteralOperatorKind.h"

namespace mx {
class EntityProvider;
class Index;
class CallExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class UserDefinedLiteral;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

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

  static std::optional<UserDefinedLiteral> from(const Reference &r);
  static std::optional<UserDefinedLiteral> from(const TokenContext &t);

  Expr cooked_literal(void) const;
  UserDefinedLiteralLiteralOperatorKind literal_operator_kind(void) const;
  Token ud_suffix_token(void) const;
};

static_assert(sizeof(UserDefinedLiteral) == sizeof(CallExpr));

#endif
} // namespace mx
