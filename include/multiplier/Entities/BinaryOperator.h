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

#include "BinaryOperatorKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class BinaryOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BinaryOperatorRange = DerivedEntityRange<StmtIterator, BinaryOperator>;
using BinaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, BinaryOperator>;
using BinaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BinaryOperator>;

class BinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BinaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BinaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : BinaryOperator::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BINARY_OPERATOR;
  }

  static BinaryOperatorContainingStmtRange containing(const Decl &decl);
  static BinaryOperatorContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BinaryOperator> from(const TokenContext &c);
  static std::optional<BinaryOperator> from(const Expr &parent);

  inline static std::optional<BinaryOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return BinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BinaryOperator> from(const ValueStmt &parent);

  inline static std::optional<BinaryOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return BinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BinaryOperator> from(const Stmt &parent);

  inline static std::optional<BinaryOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return BinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  bool has_stored_fp_features(void) const;
  bool is_additive_operation(void) const;
  bool is_assignment_operation(void) const;
  bool is_bitwise_operation(void) const;
  bool is_comma_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_compound_assignment_operation(void) const;
  bool is_equality_operation(void) const;
  bool is_logical_operation(void) const;
  bool is_multiplicative_operation(void) const;
  bool is_pointer_memory_operation(void) const;
  bool is_relational_operation(void) const;
  bool is_shift_assign_operation(void) const;
  bool is_shift_operation(void) const;
};

static_assert(sizeof(BinaryOperator) == sizeof(Expr));

#endif
} // namespace mx
