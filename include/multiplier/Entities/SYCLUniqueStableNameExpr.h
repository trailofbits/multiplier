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
class SYCLUniqueStableNameExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SYCLUniqueStableNameExprRange = DerivedEntityRange<StmtIterator, SYCLUniqueStableNameExpr>;
using SYCLUniqueStableNameExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SYCLUniqueStableNameExpr>;
using SYCLUniqueStableNameExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SYCLUniqueStableNameExpr>;

class SYCLUniqueStableNameExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SYCLUniqueStableNameExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SYCLUniqueStableNameExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : SYCLUniqueStableNameExpr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR;
  }

  static SYCLUniqueStableNameExprContainingStmtRange containing(const Decl &decl);
  static SYCLUniqueStableNameExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SYCLUniqueStableNameExpr> from(const TokenContext &c);
  static std::optional<SYCLUniqueStableNameExpr> from(const Expr &parent);

  inline static std::optional<SYCLUniqueStableNameExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return SYCLUniqueStableNameExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SYCLUniqueStableNameExpr> from(const ValueStmt &parent);

  inline static std::optional<SYCLUniqueStableNameExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return SYCLUniqueStableNameExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SYCLUniqueStableNameExpr> from(const Stmt &parent);

  inline static std::optional<SYCLUniqueStableNameExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SYCLUniqueStableNameExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view compute_name(void) const;
  Token l_paren_token(void) const;
  Token token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(SYCLUniqueStableNameExpr) == sizeof(Expr));

#endif
} // namespace mx
