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
class File;
class ImplicitValueInitExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ImplicitValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ImplicitValueInitExpr> in(const Index &index);
  static gap::generator<ImplicitValueInitExpr> in(const Fragment &frag);
  static gap::generator<ImplicitValueInitExpr> in(const File &file);
  static gap::generator<ImplicitValueInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ImplicitValueInitExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ImplicitValueInitExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IMPLICIT_VALUE_INIT_EXPR;
  }

  static gap::generator<ImplicitValueInitExpr> containing(const Decl &decl);
  static gap::generator<ImplicitValueInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ImplicitValueInitExpr> containing(const Stmt &stmt);
  static gap::generator<ImplicitValueInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ImplicitValueInitExpr> by_id(const Index &, EntityId);

  static std::optional<ImplicitValueInitExpr> from_base(const Stmt &parent);
  inline static std::optional<ImplicitValueInitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ImplicitValueInitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ImplicitValueInitExpr> from(const Reference &r);
  static std::optional<ImplicitValueInitExpr> from(const VariantEntity &e);
  static std::optional<ImplicitValueInitExpr> from(const TokenContext &t);

};

static_assert(sizeof(ImplicitValueInitExpr) == sizeof(Expr));

#endif
} // namespace mx
