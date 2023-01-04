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
#include "NonOdrUseReason.h"
#include "StmtKind.h"

namespace mx {
class DeclRefExpr;
class Expr;
class NamedDecl;
class Stmt;
class ValueDecl;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DeclRefExprRange = DerivedEntityRange<StmtIterator, DeclRefExpr>;
using DeclRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclRefExpr>;
using DeclRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DeclRefExpr>;

class DeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DeclRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DeclRefExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DECL_REF_EXPR;
  }

  static DeclRefExprContainingStmtRange containing(const Decl &decl);
  static DeclRefExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclRefExpr> from(const TokenContext &c);
  static std::optional<DeclRefExpr> from(const Expr &parent);

  inline static std::optional<DeclRefExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclRefExpr> from(const ValueStmt &parent);

  inline static std::optional<DeclRefExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclRefExpr> from(const Stmt &parent);

  inline static std::optional<DeclRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ValueDecl declaration(void) const;
  NamedDecl found_declaration(void) const;
  Token l_angle_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool had_multiple_candidates(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_qualifier(void) const;
  bool has_template_keyword_and_arguments_info(void) const;
  bool has_template_keyword(void) const;
  NonOdrUseReason is_non_odr_use(void) const;
  bool refers_to_enclosing_variable_or_capture(void) const;
};

static_assert(sizeof(DeclRefExpr) == sizeof(Expr));

#endif
} // namespace mx
