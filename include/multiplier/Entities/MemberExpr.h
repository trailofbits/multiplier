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
#include "NonOdrUseReason.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class MemberExpr;
class Stmt;
class ValueDecl;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MemberExprRange = DerivedEntityRange<StmtIterator, MemberExpr>;
using MemberExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MemberExpr>;
using MemberExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MemberExpr>;

class MemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MemberExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MemberExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MemberExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MEMBER_EXPR;
  }

  static MemberExprContainingStmtRange containing(const Decl &decl);
  static MemberExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MemberExpr> from(const TokenContext &c);
  static std::optional<MemberExpr> from(const Expr &parent);

  inline static std::optional<MemberExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return MemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MemberExpr> from(const ValueStmt &parent);

  inline static std::optional<MemberExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return MemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MemberExpr> from(const Stmt &parent);

  inline static std::optional<MemberExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token l_angle_token(void) const;
  ValueDecl member_declaration(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool had_multiple_candidates(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_qualifier(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
  NonOdrUseReason is_non_odr_use(void) const;
};

static_assert(sizeof(MemberExpr) == sizeof(Expr));

#endif
} // namespace mx
