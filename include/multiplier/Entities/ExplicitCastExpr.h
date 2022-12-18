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

#include "CastExpr.h"
#include "StmtKind.h"

namespace mx {
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ExplicitCastExprRange = DerivedEntityRange<StmtIterator, ExplicitCastExpr>;
using ExplicitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExplicitCastExpr>;
using ExplicitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExplicitCastExpr>;

class ExplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExplicitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExplicitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ExplicitCastExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static ExplicitCastExprContainingStmtRange containing(const Decl &decl);
  static ExplicitCastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExplicitCastExpr> from(const TokenContext &c);
  static std::optional<ExplicitCastExpr> from(const CastExpr &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const Expr &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const ValueStmt &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const Stmt &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type type_as_written(void) const;
};

static_assert(sizeof(ExplicitCastExpr) == sizeof(CastExpr));

#endif
} // namespace mx
