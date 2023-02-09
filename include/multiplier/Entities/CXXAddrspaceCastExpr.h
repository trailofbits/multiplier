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
class CXXAddrspaceCastExpr;
class CXXNamedCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXAddrspaceCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXAddrspaceCastExpr> in(const Fragment &frag);
  static gap::generator<CXXAddrspaceCastExpr> in(const Index &index);
  static gap::generator<CXXAddrspaceCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CXXAddrspaceCastExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
  }

  static gap::generator<CXXAddrspaceCastExpr> containing(const Decl &decl);
  static gap::generator<CXXAddrspaceCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXAddrspaceCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXAddrspaceCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXAddrspaceCastExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXAddrspaceCastExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXAddrspaceCastExpr> from(const CXXNamedCastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<CXXNamedCastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const CastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const Expr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CXXAddrspaceCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
