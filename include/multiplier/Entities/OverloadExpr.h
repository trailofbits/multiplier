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

#include "DeclUseSelector.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXRecordDecl;
class Expr;
class OverloadExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OverloadExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<OverloadExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OverloadExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OverloadExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static gap::generator<OverloadExpr> containing(const Decl &decl);
  static gap::generator<OverloadExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OverloadExpr> from(const TokenContext &c);
  static std::optional<OverloadExpr> from(const Expr &parent);

  inline static std::optional<OverloadExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return OverloadExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OverloadExpr> from(const ValueStmt &parent);

  inline static std::optional<OverloadExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return OverloadExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OverloadExpr> from(const Stmt &parent);

  inline static std::optional<OverloadExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OverloadExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token l_angle_token(void) const;
  Token name_token(void) const;
  std::optional<CXXRecordDecl> naming_class(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

static_assert(sizeof(OverloadExpr) == sizeof(Expr));

#endif
} // namespace mx
