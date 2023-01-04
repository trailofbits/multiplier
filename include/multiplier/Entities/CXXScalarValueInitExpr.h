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
class CXXScalarValueInitExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXScalarValueInitExprRange = DerivedEntityRange<StmtIterator, CXXScalarValueInitExpr>;
using CXXScalarValueInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXScalarValueInitExpr>;
using CXXScalarValueInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXScalarValueInitExpr>;

class CXXScalarValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXScalarValueInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXScalarValueInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXScalarValueInitExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
  }

  static CXXScalarValueInitExprContainingStmtRange containing(const Decl &decl);
  static CXXScalarValueInitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXScalarValueInitExpr> from(const TokenContext &c);
  static std::optional<CXXScalarValueInitExpr> from(const Expr &parent);

  inline static std::optional<CXXScalarValueInitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXScalarValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXScalarValueInitExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXScalarValueInitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXScalarValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXScalarValueInitExpr> from(const Stmt &parent);

  inline static std::optional<CXXScalarValueInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXScalarValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token r_paren_token(void) const;
};

static_assert(sizeof(CXXScalarValueInitExpr) == sizeof(Expr));

#endif
} // namespace mx
