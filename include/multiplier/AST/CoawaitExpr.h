// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CoroutineSuspendExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CoawaitExpr;
class CoroutineSuspendExpr;
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
class MX_EXPORT CoawaitExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CoawaitExpr> in(const Index &index);
  static gap::generator<CoawaitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CoawaitExpr> by_id(const Index &, EntityId);
  static gap::generator<CoawaitExpr> in(const Fragment &frag);
  static gap::generator<CoawaitExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<CoawaitExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CoawaitExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COAWAIT_EXPR;
  }

  static gap::generator<CoawaitExpr> containing(const Decl &decl);
  static gap::generator<CoawaitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CoawaitExpr> containing(const Stmt &stmt);
  static gap::generator<CoawaitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoawaitExpr> from_base(const Stmt &parent);
  inline static std::optional<CoawaitExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CoawaitExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CoawaitExpr> from(const Reference &r);
  static std::optional<CoawaitExpr> from(const VariantEntity &e);
  static std::optional<CoawaitExpr> from(const TokenContext &t);

  bool is_implicit(void) const;
};

static_assert(sizeof(CoawaitExpr) == sizeof(CoroutineSuspendExpr));

#endif
} // namespace mx
