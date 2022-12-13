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
class ObjCBoolLiteralExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCBoolLiteralExprRange = DerivedEntityRange<StmtIterator, ObjCBoolLiteralExpr>;
using ObjCBoolLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBoolLiteralExpr>;
using ObjCBoolLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCBoolLiteralExpr>;

class ObjCBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCBoolLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBoolLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCBoolLiteralExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BOOL_LITERAL_EXPR;
  }

  static ObjCBoolLiteralExprContainingStmtRange containing(const Decl &decl);
  static ObjCBoolLiteralExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCBoolLiteralExpr> from(const TokenContext &c);
  static std::optional<ObjCBoolLiteralExpr> from(const Expr &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoolLiteralExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoolLiteralExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
  bool value(void) const;
};

static_assert(sizeof(ObjCBoolLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
