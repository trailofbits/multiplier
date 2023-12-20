// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class FieldDecl;
class InitListExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT InitListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<InitListExpr> in(const Index &index);
  static gap::generator<InitListExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InitListExpr> by_id(const Index &, EntityId);
  static gap::generator<InitListExpr> in(const Fragment &frag);
  static gap::generator<InitListExpr> in(const File &file);

  static std::optional<InitListExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<InitListExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INIT_LIST_EXPR;
  }

  static gap::generator<InitListExpr> containing(const Decl &decl);
  static gap::generator<InitListExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<InitListExpr> containing(const Stmt &stmt);
  static gap::generator<InitListExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<InitListExpr> from_base(const Stmt &parent);
  inline static std::optional<InitListExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<InitListExpr> from(const std::optional<Stmt> &parent);
  static std::optional<InitListExpr> from(const Reference &r);
  static std::optional<InitListExpr> from(const VariantEntity &e);
  static std::optional<InitListExpr> from(const TokenContext &t);

  std::optional<Expr> array_filler(void) const;
  std::optional<FieldDecl> initialized_field_in_union(void) const;
  Token l_brace_token(void) const;
  Token r_brace_token(void) const;
  std::optional<InitListExpr> semantic_form(void) const;
  std::optional<InitListExpr> syntactic_form(void) const;
  bool had_array_range_designator(void) const;
  bool has_array_filler(void) const;
  bool has_designated_initializer(void) const;
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
