// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CXXNewExprInitializationStyle.h>
#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXConstructExpr;
class CXXNewExpr;
class Decl;
class Expr;
class FunctionDecl;
class Stmt;
class Token;
class TokenRange;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXNewExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXNewExpr> in(const Index &index);
  static gap::generator<CXXNewExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXNewExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXNewExpr> in(const Fragment &frag);
  static gap::generator<CXXNewExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_NEW_EXPR;
  }

  static gap::generator<CXXNewExpr> containing(const Decl &decl);
  static gap::generator<CXXNewExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXNewExpr> containing(const Stmt &stmt);
  static gap::generator<CXXNewExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXNewExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXNewExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXNewExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXNewExpr> from(const Reference &r);
  static std::optional<CXXNewExpr> from(const VariantEntity &e);
  static std::optional<CXXNewExpr> from(const TokenContext &t);

  bool does_usual_array_delete_want_size(void) const;
  Type allocated_type(void) const;
  std::optional<Expr> array_size(void) const;
  std::optional<CXXConstructExpr> construct_expression(void) const;
  TokenRange direct_initializer_range(void) const;
  CXXNewExprInitializationStyle initialization_style(void) const;
  std::optional<Expr> initializer(void) const;
  FunctionDecl operator_delete(void) const;
  FunctionDecl operator_new(void) const;
  TokenRange type_id_parentheses(void) const;
  bool has_initializer(void) const;
  bool is_array(void) const;
  bool is_global_new(void) const;
  bool is_parenthesis_type_id(void) const;
  bool pass_alignment(void) const;
  std::optional<Expr> nth_placement_argument(unsigned n) const;
  unsigned num_placement_arguments(void) const;
  gap::generator<Expr> placement_arguments(void) const &;
  bool should_null_check_allocation(void) const;
};

static_assert(sizeof(CXXNewExpr) == sizeof(Expr));

#endif
} // namespace mx
