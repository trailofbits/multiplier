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

namespace mx {
class AbstractConditionalOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AbstractConditionalOperatorRange = DerivedEntityRange<StmtIterator, AbstractConditionalOperator>;
using AbstractConditionalOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, AbstractConditionalOperator>;
using AbstractConditionalOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AbstractConditionalOperator>;

class AbstractConditionalOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AbstractConditionalOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AbstractConditionalOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AbstractConditionalOperator::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static AbstractConditionalOperatorContainingStmtRange containing(const Decl &decl);
  static AbstractConditionalOperatorContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AbstractConditionalOperator> from(const TokenContext &c);
  static std::optional<AbstractConditionalOperator> from(const Expr &parent);

  inline static std::optional<AbstractConditionalOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return AbstractConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AbstractConditionalOperator> from(const ValueStmt &parent);

  inline static std::optional<AbstractConditionalOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return AbstractConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AbstractConditionalOperator> from(const Stmt &parent);

  inline static std::optional<AbstractConditionalOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AbstractConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token colon_token(void) const;
  Expr condition(void) const;
  Expr false_expression(void) const;
  Token question_token(void) const;
  Expr true_expression(void) const;
};

static_assert(sizeof(AbstractConditionalOperator) == sizeof(Expr));

#endif
} // namespace mx
