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

#include "BinaryOperatorKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXFoldExpr;
class Expr;
class Stmt;
class UnresolvedLookupExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXFoldExprRange = DerivedEntityRange<StmtIterator, CXXFoldExpr>;
using CXXFoldExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXFoldExpr>;
using CXXFoldExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXFoldExpr>;

class CXXFoldExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXFoldExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXFoldExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXFoldExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FOLD_EXPR;
  }

  static CXXFoldExprContainingStmtRange containing(const Decl &decl);
  static CXXFoldExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXFoldExpr> from(const TokenContext &c);
  static std::optional<CXXFoldExpr> from(const Expr &parent);

  inline static std::optional<CXXFoldExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXFoldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXFoldExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXFoldExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXFoldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXFoldExpr> from(const Stmt &parent);

  inline static std::optional<CXXFoldExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXFoldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  UnresolvedLookupExpr callee(void) const;
  Token ellipsis_token(void) const;
  Expr initializer(void) const;
  Expr lhs(void) const;
  Token l_paren_token(void) const;
  std::optional<unsigned> num_expansions(void) const;
  BinaryOperatorKind operator_(void) const;
  Expr pattern(void) const;
  Expr rhs(void) const;
  Token r_paren_token(void) const;
  bool is_left_fold(void) const;
  bool is_right_fold(void) const;
};

static_assert(sizeof(CXXFoldExpr) == sizeof(Expr));

#endif
} // namespace mx
