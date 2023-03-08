// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "FullExpr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class ExprWithCleanups;
class FullExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExprWithCleanups : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExprWithCleanups> in(const Fragment &frag);
  static gap::generator<ExprWithCleanups> in(const File &file);
  static gap::generator<ExprWithCleanups> in(const Index &index);
  static gap::generator<ExprWithCleanups> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExprWithCleanups> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXPR_WITH_CLEANUPS;
  }

  static gap::generator<ExprWithCleanups> containing(const Decl &decl);
  static gap::generator<ExprWithCleanups> containing(const std::optional<Decl> &decl);

  static gap::generator<ExprWithCleanups> containing(const Stmt &stmt);
  static gap::generator<ExprWithCleanups> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExprWithCleanups> from(const Stmt &parent);

  inline static std::optional<ExprWithCleanups> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExprWithCleanups::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExprWithCleanups> from(const Reference &r);
  static std::optional<ExprWithCleanups> from(const TokenContext &t);

  bool cleanups_have_side_effects(void) const;
};

static_assert(sizeof(ExprWithCleanups) == sizeof(FullExpr));

#endif
} // namespace mx
