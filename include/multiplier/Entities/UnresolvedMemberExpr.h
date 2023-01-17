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

#include "OverloadExpr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OverloadExpr;
class Stmt;
class Type;
class UnresolvedMemberExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedMemberExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<UnresolvedMemberExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnresolvedMemberExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UnresolvedMemberExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_MEMBER_EXPR;
  }

  static gap::generator<UnresolvedMemberExpr> containing(const Decl &decl);
  static gap::generator<UnresolvedMemberExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedMemberExpr> from(const TokenContext &c);
  static std::optional<UnresolvedMemberExpr> from(const OverloadExpr &parent);

  inline static std::optional<UnresolvedMemberExpr> from(const std::optional<OverloadExpr> &parent) {
    if (parent) {
      return UnresolvedMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedMemberExpr> from(const Expr &parent);

  inline static std::optional<UnresolvedMemberExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UnresolvedMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedMemberExpr> from(const ValueStmt &parent);

  inline static std::optional<UnresolvedMemberExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UnresolvedMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedMemberExpr> from(const Stmt &parent);

  inline static std::optional<UnresolvedMemberExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnresolvedMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Type base_type(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  bool has_unresolved_using(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

static_assert(sizeof(UnresolvedMemberExpr) == sizeof(OverloadExpr));

#endif
} // namespace mx
