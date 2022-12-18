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
class ShuffleVectorExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ShuffleVectorExprRange = DerivedEntityRange<StmtIterator, ShuffleVectorExpr>;
using ShuffleVectorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ShuffleVectorExpr>;
using ShuffleVectorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ShuffleVectorExpr>;

class ShuffleVectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ShuffleVectorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ShuffleVectorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ShuffleVectorExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SHUFFLE_VECTOR_EXPR;
  }

  static ShuffleVectorExprContainingStmtRange containing(const Decl &decl);
  static ShuffleVectorExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ShuffleVectorExpr> from(const TokenContext &c);
  static std::optional<ShuffleVectorExpr> from(const Expr &parent);

  inline static std::optional<ShuffleVectorExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ShuffleVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ShuffleVectorExpr> from(const ValueStmt &parent);

  inline static std::optional<ShuffleVectorExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ShuffleVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ShuffleVectorExpr> from(const Stmt &parent);

  inline static std::optional<ShuffleVectorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ShuffleVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ShuffleVectorExpr) == sizeof(Expr));

#endif
} // namespace mx
