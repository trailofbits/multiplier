// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DesignatedInitExpr;
class Designator;
class Expr;
class Stmt;
class Token;
class TokenRange;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DesignatedInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<DesignatedInitExpr> in(const Index &index);
  static gap::generator<DesignatedInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DesignatedInitExpr> by_id(const Index &, EntityId);
  static gap::generator<DesignatedInitExpr> in(const Fragment &frag);
  static gap::generator<DesignatedInitExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DESIGNATED_INIT_EXPR;
  }

  static gap::generator<DesignatedInitExpr> containing(const Decl &decl);
  static gap::generator<DesignatedInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<DesignatedInitExpr> containing(const Stmt &stmt);
  static gap::generator<DesignatedInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DesignatedInitExpr> from(const Stmt &parent);

  inline static std::optional<DesignatedInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DesignatedInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitExpr> from(const Reference &r);
  static std::optional<DesignatedInitExpr> from(const TokenContext &t);

  std::optional<Designator> nth_designator(unsigned n) const;
  unsigned num_designators(void) const;
  gap::generator<Designator> designators(void) const &;
  TokenRange designators_tokens(void) const;
  Token equal_or_colon_token(void) const;
  Expr initializer(void) const;
  bool is_direct_initializer(void) const;
  bool uses_gnu_syntax(void) const;
  std::optional<Expr> nth_sub_expression(unsigned n) const;
  unsigned num_sub_expressions(void) const;
  gap::generator<Expr> sub_expressions(void) const &;
};

static_assert(sizeof(DesignatedInitExpr) == sizeof(Expr));

#endif
} // namespace mx
