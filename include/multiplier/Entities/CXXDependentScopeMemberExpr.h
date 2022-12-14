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

#include "DeclUseSelector.h"
#include "Expr.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class CXXDependentScopeMemberExpr;
class Expr;
class NamedDecl;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXDependentScopeMemberExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDependentScopeMemberExpr>;

class CXXDependentScopeMemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CXXDependentScopeMemberExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXDependentScopeMemberExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXDependentScopeMemberExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR;
  }

  static CXXDependentScopeMemberExprContainingStmtRange containing(const Decl &decl);
  static CXXDependentScopeMemberExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDependentScopeMemberExpr> from(const TokenContext &c);
  static std::optional<CXXDependentScopeMemberExpr> from(const Expr &parent);

  inline static std::optional<CXXDependentScopeMemberExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXDependentScopeMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDependentScopeMemberExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXDependentScopeMemberExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXDependentScopeMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDependentScopeMemberExpr> from(const Stmt &parent);

  inline static std::optional<CXXDependentScopeMemberExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDependentScopeMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> base(void) const;
  Type base_type(void) const;
  std::optional<NamedDecl> first_qualifier_found_in_scope(void) const;
  Token l_angle_token(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

static_assert(sizeof(CXXDependentScopeMemberExpr) == sizeof(Expr));

#endif
} // namespace mx
