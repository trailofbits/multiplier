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
class CXXDefaultInitExpr;
class Decl;
class Expr;
class FieldDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXDefaultInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDefaultInitExpr> in(const Index &index);
  static gap::generator<CXXDefaultInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDefaultInitExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXDefaultInitExpr> in(const Fragment &frag);
  static gap::generator<CXXDefaultInitExpr> in(const File &file);

  static std::optional<CXXDefaultInitExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CXXDefaultInitExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEFAULT_INIT_EXPR;
  }

  static gap::generator<CXXDefaultInitExpr> containing(const Decl &decl);
  static gap::generator<CXXDefaultInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDefaultInitExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDefaultInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDefaultInitExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXDefaultInitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXDefaultInitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXDefaultInitExpr> from(const Reference &r);
  static std::optional<CXXDefaultInitExpr> from(const VariantEntity &e);
  static std::optional<CXXDefaultInitExpr> from(const TokenContext &t);

  std::optional<Expr> expression(void) const;
  FieldDecl field(void) const;
  Expr rewritten_expression(void) const;
  Token used_token(void) const;
  bool has_rewritten_initializer(void) const;
};

static_assert(sizeof(CXXDefaultInitExpr) == sizeof(Expr));

#endif
} // namespace mx
