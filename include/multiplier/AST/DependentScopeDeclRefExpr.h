// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DependentScopeDeclRefExpr;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentScopeDeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<DependentScopeDeclRefExpr> in(const Index &index);
  static gap::generator<DependentScopeDeclRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentScopeDeclRefExpr> by_id(const Index &, EntityId);
  static gap::generator<DependentScopeDeclRefExpr> in(const Fragment &frag);
  static gap::generator<DependentScopeDeclRefExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR;
  }

  static gap::generator<DependentScopeDeclRefExpr> containing(const Decl &decl);
  static gap::generator<DependentScopeDeclRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<DependentScopeDeclRefExpr> containing(const Stmt &stmt);
  static gap::generator<DependentScopeDeclRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DependentScopeDeclRefExpr> from_base(const Stmt &parent);
  inline static std::optional<DependentScopeDeclRefExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<DependentScopeDeclRefExpr> from(const std::optional<Stmt> &parent);
  static std::optional<DependentScopeDeclRefExpr> from(const Reference &r);
  static std::optional<DependentScopeDeclRefExpr> from(const VariantEntity &e);
  static std::optional<DependentScopeDeclRefExpr> from(const TokenContext &t);

  Token l_angle_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

static_assert(sizeof(DependentScopeDeclRefExpr) == sizeof(Expr));

#endif
} // namespace mx
