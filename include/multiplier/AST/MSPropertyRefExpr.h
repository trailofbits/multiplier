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
class MSPropertyDecl;
class MSPropertyRefExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MSPropertyRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MSPropertyRefExpr> in(const Index &index);
  static gap::generator<MSPropertyRefExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSPropertyRefExpr> by_id(const Index &, EntityId);
  static gap::generator<MSPropertyRefExpr> in(const Fragment &frag);
  static gap::generator<MSPropertyRefExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<MSPropertyRefExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<MSPropertyRefExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_PROPERTY_REF_EXPR;
  }

  static gap::generator<MSPropertyRefExpr> containing(const Decl &decl);
  static gap::generator<MSPropertyRefExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MSPropertyRefExpr> containing(const Stmt &stmt);
  static gap::generator<MSPropertyRefExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSPropertyRefExpr> from_base(const Stmt &parent);
  inline static std::optional<MSPropertyRefExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<MSPropertyRefExpr> from(const std::optional<Stmt> &parent);
  static std::optional<MSPropertyRefExpr> from(const Reference &r);
  static std::optional<MSPropertyRefExpr> from(const VariantEntity &e);
  static std::optional<MSPropertyRefExpr> from(const TokenContext &t);

  Expr base_expression(void) const;
  Token member_token(void) const;
  MSPropertyDecl property_declaration(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

static_assert(sizeof(MSPropertyRefExpr) == sizeof(Expr));

#endif
} // namespace mx
