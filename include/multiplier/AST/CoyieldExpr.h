// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CoroutineSuspendExpr.h"

namespace mx {
class EntityProvider;
class Index;
class CoroutineSuspendExpr;
class CoyieldExpr;
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
class CoyieldExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CoyieldExpr> in(const Index &index);
  static gap::generator<CoyieldExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CoyieldExpr> by_id(const Index &, EntityId);
  static gap::generator<CoyieldExpr> in(const Fragment &frag);
  static gap::generator<CoyieldExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COYIELD_EXPR;
  }

  static gap::generator<CoyieldExpr> containing(const Decl &decl);
  static gap::generator<CoyieldExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CoyieldExpr> containing(const Stmt &stmt);
  static gap::generator<CoyieldExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoyieldExpr> from_base(const Stmt &parent);
  inline static std::optional<CoyieldExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CoyieldExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CoyieldExpr> from(const Reference &r);
  static std::optional<CoyieldExpr> from(const VariantEntity &e);
  static std::optional<CoyieldExpr> from(const TokenContext &t);

};

static_assert(sizeof(CoyieldExpr) == sizeof(CoroutineSuspendExpr));

#endif
} // namespace mx
