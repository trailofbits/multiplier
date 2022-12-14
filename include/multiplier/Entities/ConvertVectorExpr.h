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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class ConvertVectorExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConvertVectorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConvertVectorExpr>;
using ConvertVectorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConvertVectorExpr>;

class ConvertVectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ConvertVectorExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ConvertVectorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConvertVectorExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONVERT_VECTOR_EXPR;
  }

  static ConvertVectorExprContainingStmtRange containing(const Decl &decl);
  static ConvertVectorExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConvertVectorExpr> from(const TokenContext &c);
  static std::optional<ConvertVectorExpr> from(const Expr &parent);

  inline static std::optional<ConvertVectorExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ConvertVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConvertVectorExpr> from(const ValueStmt &parent);

  inline static std::optional<ConvertVectorExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ConvertVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConvertVectorExpr> from(const Stmt &parent);

  inline static std::optional<ConvertVectorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ConvertVectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr src_expression(void) const;
};

static_assert(sizeof(ConvertVectorExpr) == sizeof(Expr));

#endif
} // namespace mx
