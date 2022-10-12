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
class CXXDeleteExpr;
class Expr;
class FunctionDecl;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXDeleteExprRange = DerivedEntityRange<StmtIterator, CXXDeleteExpr>;
using CXXDeleteExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDeleteExpr>;
using CXXDeleteExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDeleteExpr>;

class CXXDeleteExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDeleteExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDeleteExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXDeleteExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DELETE_EXPR;
  }

  static CXXDeleteExprContainingStmtRange containing(const Decl &decl);
  static CXXDeleteExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDeleteExpr> from(const TokenContext &c);
  static std::optional<CXXDeleteExpr> from(const Expr &parent);

  inline static std::optional<CXXDeleteExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXDeleteExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeleteExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXDeleteExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXDeleteExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeleteExpr> from(const Stmt &parent);

  inline static std::optional<CXXDeleteExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDeleteExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool does_usual_array_delete_want_size(void) const;
  Expr argument(void) const;
  Type destroyed_type(void) const;
  FunctionDecl operator_delete(void) const;
  bool is_array_form(void) const;
  bool is_array_form_as_written(void) const;
  bool is_global_delete(void) const;
};

static_assert(sizeof(CXXDeleteExpr) == sizeof(Expr));

#endif
} // namespace mx
