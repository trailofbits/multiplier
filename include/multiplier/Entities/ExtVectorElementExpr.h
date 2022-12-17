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
class ExtVectorElementExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ExtVectorElementExprRange = DerivedEntityRange<StmtIterator, ExtVectorElementExpr>;
using ExtVectorElementExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExtVectorElementExpr>;
using ExtVectorElementExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExtVectorElementExpr>;

class ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExtVectorElementExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExtVectorElementExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ExtVectorElementExpr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
  }

  static ExtVectorElementExprContainingStmtRange containing(const Decl &decl);
  static ExtVectorElementExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExtVectorElementExpr> from(const TokenContext &c);
  static std::optional<ExtVectorElementExpr> from(const Expr &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const ValueStmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const Stmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

#endif
} // namespace mx
