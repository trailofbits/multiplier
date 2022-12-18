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
class ParmVarDecl;
class RequiresExpr;
class RequiresExprBodyDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RequiresExprRange = DerivedEntityRange<StmtIterator, RequiresExpr>;
using RequiresExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, RequiresExpr>;
using RequiresExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, RequiresExpr>;

class RequiresExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static RequiresExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RequiresExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : RequiresExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::REQUIRES_EXPR;
  }

  static RequiresExprContainingStmtRange containing(const Decl &decl);
  static RequiresExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RequiresExpr> from(const TokenContext &c);
  static std::optional<RequiresExpr> from(const Expr &parent);

  inline static std::optional<RequiresExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return RequiresExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RequiresExpr> from(const ValueStmt &parent);

  inline static std::optional<RequiresExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return RequiresExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RequiresExpr> from(const Stmt &parent);

  inline static std::optional<RequiresExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return RequiresExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  RequiresExprBodyDecl body(void) const;
  std::vector<ParmVarDecl> local_parameters(void) const;
  Token r_brace_token(void) const;
  Token requires_keyword_token(void) const;
  bool is_satisfied(void) const;
};

static_assert(sizeof(RequiresExpr) == sizeof(Expr));

#endif
} // namespace mx
