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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCEncodeExpr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCEncodeExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCEncodeExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCEncodeExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCEncodeExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ENCODE_EXPR;
  }

  static gap::generator<ObjCEncodeExpr> containing(const Decl &decl);
  static gap::generator<ObjCEncodeExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCEncodeExpr> from(const TokenContext &c);
  static std::optional<ObjCEncodeExpr> from(const Expr &parent);

  inline static std::optional<ObjCEncodeExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCEncodeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCEncodeExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCEncodeExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCEncodeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCEncodeExpr> from(const Stmt &parent);

  inline static std::optional<ObjCEncodeExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCEncodeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  Type encoded_type(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCEncodeExpr) == sizeof(Expr));

#endif
} // namespace mx
