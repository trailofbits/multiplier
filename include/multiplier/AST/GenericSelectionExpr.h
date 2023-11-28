// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class GenericSelectionExpr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GenericSelectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<GenericSelectionExpr> in(const Index &index);
  static gap::generator<GenericSelectionExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<GenericSelectionExpr> by_id(const Index &, EntityId);
  static gap::generator<GenericSelectionExpr> in(const Fragment &frag);
  static gap::generator<GenericSelectionExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GENERIC_SELECTION_EXPR;
  }

  static gap::generator<GenericSelectionExpr> containing(const Decl &decl);
  static gap::generator<GenericSelectionExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<GenericSelectionExpr> containing(const Stmt &stmt);
  static gap::generator<GenericSelectionExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GenericSelectionExpr> from_base(const Stmt &parent);
  inline static std::optional<GenericSelectionExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<GenericSelectionExpr> from(const std::optional<Stmt> &parent);
  static std::optional<GenericSelectionExpr> from(const Reference &r);
  static std::optional<GenericSelectionExpr> from(const VariantEntity &e);
  static std::optional<GenericSelectionExpr> from(const TokenContext &t);

  std::optional<Expr> nth_association_expression(unsigned n) const;
  unsigned num_association_expressions(void) const;
  gap::generator<Expr> association_expressions(void) const &;
  std::optional<Expr> controlling_expression(void) const;
  std::optional<Type> controlling_type(void) const;
  Token default_token(void) const;
  Token generic_token(void) const;
  Token r_paren_token(void) const;
  std::optional<Expr> result_expression(void) const;
  bool is_expression_predicate(void) const;
  bool is_result_dependent(void) const;
  bool is_type_predicate(void) const;
};

static_assert(sizeof(GenericSelectionExpr) == sizeof(Expr));

#endif
} // namespace mx
