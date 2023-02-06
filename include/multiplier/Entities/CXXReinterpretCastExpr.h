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

#include "CXXNamedCastExpr.h"
#include "StmtKind.h"

namespace mx {
class CXXNamedCastExpr;
class CXXReinterpretCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXReinterpretCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXReinterpretCastExpr> in(const Fragment &frag);
  static gap::generator<CXXReinterpretCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REINTERPRET_CAST_EXPR;
  }

  static gap::generator<CXXReinterpretCastExpr> containing(const Decl &decl);
  static gap::generator<CXXReinterpretCastExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXReinterpretCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXReinterpretCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXReinterpretCastExpr> from(const CXXNamedCastExpr &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<CXXNamedCastExpr> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXReinterpretCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXReinterpretCastExpr> from(const CastExpr &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXReinterpretCastExpr> from(const Expr &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXReinterpretCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXReinterpretCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CXXReinterpretCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
