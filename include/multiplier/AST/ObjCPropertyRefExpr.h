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
class ObjCInterfaceDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyRefExpr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCPropertyRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCPropertyRefExpr> in(const Index &index);
  static gap::generator<ObjCPropertyRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCPropertyRefExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCPropertyRefExpr> in(const Fragment &frag);
  static gap::generator<ObjCPropertyRefExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_PROPERTY_REF_EXPR;
  }

  static gap::generator<ObjCPropertyRefExpr> containing(const Decl &decl);
  static gap::generator<ObjCPropertyRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCPropertyRefExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCPropertyRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCPropertyRefExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCPropertyRefExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCPropertyRefExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCPropertyRefExpr> from(const Reference &r);
  static std::optional<ObjCPropertyRefExpr> from(const VariantEntity &e);
  static std::optional<ObjCPropertyRefExpr> from(const TokenContext &t);

  Expr base(void) const;
  ObjCInterfaceDecl class_receiver(void) const;
  ObjCPropertyDecl explicit_property(void) const;
  ObjCMethodDecl implicit_property_getter(void) const;
  ObjCMethodDecl implicit_property_setter(void) const;
  Token token(void) const;
  Token receiver_token(void) const;
  Type receiver_type(void) const;
  Type super_receiver_type(void) const;
  bool is_class_receiver(void) const;
  bool is_explicit_property(void) const;
  bool is_implicit_property(void) const;
  bool is_messaging_getter(void) const;
  bool is_messaging_setter(void) const;
  bool is_object_receiver(void) const;
  bool is_super_receiver(void) const;
};

static_assert(sizeof(ObjCPropertyRefExpr) == sizeof(Expr));

#endif
} // namespace mx
