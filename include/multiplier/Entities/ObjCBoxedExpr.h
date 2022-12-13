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
class Expr;
class ObjCBoxedExpr;
class ObjCMethodDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCBoxedExprRange = DerivedEntityRange<StmtIterator, ObjCBoxedExpr>;
using ObjCBoxedExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBoxedExpr>;
using ObjCBoxedExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCBoxedExpr>;

class ObjCBoxedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCBoxedExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBoxedExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCBoxedExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BOXED_EXPR;
  }

  static ObjCBoxedExprContainingStmtRange containing(const Decl &decl);
  static ObjCBoxedExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCBoxedExpr> from(const TokenContext &c);
  static std::optional<ObjCBoxedExpr> from(const Expr &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoxedExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoxedExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  ObjCMethodDecl boxing_method(void) const;
  Expr sub_expression(void) const;
  bool is_expressible_as_constant_initializer(void) const;
};

static_assert(sizeof(ObjCBoxedExpr) == sizeof(Expr));

#endif
} // namespace mx
