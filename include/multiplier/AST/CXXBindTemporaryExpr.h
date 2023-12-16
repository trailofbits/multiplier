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
class CXXBindTemporaryExpr;
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
class MX_EXPORT CXXBindTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXBindTemporaryExpr> in(const Index &index);
  static gap::generator<CXXBindTemporaryExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXBindTemporaryExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXBindTemporaryExpr> in(const Fragment &frag);
  static gap::generator<CXXBindTemporaryExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<CXXBindTemporaryExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXBindTemporaryExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BIND_TEMPORARY_EXPR;
  }

  static gap::generator<CXXBindTemporaryExpr> containing(const Decl &decl);
  static gap::generator<CXXBindTemporaryExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXBindTemporaryExpr> containing(const Stmt &stmt);
  static gap::generator<CXXBindTemporaryExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXBindTemporaryExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXBindTemporaryExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXBindTemporaryExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXBindTemporaryExpr> from(const Reference &r);
  static std::optional<CXXBindTemporaryExpr> from(const VariantEntity &e);
  static std::optional<CXXBindTemporaryExpr> from(const TokenContext &t);

  Expr sub_expression(void) const;
};

static_assert(sizeof(CXXBindTemporaryExpr) == sizeof(Expr));

#endif
} // namespace mx
