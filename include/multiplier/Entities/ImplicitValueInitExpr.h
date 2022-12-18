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
class ImplicitValueInitExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ImplicitValueInitExprRange = DerivedEntityRange<StmtIterator, ImplicitValueInitExpr>;
using ImplicitValueInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImplicitValueInitExpr>;
using ImplicitValueInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ImplicitValueInitExpr>;

class ImplicitValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ImplicitValueInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImplicitValueInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ImplicitValueInitExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IMPLICIT_VALUE_INIT_EXPR;
  }

  static ImplicitValueInitExprContainingStmtRange containing(const Decl &decl);
  static ImplicitValueInitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ImplicitValueInitExpr> from(const TokenContext &c);
  static std::optional<ImplicitValueInitExpr> from(const Expr &parent);

  inline static std::optional<ImplicitValueInitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ImplicitValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImplicitValueInitExpr> from(const ValueStmt &parent);

  inline static std::optional<ImplicitValueInitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ImplicitValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImplicitValueInitExpr> from(const Stmt &parent);

  inline static std::optional<ImplicitValueInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ImplicitValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ImplicitValueInitExpr) == sizeof(Expr));

#endif
} // namespace mx
