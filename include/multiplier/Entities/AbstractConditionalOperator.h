// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class AbstractConditionalOperator;
class BinaryConditionalOperator;
class ConditionalOperator;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AbstractConditionalOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AbstractConditionalOperator> in(const Index &index);
  static gap::generator<AbstractConditionalOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AbstractConditionalOperator> by_id(const Index &, EntityId);
  static gap::generator<AbstractConditionalOperator> in(const Fragment &frag);
  static gap::generator<AbstractConditionalOperator> in(const File &file);

  static gap::generator<AbstractConditionalOperator> containing(const Decl &decl);
  static gap::generator<AbstractConditionalOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<AbstractConditionalOperator> containing(const Stmt &stmt);
  static gap::generator<AbstractConditionalOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AbstractConditionalOperator> from(const Stmt &parent);

  inline static std::optional<AbstractConditionalOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AbstractConditionalOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AbstractConditionalOperator> from(const Reference &r);
  static std::optional<AbstractConditionalOperator> from(const TokenContext &t);

  Token colon_token(void) const;
  Expr condition(void) const;
  Expr false_expression(void) const;
  Token question_token(void) const;
  Expr true_expression(void) const;
};

static_assert(sizeof(AbstractConditionalOperator) == sizeof(Expr));

#endif
} // namespace mx
