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

#include "CXXConstructExprConstructionKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXConstructorDecl;
class CXXInheritedCtorInitExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXInheritedCtorInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXInheritedCtorInitExpr>;
using CXXInheritedCtorInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXInheritedCtorInitExpr>;

class CXXInheritedCtorInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CXXInheritedCtorInitExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static CXXInheritedCtorInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXInheritedCtorInitExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_INHERITED_CTOR_INIT_EXPR;
  }

  static CXXInheritedCtorInitExprContainingStmtRange containing(const Decl &decl);
  static CXXInheritedCtorInitExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXInheritedCtorInitExpr> from(const TokenContext &c);
  static std::optional<CXXInheritedCtorInitExpr> from(const Expr &parent);

  inline static std::optional<CXXInheritedCtorInitExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXInheritedCtorInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXInheritedCtorInitExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXInheritedCtorInitExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXInheritedCtorInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXInheritedCtorInitExpr> from(const Stmt &parent);

  inline static std::optional<CXXInheritedCtorInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXInheritedCtorInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool constructs_virtual_base(void) const;
  CXXConstructExprConstructionKind construction_kind(void) const;
  CXXConstructorDecl constructor(void) const;
  Token token(void) const;
  bool inherited_from_virtual_base(void) const;
};

static_assert(sizeof(CXXInheritedCtorInitExpr) == sizeof(Expr));

#endif
} // namespace mx
