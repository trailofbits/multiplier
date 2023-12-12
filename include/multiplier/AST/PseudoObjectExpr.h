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
class PseudoObjectExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PseudoObjectExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<PseudoObjectExpr> in(const Index &index);
  static gap::generator<PseudoObjectExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PseudoObjectExpr> by_id(const Index &, EntityId);
  static gap::generator<PseudoObjectExpr> in(const Fragment &frag);
  static gap::generator<PseudoObjectExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<PseudoObjectExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<PseudoObjectExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PSEUDO_OBJECT_EXPR;
  }

  static gap::generator<PseudoObjectExpr> containing(const Decl &decl);
  static gap::generator<PseudoObjectExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<PseudoObjectExpr> containing(const Stmt &stmt);
  static gap::generator<PseudoObjectExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PseudoObjectExpr> from_base(const Stmt &parent);
  inline static std::optional<PseudoObjectExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<PseudoObjectExpr> from(const std::optional<Stmt> &parent);
  static std::optional<PseudoObjectExpr> from(const Reference &r);
  static std::optional<PseudoObjectExpr> from(const VariantEntity &e);
  static std::optional<PseudoObjectExpr> from(const TokenContext &t);

  Expr result_expression(void) const;
  Expr syntactic_form(void) const;
  std::optional<Expr> nth_semantic(unsigned n) const;
  unsigned num_semantics(void) const;
  gap::generator<Expr> semantics(void) const &;
  std::optional<Expr> nth_semantic_expression(unsigned n) const;
  unsigned num_semantic_expressions(void) const;
  gap::generator<Expr> semantic_expressions(void) const &;
};

static_assert(sizeof(PseudoObjectExpr) == sizeof(Expr));

#endif
} // namespace mx
