// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FullExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class ExprWithCleanups;
class File;
class FullExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ExprWithCleanups : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExprWithCleanups> in(const Index &index);
  static gap::generator<ExprWithCleanups> in(const Fragment &frag);
  static gap::generator<ExprWithCleanups> in(const File &file);
  static gap::generator<ExprWithCleanups> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ExprWithCleanups> from(const ir::Operation &op);
  static gap::generator<std::pair<ExprWithCleanups, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXPR_WITH_CLEANUPS;
  }

  static gap::generator<ExprWithCleanups> containing(const Decl &decl);
  static gap::generator<ExprWithCleanups> containing(const std::optional<Decl> &decl);

  static gap::generator<ExprWithCleanups> containing(const Stmt &stmt);
  static gap::generator<ExprWithCleanups> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExprWithCleanups> by_id(const Index &, EntityId);

  static std::optional<ExprWithCleanups> from_base(const Stmt &parent);
  inline static std::optional<ExprWithCleanups> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ExprWithCleanups> from(const std::optional<Stmt> &parent);
  static std::optional<ExprWithCleanups> from(const Reference &r);
  static std::optional<ExprWithCleanups> from(const VariantEntity &e);
  static std::optional<ExprWithCleanups> from(const TokenContext &t);

  bool cleanups_have_side_effects(void) const;
};

static_assert(sizeof(ExprWithCleanups) == sizeof(FullExpr));

#endif
} // namespace mx
