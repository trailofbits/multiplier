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

#include "ExplicitCastExpr.h"
#include "StmtKind.h"

namespace mx {
class CStyleCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CStyleCastExprRange = DerivedEntityRange<StmtIterator, CStyleCastExpr>;
using CStyleCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CStyleCastExpr>;
using CStyleCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CStyleCastExpr>;

class CStyleCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CStyleCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CStyleCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CStyleCastExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::C_STYLE_CAST_EXPR;
  }

  static CStyleCastExprContainingStmtRange containing(const Decl &decl);
  static CStyleCastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CStyleCastExpr> from(const TokenContext &c);
  static std::optional<CStyleCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const CastExpr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const Expr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const Stmt &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(CStyleCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
