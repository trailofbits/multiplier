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
class MatrixSubscriptExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MatrixSubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MatrixSubscriptExpr> in(const Index &index);
  static gap::generator<MatrixSubscriptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MatrixSubscriptExpr> by_id(const Index &, EntityId);
  static gap::generator<MatrixSubscriptExpr> in(const Fragment &frag);
  static gap::generator<MatrixSubscriptExpr> in(const File &file);

  static std::optional<MatrixSubscriptExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<MatrixSubscriptExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MATRIX_SUBSCRIPT_EXPR;
  }

  static gap::generator<MatrixSubscriptExpr> containing(const Decl &decl);
  static gap::generator<MatrixSubscriptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MatrixSubscriptExpr> containing(const Stmt &stmt);
  static gap::generator<MatrixSubscriptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MatrixSubscriptExpr> from_base(const Stmt &parent);
  inline static std::optional<MatrixSubscriptExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<MatrixSubscriptExpr> from(const std::optional<Stmt> &parent);
  static std::optional<MatrixSubscriptExpr> from(const Reference &r);
  static std::optional<MatrixSubscriptExpr> from(const VariantEntity &e);
  static std::optional<MatrixSubscriptExpr> from(const TokenContext &t);

  Expr base(void) const;
  Expr column_index(void) const;
  Token r_bracket_token(void) const;
  Expr row_index(void) const;
  bool is_incomplete(void) const;
};

static_assert(sizeof(MatrixSubscriptExpr) == sizeof(Expr));

#endif
} // namespace mx
