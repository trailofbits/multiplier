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

#include "DeclUseSelector.h"
#include "Expr.h"
#include "StmtKind.h"
#include "StorageDuration.h"

namespace mx {
class Expr;
class LifetimeExtendedTemporaryDecl;
class MaterializeTemporaryExpr;
class Stmt;
class ValueDecl;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MaterializeTemporaryExprRange = DerivedEntityRange<StmtIterator, MaterializeTemporaryExpr>;
using MaterializeTemporaryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MaterializeTemporaryExpr>;
using MaterializeTemporaryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MaterializeTemporaryExpr>;

class MaterializeTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MaterializeTemporaryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MaterializeTemporaryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MaterializeTemporaryExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MATERIALIZE_TEMPORARY_EXPR;
  }

  static MaterializeTemporaryExprContainingStmtRange containing(const Decl &decl);
  static MaterializeTemporaryExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MaterializeTemporaryExpr> from(const TokenContext &c);
  static std::optional<MaterializeTemporaryExpr> from(const Expr &parent);

  inline static std::optional<MaterializeTemporaryExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return MaterializeTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MaterializeTemporaryExpr> from(const ValueStmt &parent);

  inline static std::optional<MaterializeTemporaryExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return MaterializeTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MaterializeTemporaryExpr> from(const Stmt &parent);

  inline static std::optional<MaterializeTemporaryExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MaterializeTemporaryExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<ValueDecl> extending_declaration(void) const;
  std::optional<LifetimeExtendedTemporaryDecl> lifetime_extended_temporary_declaration(void) const;
  StorageDuration storage_duration(void) const;
  Expr sub_expression(void) const;
  bool is_bound_to_lvalue_reference(void) const;
  bool is_usable_in_constant_expressions(void) const;
};

static_assert(sizeof(MaterializeTemporaryExpr) == sizeof(Expr));

#endif
} // namespace mx
