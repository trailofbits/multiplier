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
class PackExpansionExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PackExpansionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<PackExpansionExpr> in(const Fragment &frag);
  static gap::generator<PackExpansionExpr> in(const File &file);
  static gap::generator<PackExpansionExpr> in(const Index &index);
  static gap::generator<PackExpansionExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PackExpansionExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PACK_EXPANSION_EXPR;
  }

  static gap::generator<PackExpansionExpr> containing(const Decl &decl);
  static gap::generator<PackExpansionExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<PackExpansionExpr> containing(const Stmt &stmt);
  static gap::generator<PackExpansionExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PackExpansionExpr> from(const Stmt &parent);

  inline static std::optional<PackExpansionExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return PackExpansionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PackExpansionExpr> from(const Reference &r);
  static std::optional<PackExpansionExpr> from(const TokenContext &t);

  Token ellipsis_token(void) const;
  Expr pattern(void) const;
};

static_assert(sizeof(PackExpansionExpr) == sizeof(Expr));

#endif
} // namespace mx
