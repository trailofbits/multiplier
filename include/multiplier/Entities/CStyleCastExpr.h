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

#include "ExplicitCastExpr.h"
#include "StmtKind.h"

namespace mx {
class CStyleCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CStyleCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CStyleCastExpr> in(const Fragment &frag);
  static gap::generator<CStyleCastExpr> in(const Index &index);
  static gap::generator<CStyleCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CStyleCastExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::C_STYLE_CAST_EXPR;
  }

  static gap::generator<CStyleCastExpr> containing(const Decl &decl);
  static gap::generator<CStyleCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CStyleCastExpr> containing(const Stmt &stmt);
  static gap::generator<CStyleCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CStyleCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CStyleCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CStyleCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const CastExpr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const Expr &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CStyleCastExpr> from(const Stmt &parent);

  inline static std::optional<CStyleCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CStyleCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(CStyleCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
