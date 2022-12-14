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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class GenericSelectionExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using GenericSelectionExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, GenericSelectionExpr>;
using GenericSelectionExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GenericSelectionExpr>;

class GenericSelectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<GenericSelectionExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static GenericSelectionExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : GenericSelectionExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GENERIC_SELECTION_EXPR;
  }

  static GenericSelectionExprContainingStmtRange containing(const Decl &decl);
  static GenericSelectionExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GenericSelectionExpr> from(const TokenContext &c);
  static std::optional<GenericSelectionExpr> from(const Expr &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GenericSelectionExpr> from(const ValueStmt &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GenericSelectionExpr> from(const Stmt &parent);

  inline static std::optional<GenericSelectionExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GenericSelectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> association_expressions(void) const;
  Expr controlling_expression(void) const;
  Token default_token(void) const;
  Token generic_token(void) const;
  Token r_paren_token(void) const;
  Expr result_expression(void) const;
  bool is_result_dependent(void) const;
};

static_assert(sizeof(GenericSelectionExpr) == sizeof(Expr));

#endif
} // namespace mx
