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
class PseudoObjectExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PseudoObjectExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, PseudoObjectExpr>;

class PseudoObjectExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<PseudoObjectExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<PseudoObjectExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : PseudoObjectExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PSEUDO_OBJECT_EXPR;
  }

  static PseudoObjectExprContainingStmtRange containing(const Decl &decl);
  static PseudoObjectExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PseudoObjectExpr> from(const TokenContext &c);
  static std::optional<PseudoObjectExpr> from(const Expr &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PseudoObjectExpr> from(const ValueStmt &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PseudoObjectExpr> from(const Stmt &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr result_expression(void) const;
  Expr syntactic_form(void) const;
  std::vector<Expr> semantics(void) const;
  std::vector<Expr> semantic_expressions(void) const;
};

static_assert(sizeof(PseudoObjectExpr) == sizeof(Expr));

#endif
} // namespace mx
