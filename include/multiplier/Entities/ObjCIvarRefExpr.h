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
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCIvarRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIvarRefExpr>;
using ObjCIvarRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIvarRefExpr>;

class ObjCIvarRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCIvarRefExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCIvarRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCIvarRefExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_IVAR_REF_EXPR;
  }

  static ObjCIvarRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCIvarRefExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIvarRefExpr> from(const TokenContext &c);
  static std::optional<ObjCIvarRefExpr> from(const Expr &parent);

  inline static std::optional<ObjCIvarRefExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCIvarRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarRefExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCIvarRefExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCIvarRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIvarRefExpr> from(const Stmt &parent);

  inline static std::optional<ObjCIvarRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCIvarRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  ObjCIvarDecl declaration(void) const;
  Token token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
  bool is_free_instance_variable(void) const;
};

static_assert(sizeof(ObjCIvarRefExpr) == sizeof(Expr));

#endif
} // namespace mx
