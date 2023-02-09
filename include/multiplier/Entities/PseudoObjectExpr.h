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
class PseudoObjectExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PseudoObjectExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<PseudoObjectExpr> in(const Fragment &frag);
  static gap::generator<PseudoObjectExpr> in(const Index &index);
  static gap::generator<PseudoObjectExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PseudoObjectExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PSEUDO_OBJECT_EXPR;
  }

  static gap::generator<PseudoObjectExpr> containing(const Decl &decl);
  static gap::generator<PseudoObjectExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<PseudoObjectExpr> containing(const Stmt &stmt);
  static gap::generator<PseudoObjectExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<PseudoObjectExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<PseudoObjectExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<PseudoObjectExpr> from(const Expr &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PseudoObjectExpr> from(const ValueStmt &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PseudoObjectExpr> from(const Stmt &parent);

  inline static std::optional<PseudoObjectExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return PseudoObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr result_expression(void) const;
  Expr syntactic_form(void) const;
  std::optional<Expr> nth_semantic(unsigned n) const;
  gap::generator<Expr> semantics(void) const;
  std::optional<Expr> nth_semantic_expression(unsigned n) const;
  gap::generator<Expr> semantic_expressions(void) const;
};

static_assert(sizeof(PseudoObjectExpr) == sizeof(Expr));

#endif
} // namespace mx
