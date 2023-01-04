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
class OMPArraySectionExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPArraySectionExprRange = DerivedEntityRange<StmtIterator, OMPArraySectionExpr>;
using OMPArraySectionExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPArraySectionExpr>;
using OMPArraySectionExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPArraySectionExpr>;

class OMPArraySectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OMPArraySectionExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPArraySectionExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPArraySectionExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ARRAY_SECTION_EXPR;
  }

  static OMPArraySectionExprContainingStmtRange containing(const Decl &decl);
  static OMPArraySectionExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPArraySectionExpr> from(const TokenContext &c);
  static std::optional<OMPArraySectionExpr> from(const Expr &parent);

  inline static std::optional<OMPArraySectionExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return OMPArraySectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPArraySectionExpr> from(const ValueStmt &parent);

  inline static std::optional<OMPArraySectionExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return OMPArraySectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPArraySectionExpr> from(const Stmt &parent);

  inline static std::optional<OMPArraySectionExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPArraySectionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token first_colon_token(void) const;
  Token second_colon_token(void) const;
  Expr length(void) const;
  Expr lower_bound(void) const;
  Token r_bracket_token(void) const;
  Expr stride(void) const;
};

static_assert(sizeof(OMPArraySectionExpr) == sizeof(Expr));

#endif
} // namespace mx
