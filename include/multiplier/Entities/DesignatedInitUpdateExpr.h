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
class DesignatedInitUpdateExpr;
class Expr;
class InitListExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DesignatedInitUpdateExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<DesignatedInitUpdateExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DesignatedInitUpdateExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DesignatedInitUpdateExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
  }

  static gap::generator<DesignatedInitUpdateExpr> containing(const Decl &decl);
  static gap::generator<DesignatedInitUpdateExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DesignatedInitUpdateExpr> from(const TokenContext &c);
  static std::optional<DesignatedInitUpdateExpr> from(const Expr &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitUpdateExpr> from(const ValueStmt &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitUpdateExpr> from(const Stmt &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  InitListExpr updater(void) const;
};

static_assert(sizeof(DesignatedInitUpdateExpr) == sizeof(Expr));

#endif
} // namespace mx
