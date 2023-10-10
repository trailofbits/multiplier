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
class OMPArrayShapingExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPArrayShapingExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OMPArrayShapingExpr> in(const Index &index);
  static gap::generator<OMPArrayShapingExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPArrayShapingExpr> by_id(const Index &, EntityId);
  static gap::generator<OMPArrayShapingExpr> in(const Fragment &frag);
  static gap::generator<OMPArrayShapingExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ARRAY_SHAPING_EXPR;
  }

  static gap::generator<OMPArrayShapingExpr> containing(const Decl &decl);
  static gap::generator<OMPArrayShapingExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPArrayShapingExpr> containing(const Stmt &stmt);
  static gap::generator<OMPArrayShapingExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPArrayShapingExpr> from(const Stmt &parent);

  inline static std::optional<OMPArrayShapingExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPArrayShapingExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPArrayShapingExpr> from(const Reference &r);
  static std::optional<OMPArrayShapingExpr> from(const TokenContext &t);

  Expr base(void) const;
  std::optional<Expr> nth_dimension(unsigned n) const;
  unsigned num_dimensions(void) const;
  gap::generator<Expr> dimensions(void) const &;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(OMPArrayShapingExpr) == sizeof(Expr));

#endif
} // namespace mx
