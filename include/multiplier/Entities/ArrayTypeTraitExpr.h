// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ArrayTypeTrait.h"
#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class ArrayTypeTraitExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArrayTypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ArrayTypeTraitExpr> in(const Fragment &frag);
  static gap::generator<ArrayTypeTraitExpr> in(const File &file);
  static gap::generator<ArrayTypeTraitExpr> in(const Index &index);
  static gap::generator<ArrayTypeTraitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArrayTypeTraitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_TYPE_TRAIT_EXPR;
  }

  static gap::generator<ArrayTypeTraitExpr> containing(const Decl &decl);
  static gap::generator<ArrayTypeTraitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ArrayTypeTraitExpr> containing(const Stmt &stmt);
  static gap::generator<ArrayTypeTraitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArrayTypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<ArrayTypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArrayTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayTypeTraitExpr> from(const Reference &r);
  static std::optional<ArrayTypeTraitExpr> from(const TokenContext &t);

  Expr dimension_expression(void) const;
  Type queried_type(void) const;
  ArrayTypeTrait trait(void) const;
};

static_assert(sizeof(ArrayTypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
