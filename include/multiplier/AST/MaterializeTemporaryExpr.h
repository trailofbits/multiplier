// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/StorageDuration.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class LifetimeExtendedTemporaryDecl;
class MaterializeTemporaryExpr;
class Stmt;
class Token;
class ValueDecl;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MaterializeTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MaterializeTemporaryExpr> in(const Index &index);
  static gap::generator<MaterializeTemporaryExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MaterializeTemporaryExpr> by_id(const Index &, EntityId);
  static gap::generator<MaterializeTemporaryExpr> in(const Fragment &frag);
  static gap::generator<MaterializeTemporaryExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MATERIALIZE_TEMPORARY_EXPR;
  }

  static gap::generator<MaterializeTemporaryExpr> containing(const Decl &decl);
  static gap::generator<MaterializeTemporaryExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MaterializeTemporaryExpr> containing(const Stmt &stmt);
  static gap::generator<MaterializeTemporaryExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MaterializeTemporaryExpr> from_base(const Stmt &parent);
  inline static std::optional<MaterializeTemporaryExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<MaterializeTemporaryExpr> from(const std::optional<Stmt> &parent);
  static std::optional<MaterializeTemporaryExpr> from(const Reference &r);
  static std::optional<MaterializeTemporaryExpr> from(const VariantEntity &e);
  static std::optional<MaterializeTemporaryExpr> from(const TokenContext &t);

  std::optional<ValueDecl> extending_declaration(void) const;
  std::optional<LifetimeExtendedTemporaryDecl> lifetime_extended_temporary_declaration(void) const;
  StorageDuration storage_duration(void) const;
  Expr sub_expression(void) const;
  bool is_bound_to_lvalue_reference(void) const;
  bool is_usable_in_constant_expressions(void) const;
};

static_assert(sizeof(MaterializeTemporaryExpr) == sizeof(Expr));

#endif
} // namespace mx
