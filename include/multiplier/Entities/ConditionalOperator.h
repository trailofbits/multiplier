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
class ConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ConditionalOperator> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ConditionalOperator> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ConditionalOperator::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONDITIONAL_OPERATOR;
  }

  static gap::generator<ConditionalOperator> containing(const Decl &decl);
  static gap::generator<ConditionalOperator> containing(const Stmt &stmt);

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
