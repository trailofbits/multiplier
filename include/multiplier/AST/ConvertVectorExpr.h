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
class ConvertVectorExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConvertVectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ConvertVectorExpr> in(const Index &index);
  static gap::generator<ConvertVectorExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConvertVectorExpr> by_id(const Index &, EntityId);
  static gap::generator<ConvertVectorExpr> in(const Fragment &frag);
  static gap::generator<ConvertVectorExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONVERT_VECTOR_EXPR;
  }

  static gap::generator<ConvertVectorExpr> containing(const Decl &decl);
  static gap::generator<ConvertVectorExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ConvertVectorExpr> containing(const Stmt &stmt);
  static gap::generator<ConvertVectorExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConvertVectorExpr> from_base(const Stmt &parent);
  inline static std::optional<ConvertVectorExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ConvertVectorExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ConvertVectorExpr> from(const Reference &r);
  static std::optional<ConvertVectorExpr> from(const VariantEntity &e);
  static std::optional<ConvertVectorExpr> from(const TokenContext &t);

  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr src_expression(void) const;
};

static_assert(sizeof(ConvertVectorExpr) == sizeof(Expr));

#endif
} // namespace mx
