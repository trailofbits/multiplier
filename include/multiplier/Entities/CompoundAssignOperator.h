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

#include "BinaryOperator.h"
#include "StmtKind.h"

namespace mx {
class BinaryOperator;
class CompoundAssignOperator;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CompoundAssignOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, CompoundAssignOperator>;
using CompoundAssignOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CompoundAssignOperator>;

class CompoundAssignOperator : public BinaryOperator {
 private:
  friend class FragmentImpl;
  friend class BinaryOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CompoundAssignOperator> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static CompoundAssignOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CompoundAssignOperator::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_ASSIGN_OPERATOR;
  }

  static CompoundAssignOperatorContainingStmtRange containing(const Decl &decl);
  static CompoundAssignOperatorContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundAssignOperator> from(const TokenContext &c);
  static std::optional<CompoundAssignOperator> from(const BinaryOperator &parent);

  inline static std::optional<CompoundAssignOperator> from(const std::optional<BinaryOperator> &parent) {
    if (parent) {
      return CompoundAssignOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CompoundAssignOperator> from(const Expr &parent);

  inline static std::optional<CompoundAssignOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CompoundAssignOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CompoundAssignOperator> from(const ValueStmt &parent);

  inline static std::optional<CompoundAssignOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CompoundAssignOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CompoundAssignOperator> from(const Stmt &parent);

  inline static std::optional<CompoundAssignOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CompoundAssignOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type computation_lhs_type(void) const;
  Type computation_result_type(void) const;
};

static_assert(sizeof(CompoundAssignOperator) == sizeof(BinaryOperator));

#endif
} // namespace mx
