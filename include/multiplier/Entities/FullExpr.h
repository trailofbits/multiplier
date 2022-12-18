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
class FullExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FullExprRange = DerivedEntityRange<StmtIterator, FullExpr>;
using FullExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, FullExpr>;
using FullExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FullExpr>;

class FullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FullExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FullExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FullExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static FullExprContainingStmtRange containing(const Decl &decl);
  static FullExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FullExpr> from(const TokenContext &c);
  static std::optional<FullExpr> from(const Expr &parent);

  inline static std::optional<FullExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return FullExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FullExpr> from(const ValueStmt &parent);

  inline static std::optional<FullExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return FullExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FullExpr> from(const Stmt &parent);

  inline static std::optional<FullExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FullExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(FullExpr) == sizeof(Expr));

#endif
} // namespace mx
