// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class FieldDecl;
class InitListExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InitListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<InitListExpr> in(const Fragment &frag);
  static gap::generator<InitListExpr> in(const File &file);
  static gap::generator<InitListExpr> in(const Index &index);
  static gap::generator<InitListExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InitListExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INIT_LIST_EXPR;
  }

  static gap::generator<InitListExpr> containing(const Decl &decl);
  static gap::generator<InitListExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<InitListExpr> containing(const Stmt &stmt);
  static gap::generator<InitListExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<InitListExpr> from(const Stmt &parent);

  inline static std::optional<InitListExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return InitListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<InitListExpr> from(const Reference &r);
  static std::optional<InitListExpr> from(const TokenContext &t);

  std::optional<Expr> array_filler(void) const;
  std::optional<FieldDecl> initialized_field_in_union(void) const;
  Token l_brace_token(void) const;
  Token r_brace_token(void) const;
  std::optional<InitListExpr> semantic_form(void) const;
  std::optional<InitListExpr> syntactic_form(void) const;
  bool had_array_range_designator(void) const;
  bool has_array_filler(void) const;
  std::optional<Expr> nth_initializer(unsigned n) const;
  unsigned num_initializers(void) const;
  gap::generator<Expr> initializers(void) const &;
  bool is_explicit(void) const;
  bool is_semantic_form(void) const;
  bool is_string_literal_initializer(void) const;
  bool is_syntactic_form(void) const;
  std::optional<bool> is_transparent(void) const;
};

static_assert(sizeof(InitListExpr) == sizeof(Expr));

#endif
} // namespace mx
