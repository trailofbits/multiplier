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
class Expr;
class FixedPointLiteral;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FixedPointLiteralRange = DerivedEntityRange<StmtIterator, FixedPointLiteral>;
using FixedPointLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, FixedPointLiteral>;
using FixedPointLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FixedPointLiteral>;

class FixedPointLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FixedPointLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FixedPointLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : FixedPointLiteral::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FIXED_POINT_LITERAL;
  }

  static FixedPointLiteralContainingStmtRange containing(const Decl &decl);
  static FixedPointLiteralContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FixedPointLiteral> from(const TokenContext &c);
  static std::optional<FixedPointLiteral> from(const Expr &parent);

  inline static std::optional<FixedPointLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return FixedPointLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FixedPointLiteral> from(const ValueStmt &parent);

  inline static std::optional<FixedPointLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return FixedPointLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FixedPointLiteral> from(const Stmt &parent);

  inline static std::optional<FixedPointLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FixedPointLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
};

static_assert(sizeof(FixedPointLiteral) == sizeof(Expr));

#endif
} // namespace mx
