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
class Expr;
class NonTypeTemplateParmDecl;
class Stmt;
class SubstNonTypeTemplateParmPackExpr;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SubstNonTypeTemplateParmPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SubstNonTypeTemplateParmPackExpr> in(const Fragment &frag);
  static gap::generator<SubstNonTypeTemplateParmPackExpr> in(const File &file);
  static gap::generator<SubstNonTypeTemplateParmPackExpr> in(const Index &index);
  static gap::generator<SubstNonTypeTemplateParmPackExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SubstNonTypeTemplateParmPackExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR;
  }

  static gap::generator<SubstNonTypeTemplateParmPackExpr> containing(const Decl &decl);
  static gap::generator<SubstNonTypeTemplateParmPackExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<SubstNonTypeTemplateParmPackExpr> containing(const Stmt &stmt);
  static gap::generator<SubstNonTypeTemplateParmPackExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const Stmt &parent);

  inline static std::optional<SubstNonTypeTemplateParmPackExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SubstNonTypeTemplateParmPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const Reference &r);
  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const TokenContext &t);

  Decl associated_declaration(void) const;
  NonTypeTemplateParmDecl parameter_pack(void) const;
  Token parameter_pack_token(void) const;
};

static_assert(sizeof(SubstNonTypeTemplateParmPackExpr) == sizeof(Expr));

#endif
} // namespace mx
