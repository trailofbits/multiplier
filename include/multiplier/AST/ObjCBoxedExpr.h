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
class ObjCBoxedExpr;
class ObjCMethodDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCBoxedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCBoxedExpr> in(const Index &index);
  static gap::generator<ObjCBoxedExpr> in(const Fragment &frag);
  static gap::generator<ObjCBoxedExpr> in(const File &file);
  static gap::generator<ObjCBoxedExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ObjCBoxedExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCBoxedExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BOXED_EXPR;
  }

  static gap::generator<ObjCBoxedExpr> containing(const Decl &decl);
  static gap::generator<ObjCBoxedExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCBoxedExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCBoxedExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCBoxedExpr> by_id(const Index &, EntityId);

  static std::optional<ObjCBoxedExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCBoxedExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCBoxedExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCBoxedExpr> from(const Reference &r);
  static std::optional<ObjCBoxedExpr> from(const VariantEntity &e);
  static std::optional<ObjCBoxedExpr> from(const TokenContext &t);

  Token at_token(void) const;
  ObjCMethodDecl boxing_method(void) const;
  Expr sub_expression(void) const;
  bool is_expressible_as_constant_initializer(void) const;
};

static_assert(sizeof(ObjCBoxedExpr) == sizeof(Expr));

#endif
} // namespace mx
