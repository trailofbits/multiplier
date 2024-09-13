// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/BinaryOperatorKind.h>
#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXFoldExpr;
class Decl;
class Expr;
class File;
class Stmt;
class Token;
class UnresolvedLookupExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXFoldExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXFoldExpr> in(const Index &index);
  static gap::generator<CXXFoldExpr> in(const Fragment &frag);
  static gap::generator<CXXFoldExpr> in(const File &file);
  static gap::generator<CXXFoldExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXFoldExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXFoldExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FOLD_EXPR;
  }

  static gap::generator<CXXFoldExpr> containing(const Decl &decl);
  static gap::generator<CXXFoldExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXFoldExpr> containing(const Stmt &stmt);
  static gap::generator<CXXFoldExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXFoldExpr> by_id(const Index &, EntityId);

  static std::optional<CXXFoldExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXFoldExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXFoldExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXFoldExpr> from(const Reference &r);
  static std::optional<CXXFoldExpr> from(const VariantEntity &e);
  static std::optional<CXXFoldExpr> from(const TokenContext &t);

  std::optional<UnresolvedLookupExpr> callee(void) const;
  Token ellipsis_token(void) const;
  std::optional<Expr> initializer(void) const;
  std::optional<Expr> lhs(void) const;
  Token l_paren_token(void) const;
  BinaryOperatorKind operator_(void) const;
  Expr pattern(void) const;
  std::optional<Expr> rhs(void) const;
  Token r_paren_token(void) const;
  bool is_left_fold(void) const;
  bool is_right_fold(void) const;
};

static_assert(sizeof(CXXFoldExpr) == sizeof(Expr));

#endif
} // namespace mx
