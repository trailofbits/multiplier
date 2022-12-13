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

#include "AbstractConditionalOperator.h"
#include "StmtKind.h"

namespace mx {
class AbstractConditionalOperator;
class ConditionalOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConditionalOperatorRange = DerivedEntityRange<StmtIterator, ConditionalOperator>;
using ConditionalOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConditionalOperator>;
using ConditionalOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConditionalOperator>;

class ConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConditionalOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConditionalOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConditionalOperator::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONDITIONAL_OPERATOR;
  }

  static ConditionalOperatorContainingStmtRange containing(const Decl &decl);
  static ConditionalOperatorContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConditionalOperator> from(const TokenContext &c);
  static std::optional<ConditionalOperator> from(const AbstractConditionalOperator &parent);

  inline static std::optional<ConditionalOperator> from(const std::optional<AbstractConditionalOperator> &parent) {
    if (parent) {
      return ConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConditionalOperator> from(const Expr &parent);

  inline static std::optional<ConditionalOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConditionalOperator> from(const ValueStmt &parent);

  inline static std::optional<ConditionalOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConditionalOperator> from(const Stmt &parent);

  inline static std::optional<ConditionalOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr lhs(void) const;
  Expr rhs(void) const;
};

static_assert(sizeof(ConditionalOperator) == sizeof(AbstractConditionalOperator));

#endif
} // namespace mx
