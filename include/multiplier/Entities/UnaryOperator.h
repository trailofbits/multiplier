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
using UnaryOperatorRange = DerivedEntityRange<StmtIterator, UnaryOperator>;
using UnaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnaryOperator>;
using UnaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnaryOperator>;

class UnaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UnaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
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

  static UnaryOperatorContainingStmtRange containing(const Decl &decl);
  static UnaryOperatorContainingStmtRange containing(const Stmt &stmt);

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
