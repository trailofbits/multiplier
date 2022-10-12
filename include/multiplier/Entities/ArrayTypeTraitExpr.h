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

#include "ArrayTypeTrait.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class ArrayTypeTraitExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArrayTypeTraitExprRange = DerivedEntityRange<StmtIterator, ArrayTypeTraitExpr>;
using ArrayTypeTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayTypeTraitExpr>;
using ArrayTypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayTypeTraitExpr>;

class ArrayTypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayTypeTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayTypeTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ArrayTypeTraitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_TYPE_TRAIT_EXPR;
  }

  static ArrayTypeTraitExprContainingStmtRange containing(const Decl &decl);
  static ArrayTypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArrayTypeTraitExpr> from(const TokenContext &c);
  static std::optional<ArrayTypeTraitExpr> from(const Expr &parent);

  inline static std::optional<ArrayTypeTraitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ArrayTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayTypeTraitExpr> from(const ValueStmt &parent);

  inline static std::optional<ArrayTypeTraitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ArrayTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayTypeTraitExpr> from(const Stmt &parent);

  inline static std::optional<ArrayTypeTraitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArrayTypeTraitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr dimension_expression(void) const;
  Type queried_type(void) const;
  ArrayTypeTrait trait(void) const;
};

static_assert(sizeof(ArrayTypeTraitExpr) == sizeof(Expr));

#endif
} // namespace mx
