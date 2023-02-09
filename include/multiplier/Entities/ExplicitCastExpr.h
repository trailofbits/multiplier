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

#include "CastExpr.h"
#include "StmtKind.h"

namespace mx {
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExplicitCastExpr> in(const Fragment &frag);
  static gap::generator<ExplicitCastExpr> in(const Index &index);
  static gap::generator<ExplicitCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ExplicitCastExpr> by(const Index &, EntityId);

  static gap::generator<ExplicitCastExpr> containing(const Decl &decl);
  static gap::generator<ExplicitCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ExplicitCastExpr> containing(const Stmt &stmt);
  static gap::generator<ExplicitCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ExplicitCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ExplicitCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ExplicitCastExpr> from(const CastExpr &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const Expr &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const ValueStmt &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExplicitCastExpr> from(const Stmt &parent);

  inline static std::optional<ExplicitCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExplicitCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type type_as_written(void) const;
};

static_assert(sizeof(ExplicitCastExpr) == sizeof(CastExpr));

#endif
} // namespace mx
