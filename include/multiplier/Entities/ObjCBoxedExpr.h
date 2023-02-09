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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCBoxedExpr;
class ObjCMethodDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCBoxedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCBoxedExpr> in(const Fragment &frag);
  static gap::generator<ObjCBoxedExpr> in(const Index &index);
  static gap::generator<ObjCBoxedExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCBoxedExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BOXED_EXPR;
  }

  static gap::generator<ObjCBoxedExpr> containing(const Decl &decl);
  static gap::generator<ObjCBoxedExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCBoxedExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCBoxedExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ObjCBoxedExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ObjCBoxedExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ObjCBoxedExpr> from(const Expr &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoxedExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoxedExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBoxedExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBoxedExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  ObjCMethodDecl boxing_method(void) const;
  Expr sub_expression(void) const;
  bool is_expressible_as_constant_initializer(void) const;
};

static_assert(sizeof(ObjCBoxedExpr) == sizeof(Expr));

#endif
} // namespace mx
