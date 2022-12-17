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
class RecoveryExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RecoveryExprRange = DerivedEntityRange<StmtIterator, RecoveryExpr>;
using RecoveryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, RecoveryExpr>;
using RecoveryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, RecoveryExpr>;

class RecoveryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static RecoveryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RecoveryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : RecoveryExpr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::RECOVERY_EXPR;
  }

  static RecoveryExprContainingStmtRange containing(const Decl &decl);
  static RecoveryExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RecoveryExpr> from(const TokenContext &c);
  static std::optional<RecoveryExpr> from(const Expr &parent);

  inline static std::optional<RecoveryExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return RecoveryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecoveryExpr> from(const ValueStmt &parent);

  inline static std::optional<RecoveryExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return RecoveryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecoveryExpr> from(const Stmt &parent);

  inline static std::optional<RecoveryExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return RecoveryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> sub_expressions(void) const;
};

static_assert(sizeof(RecoveryExpr) == sizeof(Expr));

#endif
} // namespace mx
