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
class OpaqueValueExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpaqueValueExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OpaqueValueExpr> in(const Index &index);
  static gap::generator<OpaqueValueExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpaqueValueExpr> by_id(const Index &, EntityId);
  static gap::generator<OpaqueValueExpr> in(const Fragment &frag);
  static gap::generator<OpaqueValueExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OPAQUE_VALUE_EXPR;
  }

  static gap::generator<OpaqueValueExpr> containing(const Decl &decl);
  static gap::generator<OpaqueValueExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OpaqueValueExpr> containing(const Stmt &stmt);
  static gap::generator<OpaqueValueExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OpaqueValueExpr> from_base(const Stmt &parent);
  inline static std::optional<OpaqueValueExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OpaqueValueExpr> from(const std::optional<Stmt> &parent);
  static std::optional<OpaqueValueExpr> from(const Reference &r);
  static std::optional<OpaqueValueExpr> from(const VariantEntity &e);
  static std::optional<OpaqueValueExpr> from(const TokenContext &t);

  Token token(void) const;
  Expr source_expression(void) const;
  bool is_unique(void) const;
};

static_assert(sizeof(OpaqueValueExpr) == sizeof(Expr));

#endif
} // namespace mx
