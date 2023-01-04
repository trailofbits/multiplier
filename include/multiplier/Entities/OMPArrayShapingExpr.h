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
class Expr;
class OMPArrayShapingExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPArrayShapingExprRange = DerivedEntityRange<StmtIterator, OMPArrayShapingExpr>;
using OMPArrayShapingExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPArrayShapingExpr>;
using OMPArrayShapingExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPArrayShapingExpr>;

class OMPArrayShapingExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OMPArrayShapingExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPArrayShapingExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPArrayShapingExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ARRAY_SHAPING_EXPR;
  }

  static OMPArrayShapingExprContainingStmtRange containing(const Decl &decl);
  static OMPArrayShapingExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPArrayShapingExpr> from(const TokenContext &c);
  static std::optional<OMPArrayShapingExpr> from(const Expr &parent);

  inline static std::optional<OMPArrayShapingExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return OMPArrayShapingExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPArrayShapingExpr> from(const ValueStmt &parent);

  inline static std::optional<OMPArrayShapingExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return OMPArrayShapingExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPArrayShapingExpr> from(const Stmt &parent);

  inline static std::optional<OMPArrayShapingExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPArrayShapingExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  std::vector<Expr> dimensions(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(OMPArrayShapingExpr) == sizeof(Expr));

#endif
} // namespace mx
