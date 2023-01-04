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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"
#include "TypeTrait.h"

namespace mx {
class Expr;
class Stmt;
class Type;
class TypeTraitExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeTraitExprRange = DerivedEntityRange<StmtIterator, TypeTraitExpr>;
using TypeTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeTraitExpr>;
using TypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, TypeTraitExpr>;

class TypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static TypeTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeTraitExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPE_TRAIT_EXPR;
  }

  static TypeTraitExprContainingStmtRange containing(const Decl &decl);
  static TypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeTraitExpr> from(const TokenContext &c);
  static std::optional<TypeTraitExpr> from(const Expr &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTraitExpr> from(const ValueStmt &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<TypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return TypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TypeTrait trait(void) const;
  std::optional<bool> value(void) const;
  std::vector<Type> arguments(void) const;
};

static_assert(sizeof(TypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
