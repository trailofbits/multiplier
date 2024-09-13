// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class ObjCMethodDecl;
class ObjCSubscriptRefExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCSubscriptRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCSubscriptRefExpr> in(const Index &index);
  static gap::generator<ObjCSubscriptRefExpr> in(const Fragment &frag);
  static gap::generator<ObjCSubscriptRefExpr> in(const File &file);
  static gap::generator<ObjCSubscriptRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ObjCSubscriptRefExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCSubscriptRefExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR;
  }

  static gap::generator<ObjCSubscriptRefExpr> containing(const Decl &decl);
  static gap::generator<ObjCSubscriptRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCSubscriptRefExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCSubscriptRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCSubscriptRefExpr> by_id(const Index &, EntityId);

  static std::optional<ObjCSubscriptRefExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCSubscriptRefExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCSubscriptRefExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCSubscriptRefExpr> from(const Reference &r);
  static std::optional<ObjCSubscriptRefExpr> from(const VariantEntity &e);
  static std::optional<ObjCSubscriptRefExpr> from(const TokenContext &t);

  ObjCMethodDecl at_index_method_declaration(void) const;
  Expr base_expression(void) const;
  Expr key_expression(void) const;
  Token r_bracket_token(void) const;
  bool is_array_subscript_reference_expression(void) const;
};

static_assert(sizeof(ObjCSubscriptRefExpr) == sizeof(Expr));

#endif
} // namespace mx
