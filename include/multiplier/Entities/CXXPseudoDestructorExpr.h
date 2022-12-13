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
#include "TypeUseSelector.h"

namespace mx {
class CXXPseudoDestructorExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXPseudoDestructorExprRange = DerivedEntityRange<StmtIterator, CXXPseudoDestructorExpr>;
using CXXPseudoDestructorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXPseudoDestructorExpr>;
using CXXPseudoDestructorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXPseudoDestructorExpr>;

class CXXPseudoDestructorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXPseudoDestructorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXPseudoDestructorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXPseudoDestructorExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
  }

  static CXXPseudoDestructorExprContainingStmtRange containing(const Decl &decl);
  static CXXPseudoDestructorExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXPseudoDestructorExpr> from(const TokenContext &c);
  static std::optional<CXXPseudoDestructorExpr> from(const Expr &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXPseudoDestructorExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXPseudoDestructorExpr> from(const Stmt &parent);

  inline static std::optional<CXXPseudoDestructorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXPseudoDestructorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token colon_colon_token(void) const;
  Type destroyed_type(void) const;
  Token destroyed_type_token(void) const;
  Token operator_token(void) const;
  std::optional<Type> scope_type(void) const;
  Token tilde_token(void) const;
  bool has_qualifier(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(CXXPseudoDestructorExpr) == sizeof(Expr));

#endif
} // namespace mx
