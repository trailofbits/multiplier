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

#include "CastExpr.h"
#include "StmtKind.h"

namespace mx {
class CastExpr;
class Expr;
class ImplicitCastExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ImplicitCastExprRange = DerivedEntityRange<StmtIterator, ImplicitCastExpr>;
using ImplicitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImplicitCastExpr>;
using ImplicitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ImplicitCastExpr>;

class ImplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ImplicitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImplicitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ImplicitCastExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IMPLICIT_CAST_EXPR;
  }

  static ImplicitCastExprContainingStmtRange containing(const Decl &decl);
  static ImplicitCastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ImplicitCastExpr> from(const TokenContext &c);
  static std::optional<ImplicitCastExpr> from(const CastExpr &parent);

  inline static std::optional<ImplicitCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return ImplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImplicitCastExpr> from(const Expr &parent);

  inline static std::optional<ImplicitCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ImplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImplicitCastExpr> from(const ValueStmt &parent);

  inline static std::optional<ImplicitCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ImplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImplicitCastExpr> from(const Stmt &parent);

  inline static std::optional<ImplicitCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ImplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_part_of_explicit_cast(void) const;
};

static_assert(sizeof(ImplicitCastExpr) == sizeof(CastExpr));

#endif
} // namespace mx
