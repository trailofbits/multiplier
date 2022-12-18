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
class Stmt;
class Type;
class VAArgExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VAArgExprRange = DerivedEntityRange<StmtIterator, VAArgExpr>;
using VAArgExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, VAArgExpr>;
using VAArgExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, VAArgExpr>;

class VAArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static VAArgExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VAArgExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : VAArgExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::VA_ARG_EXPR;
  }

  static VAArgExprContainingStmtRange containing(const Decl &decl);
  static VAArgExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VAArgExpr> from(const TokenContext &c);
  static std::optional<VAArgExpr> from(const Expr &parent);

  inline static std::optional<VAArgExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return VAArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VAArgExpr> from(const ValueStmt &parent);

  inline static std::optional<VAArgExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return VAArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VAArgExpr> from(const Stmt &parent);

  inline static std::optional<VAArgExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return VAArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr sub_expression(void) const;
  Type written_type(void) const;
  bool is_microsoft_abi(void) const;
};

static_assert(sizeof(VAArgExpr) == sizeof(Expr));

#endif
} // namespace mx
