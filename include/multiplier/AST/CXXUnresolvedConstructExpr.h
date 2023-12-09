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
class CXXUnresolvedConstructExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXUnresolvedConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXUnresolvedConstructExpr> in(const Index &index);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXUnresolvedConstructExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXUnresolvedConstructExpr> in(const Fragment &frag);
  static gap::generator<CXXUnresolvedConstructExpr> in(const File &file);

  static std::optional<CXXUnresolvedConstructExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CXXUnresolvedConstructExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
  }

  static gap::generator<CXXUnresolvedConstructExpr> containing(const Decl &decl);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXUnresolvedConstructExpr> containing(const Stmt &stmt);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXUnresolvedConstructExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXUnresolvedConstructExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXUnresolvedConstructExpr> from(const Reference &r);
  static std::optional<CXXUnresolvedConstructExpr> from(const VariantEntity &e);
  static std::optional<CXXUnresolvedConstructExpr> from(const TokenContext &t);

  std::optional<Expr> nth_argument(unsigned n) const;
  unsigned num_arguments(void) const;
  gap::generator<Expr> arguments(void) const &;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Type type_as_written(void) const;
  bool is_list_initialization(void) const;
};

static_assert(sizeof(CXXUnresolvedConstructExpr) == sizeof(Expr));

#endif
} // namespace mx
