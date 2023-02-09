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
class ObjCBoolLiteralExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCBoolLiteralExpr> in(const Fragment &frag);
  static gap::generator<ObjCBoolLiteralExpr> in(const Index &index);
  static gap::generator<ObjCBoolLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCBoolLiteralExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BOOL_LITERAL_EXPR;
  }

  static gap::generator<ObjCBoolLiteralExpr> containing(const Decl &decl);
  static gap::generator<ObjCBoolLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCBoolLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCBoolLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ObjCBoolLiteralExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ObjCBoolLiteralExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ObjCBoolLiteralExpr> from(const Expr &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoolLiteralExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBoolLiteralExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBoolLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBoolLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token token(void) const;
  bool value(void) const;
};

static_assert(sizeof(ObjCBoolLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
