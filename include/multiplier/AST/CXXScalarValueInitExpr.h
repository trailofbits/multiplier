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
class CXXScalarValueInitExpr;
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
class MX_EXPORT CXXScalarValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXScalarValueInitExpr> in(const Index &index);
  static gap::generator<CXXScalarValueInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXScalarValueInitExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXScalarValueInitExpr> in(const Fragment &frag);
  static gap::generator<CXXScalarValueInitExpr> in(const File &file);

  static std::optional<CXXScalarValueInitExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CXXScalarValueInitExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
  }

  static gap::generator<CXXScalarValueInitExpr> containing(const Decl &decl);
  static gap::generator<CXXScalarValueInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXScalarValueInitExpr> containing(const Stmt &stmt);
  static gap::generator<CXXScalarValueInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXScalarValueInitExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXScalarValueInitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXScalarValueInitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXScalarValueInitExpr> from(const Reference &r);
  static std::optional<CXXScalarValueInitExpr> from(const VariantEntity &e);
  static std::optional<CXXScalarValueInitExpr> from(const TokenContext &t);

  Token r_paren_token(void) const;
};

static_assert(sizeof(CXXScalarValueInitExpr) == sizeof(Expr));

#endif
} // namespace mx
