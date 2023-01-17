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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "ExplicitCastExpr.h"
#include "ObjCBridgeCastKind.h"
#include "StmtKind.h"

namespace mx {
class CastExpr;
class ExplicitCastExpr;
class Expr;
class ObjCBridgedCastExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCBridgedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCBridgedCastExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCBridgedCastExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCBridgedCastExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BRIDGED_CAST_EXPR;
  }

  static gap::generator<ObjCBridgedCastExpr> containing(const Decl &decl);
  static gap::generator<ObjCBridgedCastExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCBridgedCastExpr> from(const TokenContext &c);
  static std::optional<ObjCBridgedCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgedCastExpr> from(const CastExpr &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgedCastExpr> from(const Expr &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgedCastExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgedCastExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token bridge_keyword_token(void) const;
  ObjCBridgeCastKind bridge_kind(void) const;
  std::string_view bridge_kind_name(void) const;
  Token l_paren_token(void) const;
};

static_assert(sizeof(ObjCBridgedCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
