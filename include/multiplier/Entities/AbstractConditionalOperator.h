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
  inline static gap::generator<AbstractConditionalOperator> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<AbstractConditionalOperator> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AbstractConditionalOperator::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static gap::generator<AbstractConditionalOperator> containing(const Decl &decl);
  static gap::generator<AbstractConditionalOperator> containing(const Stmt &stmt);

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
