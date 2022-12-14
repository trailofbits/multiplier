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
class DesignatedInitExpr;
class Designator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DesignatedInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DesignatedInitExpr>;

class DesignatedInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<DesignatedInitExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DesignatedInitExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DesignatedInitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DESIGNATED_INIT_EXPR;
  }

  static DesignatedInitExprContainingStmtRange containing(const Decl &decl);
  static DesignatedInitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DesignatedInitExpr> from(const TokenContext &c);
  static std::optional<DesignatedInitExpr> from(const Expr &parent);

  inline static std::optional<DesignatedInitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DesignatedInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitExpr> from(const ValueStmt &parent);

  inline static std::optional<DesignatedInitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DesignatedInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitExpr> from(const Stmt &parent);

  inline static std::optional<DesignatedInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DesignatedInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Designator> designators(void) const;
  TokenRange designators_source_range(void) const;
  Token equal_or_colon_token(void) const;
  Expr initializer(void) const;
  bool is_direct_initializer(void) const;
  bool uses_gnu_syntax(void) const;
  std::vector<Expr> sub_expressions(void) const;
};

static_assert(sizeof(DesignatedInitExpr) == sizeof(Expr));

#endif
} // namespace mx
