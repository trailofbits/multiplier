// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class ObjCIvarDecl;
class ObjCIvarRefExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCIvarRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCIvarRefExpr> in(const Index &index);
  static gap::generator<ObjCIvarRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCIvarRefExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCIvarRefExpr> in(const Fragment &frag);
  static gap::generator<ObjCIvarRefExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_IVAR_REF_EXPR;
  }

  static gap::generator<ObjCIvarRefExpr> containing(const Decl &decl);
  static gap::generator<ObjCIvarRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCIvarRefExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCIvarRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIvarRefExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCIvarRefExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCIvarRefExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCIvarRefExpr> from(const Reference &r);
  static std::optional<ObjCIvarRefExpr> from(const VariantEntity &e);
  static std::optional<ObjCIvarRefExpr> from(const TokenContext &t);

  Expr base(void) const;
  ObjCIvarDecl declaration(void) const;
  Token token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
  bool is_free_instance_variable(void) const;
};

static_assert(sizeof(ObjCIvarRefExpr) == sizeof(Expr));

#endif
} // namespace mx
