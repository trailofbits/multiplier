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
class CXXParenListInitExpr;
class Decl;
class Expr;
class FieldDecl;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXParenListInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXParenListInitExpr> in(const Index &index);
  static gap::generator<CXXParenListInitExpr> in(const Fragment &frag);
  static gap::generator<CXXParenListInitExpr> in(const File &file);
  static gap::generator<CXXParenListInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXParenListInitExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXParenListInitExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_PAREN_LIST_INIT_EXPR;
  }

  static gap::generator<CXXParenListInitExpr> containing(const Decl &decl);
  static gap::generator<CXXParenListInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXParenListInitExpr> containing(const Stmt &stmt);
  static gap::generator<CXXParenListInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXParenListInitExpr> by_id(const Index &, EntityId);

  static std::optional<CXXParenListInitExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXParenListInitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXParenListInitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXParenListInitExpr> from(const Reference &r);
  static std::optional<CXXParenListInitExpr> from(const VariantEntity &e);
  static std::optional<CXXParenListInitExpr> from(const TokenContext &t);

  Expr array_filler(void) const;
  Token initializer_token(void) const;
  FieldDecl initialized_field_in_union(void) const;
};

static_assert(sizeof(CXXParenListInitExpr) == sizeof(Expr));

#endif
} // namespace mx
