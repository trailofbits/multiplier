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

#include "Expr.h"
#include "StmtKind.h"
#include "UnaryOperatorKind.h"

namespace mx {
class Expr;
class Stmt;
class UnaryOperator;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<UnaryOperator> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnaryOperator> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UnaryOperator::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNARY_OPERATOR;
  }

  static gap::generator<UnaryOperator> containing(const Decl &decl);
  static gap::generator<UnaryOperator> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnaryOperator> from(const TokenContext &c);
  static std::optional<UnaryOperator> from(const Expr &parent);

  inline static std::optional<UnaryOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UnaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnaryOperator> from(const ValueStmt &parent);

  inline static std::optional<UnaryOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UnaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnaryOperator> from(const Stmt &parent);

  inline static std::optional<UnaryOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool can_overflow(void) const;
  UnaryOperatorKind opcode(void) const;
  Token operator_token(void) const;
  Expr sub_expression(void) const;
  bool has_stored_fp_features(void) const;
  bool is_arithmetic_operation(void) const;
  bool is_decrement_operation(void) const;
  bool is_increment_decrement_operation(void) const;
  bool is_increment_operation(void) const;
  bool is_postfix(void) const;
  bool is_prefix(void) const;
};

static_assert(sizeof(UnaryOperator) == sizeof(Expr));

#endif
} // namespace mx
