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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCIsaExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCIsaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCIsaExpr> in(const Fragment &frag);
  static gap::generator<ObjCIsaExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ISA_EXPR;
  }

  static gap::generator<ObjCIsaExpr> containing(const Decl &decl);
  static gap::generator<ObjCIsaExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ObjCIsaExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ObjCIsaExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ObjCIsaExpr> from(const Expr &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIsaExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIsaExpr> from(const Stmt &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token base_token_end(void) const;
  Token isa_member_token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ObjCIsaExpr) == sizeof(Expr));

#endif
} // namespace mx
