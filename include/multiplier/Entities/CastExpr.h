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

#include "CastKind.h"
#include "DeclUseSelector.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CastExpr;
class Expr;
class FieldDecl;
class NamedDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CastExpr>;

class CastExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CastExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CastExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CastExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static CastExprContainingStmtRange containing(const Decl &decl);
  static CastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CastExpr> from(const TokenContext &c);
  static std::optional<CastExpr> from(const Expr &parent);

  inline static std::optional<CastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CastExpr> from(const ValueStmt &parent);

  inline static std::optional<CastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CastExpr> from(const Stmt &parent);

  inline static std::optional<CastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CastKind cast_kind(void) const;
  std::string_view cast_kind_name(void) const;
  std::optional<NamedDecl> conversion_function(void) const;
  Expr sub_expression(void) const;
  Expr sub_expression_as_written(void) const;
  std::optional<FieldDecl> target_union_field(void) const;
  bool has_stored_fp_features(void) const;
};

static_assert(sizeof(CastExpr) == sizeof(Expr));

#endif
} // namespace mx
