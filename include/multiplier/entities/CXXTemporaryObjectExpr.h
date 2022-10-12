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

#include "CXXConstructExpr.h"
#include "StmtKind.h"

namespace mx {
class CXXConstructExpr;
class CXXTemporaryObjectExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXTemporaryObjectExprRange = DerivedEntityRange<StmtIterator, CXXTemporaryObjectExpr>;
using CXXTemporaryObjectExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTemporaryObjectExpr>;
using CXXTemporaryObjectExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTemporaryObjectExpr>;

class CXXTemporaryObjectExpr : public CXXConstructExpr {
 private:
  friend class FragmentImpl;
  friend class CXXConstructExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXTemporaryObjectExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTemporaryObjectExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXTemporaryObjectExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TEMPORARY_OBJECT_EXPR;
  }

  static CXXTemporaryObjectExprContainingStmtRange containing(const Decl &decl);
  static CXXTemporaryObjectExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXTemporaryObjectExpr> from(const TokenContext &c);
  static std::optional<CXXTemporaryObjectExpr> from(const CXXConstructExpr &parent);

  inline static std::optional<CXXTemporaryObjectExpr> from(const std::optional<CXXConstructExpr> &parent) {
    if (parent) {
      return CXXTemporaryObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTemporaryObjectExpr> from(const Expr &parent);

  inline static std::optional<CXXTemporaryObjectExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXTemporaryObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTemporaryObjectExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXTemporaryObjectExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXTemporaryObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTemporaryObjectExpr> from(const Stmt &parent);

  inline static std::optional<CXXTemporaryObjectExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTemporaryObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CXXTemporaryObjectExpr) == sizeof(CXXConstructExpr));

#endif
} // namespace mx
