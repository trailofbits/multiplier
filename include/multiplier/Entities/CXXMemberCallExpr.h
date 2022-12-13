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

#include "CallExpr.h"
#include "DeclUseSelector.h"
#include "StmtKind.h"

namespace mx {
class CXXMemberCallExpr;
class CXXMethodDecl;
class CXXRecordDecl;
class CallExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXMemberCallExprRange = DerivedEntityRange<StmtIterator, CXXMemberCallExpr>;
using CXXMemberCallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXMemberCallExpr>;
using CXXMemberCallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXMemberCallExpr>;

class CXXMemberCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXMemberCallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXMemberCallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXMemberCallExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_MEMBER_CALL_EXPR;
  }

  static CXXMemberCallExprContainingStmtRange containing(const Decl &decl);
  static CXXMemberCallExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXMemberCallExpr> from(const TokenContext &c);
  static std::optional<CXXMemberCallExpr> from(const CallExpr &parent);

  inline static std::optional<CXXMemberCallExpr> from(const std::optional<CallExpr> &parent) {
    if (parent) {
      return CXXMemberCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMemberCallExpr> from(const Expr &parent);

  inline static std::optional<CXXMemberCallExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXMemberCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMemberCallExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXMemberCallExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXMemberCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXMemberCallExpr> from(const Stmt &parent);

  inline static std::optional<CXXMemberCallExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXMemberCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr implicit_object_argument(void) const;
  std::optional<CXXMethodDecl> method_declaration(void) const;
  Type object_type(void) const;
  CXXRecordDecl record_declaration(void) const;
};

static_assert(sizeof(CXXMemberCallExpr) == sizeof(CallExpr));

#endif
} // namespace mx
