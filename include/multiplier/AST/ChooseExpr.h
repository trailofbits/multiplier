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
class ChooseExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ChooseExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ChooseExpr> in(const Index &index);
  static gap::generator<ChooseExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ChooseExpr> by_id(const Index &, EntityId);
  static gap::generator<ChooseExpr> in(const Fragment &frag);
  static gap::generator<ChooseExpr> in(const File &file);

  static std::optional<ChooseExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ChooseExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CHOOSE_EXPR;
  }

  static gap::generator<ChooseExpr> containing(const Decl &decl);
  static gap::generator<ChooseExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ChooseExpr> containing(const Stmt &stmt);
  static gap::generator<ChooseExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ChooseExpr> from_base(const Stmt &parent);
  inline static std::optional<ChooseExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ChooseExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ChooseExpr> from(const Reference &r);
  static std::optional<ChooseExpr> from(const VariantEntity &e);
  static std::optional<ChooseExpr> from(const TokenContext &t);

  Token builtin_token(void) const;
  Expr chosen_sub_expression(void) const;
  Expr condition(void) const;
  Expr lhs(void) const;
  Expr rhs(void) const;
  Token r_paren_token(void) const;
  bool is_condition_dependent(void) const;
  bool is_condition_true(void) const;
};

static_assert(sizeof(ChooseExpr) == sizeof(Expr));

#endif
} // namespace mx
