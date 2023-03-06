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

#include "CoroutineSuspendExpr.h"

namespace mx {
class CoawaitExpr;
class CoroutineSuspendExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CoawaitExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CoawaitExpr> in(const Fragment &frag);
  static gap::generator<CoawaitExpr> in(const File &file);
  static gap::generator<CoawaitExpr> in(const Index &index);
  static gap::generator<CoawaitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CoawaitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COAWAIT_EXPR;
  }

  static gap::generator<CoawaitExpr> containing(const Decl &decl);
  static gap::generator<CoawaitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CoawaitExpr> containing(const Stmt &stmt);
  static gap::generator<CoawaitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CoawaitExpr> from(const Stmt &parent);

  inline static std::optional<CoawaitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoawaitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CoawaitExpr> from(const Reference &r) {
    return CoawaitExpr::from(r.as_statement());
  }

  inline static std::optional<CoawaitExpr> from(const TokenContext &t) {
    return CoawaitExpr::from(t.as_statement());
  }

  bool is_implicit(void) const;
};

static_assert(sizeof(CoawaitExpr) == sizeof(CoroutineSuspendExpr));

#endif
} // namespace mx
