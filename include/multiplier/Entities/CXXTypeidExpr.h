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
#include "StmtUseSelector.h"

namespace mx {
class CXXTypeidExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXTypeidExprRange = DerivedEntityRange<StmtIterator, CXXTypeidExpr>;
using CXXTypeidExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTypeidExpr>;
using CXXTypeidExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTypeidExpr>;

class CXXTypeidExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXTypeidExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTypeidExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXTypeidExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TYPEID_EXPR;
  }

  static CXXTypeidExprContainingStmtRange containing(const Decl &decl);
  static CXXTypeidExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXTypeidExpr> from(const TokenContext &c);
  static std::optional<CXXTypeidExpr> from(const Expr &parent);

  inline static std::optional<CXXTypeidExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXTypeidExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTypeidExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXTypeidExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXTypeidExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTypeidExpr> from(const Stmt &parent);

  inline static std::optional<CXXTypeidExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTypeidExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> expression_operand(void) const;
  Type type_operand(void) const;
  Type type_operand_source_info(void) const;
  std::optional<bool> is_most_derived(void) const;
  bool is_potentially_evaluated(void) const;
  bool is_type_operand(void) const;
};

static_assert(sizeof(CXXTypeidExpr) == sizeof(Expr));

#endif
} // namespace mx
