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
class DependentCoawaitExpr;
class Expr;
class Stmt;
class UnresolvedLookupExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentCoawaitExprRange = DerivedEntityRange<StmtIterator, DependentCoawaitExpr>;
using DependentCoawaitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentCoawaitExpr>;
using DependentCoawaitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DependentCoawaitExpr>;

class DependentCoawaitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DependentCoawaitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentCoawaitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DependentCoawaitExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEPENDENT_COAWAIT_EXPR;
  }

  static DependentCoawaitExprContainingStmtRange containing(const Decl &decl);
  static DependentCoawaitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DependentCoawaitExpr> from(const TokenContext &c);
  static std::optional<DependentCoawaitExpr> from(const Expr &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentCoawaitExpr> from(const ValueStmt &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentCoawaitExpr> from(const Stmt &parent);

  inline static std::optional<DependentCoawaitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DependentCoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token keyword_token(void) const;
  Expr operand(void) const;
  UnresolvedLookupExpr operator_coawait_lookup(void) const;
};

static_assert(sizeof(DependentCoawaitExpr) == sizeof(Expr));

#endif
} // namespace mx
