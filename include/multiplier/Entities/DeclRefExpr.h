// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"
#include "NonOdrUseReason.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DeclRefExpr;
class Expr;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<DeclRefExpr> in(const Fragment &frag);
  static gap::generator<DeclRefExpr> in(const File &file);
  static gap::generator<DeclRefExpr> in(const Index &index);
  static gap::generator<DeclRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeclRefExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DECL_REF_EXPR;
  }

  static gap::generator<DeclRefExpr> containing(const Decl &decl);
  static gap::generator<DeclRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<DeclRefExpr> containing(const Stmt &stmt);
  static gap::generator<DeclRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclRefExpr> from(const Stmt &parent);

  inline static std::optional<DeclRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DeclRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclRefExpr> from(const Reference &r);
  static std::optional<DeclRefExpr> from(const TokenContext &t);

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
