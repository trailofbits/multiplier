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

#include "CXXNamedCastExpr.h"
#include "StmtKind.h"

namespace mx {
class CXXNamedCastExpr;
class CXXStaticCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXStaticCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXStaticCastExpr> in(const Fragment &frag);
  static gap::generator<CXXStaticCastExpr> in(const Index &index);
  static gap::generator<CXXStaticCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CXXStaticCastExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_STATIC_CAST_EXPR;
  }

  static gap::generator<CXXStaticCastExpr> containing(const Decl &decl);
  static gap::generator<CXXStaticCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXStaticCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXStaticCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXStaticCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXStaticCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXStaticCastExpr> from(const CXXNamedCastExpr &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<CXXNamedCastExpr> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStaticCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStaticCastExpr> from(const CastExpr &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStaticCastExpr> from(const Expr &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStaticCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXStaticCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXStaticCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXStaticCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CXXStaticCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
