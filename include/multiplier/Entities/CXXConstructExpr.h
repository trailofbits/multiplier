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

#include "CXXConstructExprConstructionKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXConstructExpr;
class CXXConstructorDecl;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXConstructExpr> in(const Fragment &frag);
  static gap::generator<CXXConstructExpr> in(const Index &index);
  static gap::generator<CXXConstructExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CXXConstructExpr> by(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CONSTRUCT_EXPR;
  }

  static gap::generator<CXXConstructExpr> containing(const Decl &decl);
  static gap::generator<CXXConstructExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXConstructExpr> containing(const Stmt &stmt);
  static gap::generator<CXXConstructExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXConstructExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXConstructExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXConstructExpr> from(const Expr &parent);

  inline static std::optional<CXXConstructExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConstructExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXConstructExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConstructExpr> from(const Stmt &parent);

  inline static std::optional<CXXConstructExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> nth_argument(unsigned n) const;
  gap::generator<Expr> arguments(void) const;
  CXXConstructExprConstructionKind construction_kind(void) const;
  CXXConstructorDecl constructor(void) const;
  Token token(void) const;
  TokenRange parenthesis_or_brace_range(void) const;
  bool had_multiple_candidates(void) const;
  bool is_elidable(void) const;
  bool is_list_initialization(void) const;
  bool is_std_initializer_list_initialization(void) const;
  bool requires_zero_initialization(void) const;
};

static_assert(sizeof(CXXConstructExpr) == sizeof(Expr));

#endif
} // namespace mx
