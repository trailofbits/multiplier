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

#include "ExplicitCastExpr.h"
#include "StmtKind.h"

namespace mx {
class BuiltinBitCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BuiltinBitCastExprRange = DerivedEntityRange<StmtIterator, BuiltinBitCastExpr>;
using BuiltinBitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinBitCastExpr>;
using BuiltinBitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BuiltinBitCastExpr>;

class BuiltinBitCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BuiltinBitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinBitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BuiltinBitCastExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BUILTIN_BIT_CAST_EXPR;
  }

  static BuiltinBitCastExprContainingStmtRange containing(const Decl &decl);
  static BuiltinBitCastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BuiltinBitCastExpr> from(const TokenContext &c);
  static std::optional<BuiltinBitCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<BuiltinBitCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return BuiltinBitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinBitCastExpr> from(const CastExpr &parent);

  inline static std::optional<BuiltinBitCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return BuiltinBitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinBitCastExpr> from(const Expr &parent);

  inline static std::optional<BuiltinBitCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return BuiltinBitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinBitCastExpr> from(const ValueStmt &parent);

  inline static std::optional<BuiltinBitCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return BuiltinBitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinBitCastExpr> from(const Stmt &parent);

  inline static std::optional<BuiltinBitCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return BuiltinBitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(BuiltinBitCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
