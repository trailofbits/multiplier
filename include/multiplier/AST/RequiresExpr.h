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
class ParmVarDecl;
class RequiresExpr;
class RequiresExprBodyDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RequiresExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<RequiresExpr> in(const Index &index);
  static gap::generator<RequiresExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RequiresExpr> by_id(const Index &, EntityId);
  static gap::generator<RequiresExpr> in(const Fragment &frag);
  static gap::generator<RequiresExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::REQUIRES_EXPR;
  }

  static gap::generator<RequiresExpr> containing(const Decl &decl);
  static gap::generator<RequiresExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<RequiresExpr> containing(const Stmt &stmt);
  static gap::generator<RequiresExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<RequiresExpr> from_base(const Stmt &parent);
  inline static std::optional<RequiresExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<RequiresExpr> from(const std::optional<Stmt> &parent);
  static std::optional<RequiresExpr> from(const Reference &r);
  static std::optional<RequiresExpr> from(const VariantEntity &e);
  static std::optional<RequiresExpr> from(const TokenContext &t);

  RequiresExprBodyDecl body(void) const;
  std::optional<ParmVarDecl> nth_local_parameter(unsigned n) const;
  unsigned num_local_parameters(void) const;
  gap::generator<ParmVarDecl> local_parameters(void) const &;
  Token r_brace_token(void) const;
  Token requires_keyword_token(void) const;
  bool is_satisfied(void) const;
};

static_assert(sizeof(RequiresExpr) == sizeof(Expr));

#endif
} // namespace mx
