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
class CXXNamedCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXNamedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXNamedCastExpr> in(const Fragment &frag);
  static gap::generator<CXXNamedCastExpr> in(const Index &index);
  static gap::generator<CXXNamedCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CXXNamedCastExpr> by(const Index &, EntityId);

  static gap::generator<CXXNamedCastExpr> containing(const Decl &decl);
  static gap::generator<CXXNamedCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXNamedCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXNamedCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXNamedCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXNamedCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXNamedCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CXXNamedCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CXXNamedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXNamedCastExpr> from(const CastExpr &parent);

  inline static std::optional<CXXNamedCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CXXNamedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXNamedCastExpr> from(const Expr &parent);

  inline static std::optional<CXXNamedCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXNamedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXNamedCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXNamedCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXNamedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXNamedCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXNamedCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXNamedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TokenRange angle_brackets(void) const;
  std::string_view cast_name(void) const;
  Token operator_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(CXXNamedCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
