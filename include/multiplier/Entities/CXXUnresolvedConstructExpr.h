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
class CXXUnresolvedConstructExpr;
class Expr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXUnresolvedConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXUnresolvedConstructExpr> in(const Fragment &frag);
  static gap::generator<CXXUnresolvedConstructExpr> in(const Index &index);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXUnresolvedConstructExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
  }

  static gap::generator<CXXUnresolvedConstructExpr> containing(const Decl &decl);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXUnresolvedConstructExpr> containing(const Stmt &stmt);
  static gap::generator<CXXUnresolvedConstructExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<CXXUnresolvedConstructExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<CXXUnresolvedConstructExpr> from(const Expr &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUnresolvedConstructExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUnresolvedConstructExpr> from(const Stmt &parent);

  inline static std::optional<CXXUnresolvedConstructExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXUnresolvedConstructExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> nth_argument(unsigned n) const;
  gap::generator<Expr> arguments(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Type type_as_written(void) const;
  bool is_list_initialization(void) const;
};

static_assert(sizeof(CXXUnresolvedConstructExpr) == sizeof(Expr));

#endif
} // namespace mx
