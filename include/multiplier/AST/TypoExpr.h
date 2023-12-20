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
class Stmt;
class Token;
class TypoExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypoExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<TypoExpr> in(const Index &index);
  static gap::generator<TypoExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypoExpr> by_id(const Index &, EntityId);
  static gap::generator<TypoExpr> in(const Fragment &frag);
  static gap::generator<TypoExpr> in(const File &file);

  static std::optional<TypoExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<TypoExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPO_EXPR;
  }

  static gap::generator<TypoExpr> containing(const Decl &decl);
  static gap::generator<TypoExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<TypoExpr> containing(const Stmt &stmt);
  static gap::generator<TypoExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypoExpr> from_base(const Stmt &parent);
  inline static std::optional<TypoExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<TypoExpr> from(const std::optional<Stmt> &parent);
  static std::optional<TypoExpr> from(const Reference &r);
  static std::optional<TypoExpr> from(const VariantEntity &e);
  static std::optional<TypoExpr> from(const TokenContext &t);

};

static_assert(sizeof(TypoExpr) == sizeof(Expr));

#endif
} // namespace mx
