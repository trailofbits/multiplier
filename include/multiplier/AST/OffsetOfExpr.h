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
class OffsetOfExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OffsetOfExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OffsetOfExpr> in(const Index &index);
  static gap::generator<OffsetOfExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OffsetOfExpr> by_id(const Index &, EntityId);
  static gap::generator<OffsetOfExpr> in(const Fragment &frag);
  static gap::generator<OffsetOfExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<OffsetOfExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<OffsetOfExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OFFSET_OF_EXPR;
  }

  static gap::generator<OffsetOfExpr> containing(const Decl &decl);
  static gap::generator<OffsetOfExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OffsetOfExpr> containing(const Stmt &stmt);
  static gap::generator<OffsetOfExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OffsetOfExpr> from_base(const Stmt &parent);
  inline static std::optional<OffsetOfExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OffsetOfExpr> from(const std::optional<Stmt> &parent);
  static std::optional<OffsetOfExpr> from(const Reference &r);
  static std::optional<OffsetOfExpr> from(const VariantEntity &e);
  static std::optional<OffsetOfExpr> from(const TokenContext &t);

  Token operator_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(OffsetOfExpr) == sizeof(Expr));

#endif
} // namespace mx
