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
#include "StmtUseSelector.h"

namespace mx {
class Expr;
class FieldDecl;
class InitListExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InitListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<InitListExpr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<InitListExpr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : InitListExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INIT_LIST_EXPR;
  }

  static gap::generator<InitListExpr> containing(const Decl &decl);
  static gap::generator<InitListExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<InitListExpr> from(const TokenContext &c);
  static std::optional<InitListExpr> from(const Expr &parent);

  inline static std::optional<InitListExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return InitListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<InitListExpr> from(const ValueStmt &parent);

  inline static std::optional<InitListExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return InitListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<InitListExpr> from(const Stmt &parent);

  inline static std::optional<InitListExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return InitListExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> array_filler(void) const;
  std::optional<FieldDecl> initialized_field_in_union(void) const;
  Token l_brace_token(void) const;
  Token r_brace_token(void) const;
  std::optional<InitListExpr> semantic_form(void) const;
  std::optional<InitListExpr> syntactic_form(void) const;
  bool had_array_range_designator(void) const;
  bool has_array_filler(void) const;
  std::vector<Expr> initializers(void) const;
  bool is_explicit(void) const;
  bool is_semantic_form(void) const;
  bool is_string_literal_initializer(void) const;
  bool is_syntactic_form(void) const;
  std::optional<bool> is_transparent(void) const;
};

static_assert(sizeof(InitListExpr) == sizeof(Expr));

#endif
} // namespace mx
