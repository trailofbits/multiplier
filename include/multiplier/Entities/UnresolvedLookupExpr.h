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

#include "OverloadExpr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OverloadExpr;
class Stmt;
class UnresolvedLookupExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnresolvedLookupExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedLookupExpr>;
using UnresolvedLookupExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnresolvedLookupExpr>;

class UnresolvedLookupExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<UnresolvedLookupExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static UnresolvedLookupExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnresolvedLookupExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_LOOKUP_EXPR;
  }

  static UnresolvedLookupExprContainingStmtRange containing(const Decl &decl);
  static UnresolvedLookupExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedLookupExpr> from(const TokenContext &c);
  static std::optional<UnresolvedLookupExpr> from(const OverloadExpr &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<OverloadExpr> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const Expr &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const ValueStmt &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const Stmt &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_overloaded(void) const;
  bool requires_adl(void) const;
};

static_assert(sizeof(UnresolvedLookupExpr) == sizeof(OverloadExpr));

#endif
} // namespace mx
