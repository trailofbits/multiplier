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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCProtocolDecl;
class ObjCProtocolExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCProtocolExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCProtocolExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCProtocolExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCProtocolExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_PROTOCOL_EXPR;
  }

  static gap::generator<ObjCProtocolExpr> containing(const Decl &decl);
  static gap::generator<ObjCProtocolExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCProtocolExpr> from(const TokenContext &c);
  static std::optional<ObjCProtocolExpr> from(const Expr &parent);

  inline static std::optional<ObjCProtocolExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCProtocolExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCProtocolExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCProtocolExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCProtocolExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCProtocolExpr> from(const Stmt &parent);

  inline static std::optional<ObjCProtocolExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCProtocolExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  ObjCProtocolDecl protocol(void) const;
  Token protocol_id_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCProtocolExpr) == sizeof(Expr));

#endif
} // namespace mx
