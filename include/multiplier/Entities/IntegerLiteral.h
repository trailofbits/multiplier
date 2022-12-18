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
class IntegerLiteral;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IntegerLiteralRange = DerivedEntityRange<StmtIterator, IntegerLiteral>;
using IntegerLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, IntegerLiteral>;
using IntegerLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IntegerLiteral>;

class IntegerLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static IntegerLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IntegerLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : IntegerLiteral::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INTEGER_LITERAL;
  }

  static IntegerLiteralContainingStmtRange containing(const Decl &decl);
  static IntegerLiteralContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IntegerLiteral> from(const TokenContext &c);
  static std::optional<IntegerLiteral> from(const Expr &parent);

  inline static std::optional<IntegerLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return IntegerLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IntegerLiteral> from(const ValueStmt &parent);

  inline static std::optional<IntegerLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return IntegerLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IntegerLiteral> from(const Stmt &parent);

  inline static std::optional<IntegerLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return IntegerLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
};

static_assert(sizeof(IntegerLiteral) == sizeof(Expr));

#endif
} // namespace mx
