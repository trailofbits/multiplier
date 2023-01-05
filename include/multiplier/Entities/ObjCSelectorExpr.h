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
class ObjCSelectorExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCSelectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCSelectorExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCSelectorExpr> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCSelectorExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_SELECTOR_EXPR;
  }

  static gap::generator<ObjCSelectorExpr> containing(const Decl &decl);
  static gap::generator<ObjCSelectorExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCSelectorExpr> from(const TokenContext &c);
  static std::optional<ObjCSelectorExpr> from(const Expr &parent);

  inline static std::optional<ObjCSelectorExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCSelectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCSelectorExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCSelectorExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCSelectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCSelectorExpr> from(const Stmt &parent);

  inline static std::optional<ObjCSelectorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCSelectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCSelectorExpr) == sizeof(Expr));

#endif
} // namespace mx
