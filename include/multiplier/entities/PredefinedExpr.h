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
#include "PredefinedExprIdentKind.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class PredefinedExpr;
class Stmt;
class StringLiteral;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using PredefinedExprRange = DerivedEntityRange<StmtIterator, PredefinedExpr>;
using PredefinedExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, PredefinedExpr>;
using PredefinedExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, PredefinedExpr>;

class PredefinedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static PredefinedExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PredefinedExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : PredefinedExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PREDEFINED_EXPR;
  }

  static PredefinedExprContainingStmtRange containing(const Decl &decl);
  static PredefinedExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PredefinedExpr> from(const TokenContext &c);
  static std::optional<PredefinedExpr> from(const Expr &parent);

  inline static std::optional<PredefinedExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return PredefinedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PredefinedExpr> from(const ValueStmt &parent);

  inline static std::optional<PredefinedExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return PredefinedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PredefinedExpr> from(const Stmt &parent);

  inline static std::optional<PredefinedExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return PredefinedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  StringLiteral function_name(void) const;
  PredefinedExprIdentKind identifier_kind(void) const;
  std::string_view identifier_kind_name(void) const;
  Token token(void) const;
};

static_assert(sizeof(PredefinedExpr) == sizeof(Expr));

#endif
} // namespace mx
