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
class ObjCMethodDecl;
class ObjCSubscriptRefExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCSubscriptRefExprRange = DerivedEntityRange<StmtIterator, ObjCSubscriptRefExpr>;
using ObjCSubscriptRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCSubscriptRefExpr>;
using ObjCSubscriptRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCSubscriptRefExpr>;

class ObjCSubscriptRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCSubscriptRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCSubscriptRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCSubscriptRefExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR;
  }

  static ObjCSubscriptRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCSubscriptRefExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCSubscriptRefExpr> from(const TokenContext &c);
  static std::optional<ObjCSubscriptRefExpr> from(const Expr &parent);

  inline static std::optional<ObjCSubscriptRefExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCSubscriptRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCSubscriptRefExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCSubscriptRefExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCSubscriptRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCSubscriptRefExpr> from(const Stmt &parent);

  inline static std::optional<ObjCSubscriptRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCSubscriptRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCMethodDecl at_index_method_declaration(void) const;
  Expr base_expression(void) const;
  Expr key_expression(void) const;
  Token r_bracket_token(void) const;
  bool is_array_subscript_reference_expression(void) const;
};

static_assert(sizeof(ObjCSubscriptRefExpr) == sizeof(Expr));

#endif
} // namespace mx
