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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class AbstractConditionalOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AbstractConditionalOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AbstractConditionalOperator> in(const Fragment &frag);
  static gap::generator<AbstractConditionalOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<AbstractConditionalOperator> containing(const Decl &decl);
  static gap::generator<AbstractConditionalOperator> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<AbstractConditionalOperator> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<AbstractConditionalOperator> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
