// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OverloadExpr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class OverloadExpr;
class Stmt;
class Token;
class Type;
class UnresolvedMemberExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedMemberExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnresolvedMemberExpr> in(const Index &index);
  static gap::generator<UnresolvedMemberExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedMemberExpr> by_id(const Index &, EntityId);
  static gap::generator<UnresolvedMemberExpr> in(const Fragment &frag);
  static gap::generator<UnresolvedMemberExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_MEMBER_EXPR;
  }

  static gap::generator<UnresolvedMemberExpr> containing(const Decl &decl);
  static gap::generator<UnresolvedMemberExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedMemberExpr> containing(const Stmt &stmt);
  static gap::generator<UnresolvedMemberExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedMemberExpr> from(const Stmt &parent);

  inline static std::optional<UnresolvedMemberExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnresolvedMemberExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedMemberExpr> from(const Reference &r);
  static std::optional<UnresolvedMemberExpr> from(const TokenContext &t);

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
