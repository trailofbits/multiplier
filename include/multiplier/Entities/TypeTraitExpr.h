// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"
#include "TypeTrait.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class TypeTraitExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<TypeTraitExpr> in(const Fragment &frag);
  static gap::generator<TypeTraitExpr> in(const File &file);
  static gap::generator<TypeTraitExpr> in(const Index &index);
  static gap::generator<TypeTraitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeTraitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPE_TRAIT_EXPR;
  }

  static gap::generator<TypeTraitExpr> containing(const Decl &decl);
  static gap::generator<TypeTraitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeTraitExpr> containing(const Stmt &stmt);
  static gap::generator<TypeTraitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTraitExpr> from(const Reference &r);
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
