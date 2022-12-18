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
class CXXThisExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXThisExprRange = DerivedEntityRange<StmtIterator, CXXThisExpr>;
using CXXThisExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXThisExpr>;
using CXXThisExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXThisExpr>;

class CXXThisExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXThisExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXThisExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXThisExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_THIS_EXPR;
  }

  static CXXThisExprContainingStmtRange containing(const Decl &decl);
  static CXXThisExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXThisExpr> from(const TokenContext &c);
  static std::optional<CXXThisExpr> from(const Expr &parent);

  inline static std::optional<CXXThisExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXThisExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThisExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXThisExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXThisExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXThisExpr> from(const Stmt &parent);

  inline static std::optional<CXXThisExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXThisExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
  bool is_implicit(void) const;
};

static_assert(sizeof(CXXThisExpr) == sizeof(Expr));

#endif
} // namespace mx
