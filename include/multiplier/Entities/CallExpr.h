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

#include "CallExprADLCallKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Attr;
class CallExpr;
class Decl;
class Expr;
class FunctionDecl;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CallExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CallExpr> in(const Fragment &frag);
  static gap::generator<CallExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CALL_EXPR;
  }

  static gap::generator<CallExpr> containing(const Decl &decl);
  static gap::generator<CallExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CallExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CallExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CallExpr> from(const Expr &parent);

  inline static std::optional<CallExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CallExpr> from(const ValueStmt &parent);

  inline static std::optional<CallExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CallExpr> from(const Stmt &parent);

  inline static std::optional<CallExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> nth_argument(unsigned n) const;
  gap::generator<Expr> arguments(void) const;
  CallExprADLCallKind adl_call_kind(void) const;
  Type call_return_type(void) const;
  Expr callee(void) const;
  std::optional<Decl> callee_declaration(void) const;
  std::optional<FunctionDecl> direct_callee(void) const;
  Token r_paren_token(void) const;
  std::optional<Attr> unused_result_attribute(void) const;
  bool has_stored_fp_features(void) const;
  bool has_unused_result_attribute(void) const;
  bool is_builtin_assume_false(void) const;
  bool is_call_to_std_move(void) const;
  bool is_unevaluated_builtin_call(void) const;
  bool uses_adl(void) const;
};

static_assert(sizeof(CallExpr) == sizeof(Expr));

#endif
} // namespace mx
