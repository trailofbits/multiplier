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
class AsTypeExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AsTypeExprRange = DerivedEntityRange<StmtIterator, AsTypeExpr>;
using AsTypeExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, AsTypeExpr>;
using AsTypeExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AsTypeExpr>;

class AsTypeExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AsTypeExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AsTypeExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AsTypeExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::AS_TYPE_EXPR;
  }

  static AsTypeExprContainingStmtRange containing(const Decl &decl);
  static AsTypeExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AsTypeExpr> from(const TokenContext &c);
  static std::optional<AsTypeExpr> from(const Expr &parent);

  inline static std::optional<AsTypeExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return AsTypeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AsTypeExpr> from(const ValueStmt &parent);

  inline static std::optional<AsTypeExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return AsTypeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AsTypeExpr> from(const Stmt &parent);

  inline static std::optional<AsTypeExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AsTypeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr src_expression(void) const;
};

static_assert(sizeof(AsTypeExpr) == sizeof(Expr));

#endif
} // namespace mx
