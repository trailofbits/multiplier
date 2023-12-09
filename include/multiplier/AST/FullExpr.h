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
class FullExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<FullExpr> in(const Index &index);
  static gap::generator<FullExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FullExpr> by_id(const Index &, EntityId);
  static gap::generator<FullExpr> in(const Fragment &frag);
  static gap::generator<FullExpr> in(const File &file);

  static std::optional<FullExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<FullExpr, ir::hl::Operation>> in(const Compilation &tu);

  static gap::generator<FullExpr> containing(const Decl &decl);
  static gap::generator<FullExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<FullExpr> containing(const Stmt &stmt);
  static gap::generator<FullExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FullExpr> from_base(const Stmt &parent);
  inline static std::optional<FullExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<FullExpr> from(const std::optional<Stmt> &parent);
  static std::optional<FullExpr> from(const Reference &r);
  static std::optional<FullExpr> from(const VariantEntity &e);
  static std::optional<FullExpr> from(const TokenContext &t);

  Expr sub_expression(void) const;
};

static_assert(sizeof(FullExpr) == sizeof(Expr));

#endif
} // namespace mx
