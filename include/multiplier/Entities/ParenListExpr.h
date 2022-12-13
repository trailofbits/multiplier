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
class ParenListExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ParenListExprRange = DerivedEntityRange<StmtIterator, ParenListExpr>;
using ParenListExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ParenListExpr>;
using ParenListExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ParenListExpr>;

class ParenListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ParenListExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ParenListExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ParenListExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PAREN_LIST_EXPR;
  }

  static ParenListExprContainingStmtRange containing(const Decl &decl);
  static ParenListExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ParenListExpr> from(const TokenContext &c);
  static std::optional<ParenListExpr> from(const Expr &parent);

  inline static std::optional<ParenListExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ParenListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParenListExpr> from(const ValueStmt &parent);

  inline static std::optional<ParenListExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ParenListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParenListExpr> from(const Stmt &parent);

  inline static std::optional<ParenListExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ParenListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  std::vector<Expr> expressions(void) const;
};

static_assert(sizeof(ParenListExpr) == sizeof(Expr));

#endif
} // namespace mx
