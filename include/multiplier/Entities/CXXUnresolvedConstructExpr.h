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
class CXXUnresolvedConstructExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXUnresolvedConstructExprRange = DerivedEntityRange<StmtIterator, CXXUnresolvedConstructExpr>;
using CXXUnresolvedConstructExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXUnresolvedConstructExpr>;
using CXXUnresolvedConstructExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXUnresolvedConstructExpr>;

class CXXUnresolvedConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXUnresolvedConstructExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXUnresolvedConstructExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : CXXUnresolvedConstructExpr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
  }

  static CXXUnresolvedConstructExprContainingStmtRange containing(const Decl &decl);
  static CXXUnresolvedConstructExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXUnresolvedConstructExpr> from(const TokenContext &c);
  static std::optional<CXXUnresolvedConstructExpr> from(const Expr &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUnresolvedConstructExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUnresolvedConstructExpr> from(const Stmt &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> arguments(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Type type_as_written(void) const;
  bool is_list_initialization(void) const;
};

static_assert(sizeof(CXXUnresolvedConstructExpr) == sizeof(Expr));

#endif
} // namespace mx
