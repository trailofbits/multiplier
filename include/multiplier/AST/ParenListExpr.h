// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class ParenListExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ParenListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ParenListExpr> in(const Index &index);
  static gap::generator<ParenListExpr> in(const Fragment &frag);
  static gap::generator<ParenListExpr> in(const File &file);
  static gap::generator<ParenListExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ParenListExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ParenListExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PAREN_LIST_EXPR;
  }

  static gap::generator<ParenListExpr> containing(const Decl &decl);
  static gap::generator<ParenListExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ParenListExpr> containing(const Stmt &stmt);
  static gap::generator<ParenListExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ParenListExpr> by_id(const Index &, EntityId);

  static std::optional<ParenListExpr> from_base(const Stmt &parent);
  inline static std::optional<ParenListExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ParenListExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ParenListExpr> from(const Reference &r);
  static std::optional<ParenListExpr> from(const VariantEntity &e);
  static std::optional<ParenListExpr> from(const TokenContext &t);

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  std::optional<Expr> nth_expression(unsigned n) const;
  unsigned num_expressions(void) const;
  gap::generator<Expr> expressions(void) const &;
};

static_assert(sizeof(ParenListExpr) == sizeof(Expr));

#endif
} // namespace mx
