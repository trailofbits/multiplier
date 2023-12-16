// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/TypeTrait.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class TypeTraitExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<TypeTraitExpr> in(const Index &index);
  static gap::generator<TypeTraitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeTraitExpr> by_id(const Index &, EntityId);
  static gap::generator<TypeTraitExpr> in(const Fragment &frag);
  static gap::generator<TypeTraitExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<TypeTraitExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<TypeTraitExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPE_TRAIT_EXPR;
  }

  static gap::generator<TypeTraitExpr> containing(const Decl &decl);
  static gap::generator<TypeTraitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeTraitExpr> containing(const Stmt &stmt);
  static gap::generator<TypeTraitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeTraitExpr> from_base(const Stmt &parent);
  inline static std::optional<TypeTraitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<TypeTraitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<TypeTraitExpr> from(const Reference &r);
  static std::optional<TypeTraitExpr> from(const VariantEntity &e);
  static std::optional<TypeTraitExpr> from(const TokenContext &t);

  TypeTrait trait(void) const;
  std::optional<bool> value(void) const;
  std::optional<Type> nth_argument(unsigned n) const;
  unsigned num_arguments(void) const;
  gap::generator<Type> arguments(void) const &;
};

static_assert(sizeof(TypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
