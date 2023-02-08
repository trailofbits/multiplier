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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "CoroutineSuspendExpr.h"
#include "StmtKind.h"

namespace mx {
class CoroutineSuspendExpr;
class CoyieldExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CoyieldExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CoyieldExpr> in(const Fragment &frag);
  static gap::generator<CoyieldExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COYIELD_EXPR;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<CoyieldExpr> containing(const Decl &decl);
  static gap::generator<CoyieldExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CoyieldExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CoyieldExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CoyieldExpr> from(const CoroutineSuspendExpr &parent);

  inline static std::optional<CoyieldExpr> from(const std::optional<CoroutineSuspendExpr> &parent) {
    if (parent) {
      return CoyieldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoyieldExpr> from(const Expr &parent);

  inline static std::optional<CoyieldExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CoyieldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoyieldExpr> from(const ValueStmt &parent);

  inline static std::optional<CoyieldExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CoyieldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CoyieldExpr> from(const Stmt &parent);

  inline static std::optional<CoyieldExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CoyieldExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CoyieldExpr) == sizeof(CoroutineSuspendExpr));

#endif
} // namespace mx
