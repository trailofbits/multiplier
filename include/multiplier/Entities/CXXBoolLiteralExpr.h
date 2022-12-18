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
class CXXBoolLiteralExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXBoolLiteralExprRange = DerivedEntityRange<StmtIterator, CXXBoolLiteralExpr>;
using CXXBoolLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXBoolLiteralExpr>;
using CXXBoolLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXBoolLiteralExpr>;

class CXXBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXBoolLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXBoolLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXBoolLiteralExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BOOL_LITERAL_EXPR;
  }

  static CXXBoolLiteralExprContainingStmtRange containing(const Decl &decl);
  static CXXBoolLiteralExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXBoolLiteralExpr> from(const TokenContext &c);
  static std::optional<CXXBoolLiteralExpr> from(const Expr &parent);

  inline static std::optional<CXXBoolLiteralExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBoolLiteralExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXBoolLiteralExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXBoolLiteralExpr> from(const Stmt &parent);

  inline static std::optional<CXXBoolLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
  bool value(void) const;
};

static_assert(sizeof(CXXBoolLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
