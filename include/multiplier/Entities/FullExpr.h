// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"

namespace mx {
class ConstantExpr;
class Decl;
class Expr;
class ExprWithCleanups;
class FullExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<FullExpr> in(const Fragment &frag);
  static gap::generator<FullExpr> in(const File &file);
  static gap::generator<FullExpr> in(const Index &index);
  static gap::generator<FullExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FullExpr> by_id(const Index &, EntityId);

  static gap::generator<FullExpr> containing(const Decl &decl);
  static gap::generator<FullExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<FullExpr> containing(const Stmt &stmt);
  static gap::generator<FullExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FullExpr> from(const Stmt &parent);

  inline static std::optional<FullExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FullExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<FullExpr> from(const Reference &r) {
    return FullExpr::from(r.as_statement());
  }

  inline static std::optional<FullExpr> from(const TokenContext &t) {
    return FullExpr::from(t.as_statement());
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(FullExpr) == sizeof(Expr));

#endif
} // namespace mx
