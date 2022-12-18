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

namespace mx {
class ArrayInitIndexExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArrayInitIndexExprRange = DerivedEntityRange<StmtIterator, ArrayInitIndexExpr>;
using ArrayInitIndexExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayInitIndexExpr>;
using ArrayInitIndexExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayInitIndexExpr>;

class ArrayInitIndexExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayInitIndexExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayInitIndexExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ArrayInitIndexExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ARRAY_INIT_INDEX_EXPR;
  }

  static ArrayInitIndexExprContainingStmtRange containing(const Decl &decl);
  static ArrayInitIndexExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ArrayInitIndexExpr> from(const TokenContext &c);
  static std::optional<ArrayInitIndexExpr> from(const Expr &parent);

  inline static std::optional<ArrayInitIndexExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ArrayInitIndexExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayInitIndexExpr> from(const ValueStmt &parent);

  inline static std::optional<ArrayInitIndexExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ArrayInitIndexExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayInitIndexExpr> from(const Stmt &parent);

  inline static std::optional<ArrayInitIndexExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ArrayInitIndexExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ArrayInitIndexExpr) == sizeof(Expr));

#endif
} // namespace mx
