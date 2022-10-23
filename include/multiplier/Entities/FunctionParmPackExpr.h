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
class FunctionParmPackExpr;
class Stmt;
class ValueStmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FunctionParmPackExprRange = DerivedEntityRange<StmtIterator, FunctionParmPackExpr>;
using FunctionParmPackExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionParmPackExpr>;
using FunctionParmPackExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FunctionParmPackExpr>;

class FunctionParmPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FunctionParmPackExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionParmPackExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : FunctionParmPackExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FUNCTION_PARM_PACK_EXPR;
  }

  static FunctionParmPackExprContainingStmtRange containing(const Decl &decl);
  static FunctionParmPackExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FunctionParmPackExpr> from(const TokenContext &c);
  static std::optional<FunctionParmPackExpr> from(const Expr &parent);

  inline static std::optional<FunctionParmPackExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return FunctionParmPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionParmPackExpr> from(const ValueStmt &parent);

  inline static std::optional<FunctionParmPackExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return FunctionParmPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionParmPackExpr> from(const Stmt &parent);

  inline static std::optional<FunctionParmPackExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FunctionParmPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  VarDecl parameter_pack(void) const;
  Token parameter_pack_token(void) const;
  std::vector<VarDecl> expansions(void) const;
};

static_assert(sizeof(FunctionParmPackExpr) == sizeof(Expr));

#endif
} // namespace mx