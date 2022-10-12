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
class ChooseExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ChooseExprRange = DerivedEntityRange<StmtIterator, ChooseExpr>;
using ChooseExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ChooseExpr>;
using ChooseExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ChooseExpr>;

class ChooseExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ChooseExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ChooseExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ChooseExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CHOOSE_EXPR;
  }

  static ChooseExprContainingStmtRange containing(const Decl &decl);
  static ChooseExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ChooseExpr> from(const TokenContext &c);
  static std::optional<ChooseExpr> from(const Expr &parent);

  inline static std::optional<ChooseExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ChooseExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ChooseExpr> from(const ValueStmt &parent);

  inline static std::optional<ChooseExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ChooseExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ChooseExpr> from(const Stmt &parent);

  inline static std::optional<ChooseExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ChooseExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token builtin_token(void) const;
  Expr chosen_sub_expression(void) const;
  Expr condition(void) const;
  Expr lhs(void) const;
  Expr rhs(void) const;
  Token r_paren_token(void) const;
  bool is_condition_dependent(void) const;
  bool is_condition_true(void) const;
};

static_assert(sizeof(ChooseExpr) == sizeof(Expr));

#endif
} // namespace mx
