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
class SubstNonTypeTemplateParmExpr;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SubstNonTypeTemplateParmExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SubstNonTypeTemplateParmExpr> in(const Index &index);
  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SubstNonTypeTemplateParmExpr> by_id(const Index &, EntityId);
  static gap::generator<SubstNonTypeTemplateParmExpr> in(const Fragment &frag);
  static gap::generator<SubstNonTypeTemplateParmExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR;
  }

  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Decl &decl);
  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Stmt &stmt);
  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SubstNonTypeTemplateParmExpr> from_base(const Stmt &parent);
  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<SubstNonTypeTemplateParmExpr> from(const std::optional<Stmt> &parent);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const Reference &r);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const VariantEntity &e);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const TokenContext &t);

  Decl associated_declaration(void) const;
  Token name_token(void) const;
  std::optional<uint32_t> pack_index(void) const;
  NonTypeTemplateParmDecl parameter(void) const;
  Type parameter_type(void) const;
  Expr replacement(void) const;
  bool is_reference_parameter(void) const;
};

static_assert(sizeof(SubstNonTypeTemplateParmExpr) == sizeof(Expr));

#endif
} // namespace mx
