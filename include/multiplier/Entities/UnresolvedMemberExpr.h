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

#include "OverloadExpr.h"

namespace mx {
class Decl;
class Expr;
class OverloadExpr;
class Stmt;
class Token;
class Type;
class UnresolvedMemberExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedMemberExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnresolvedMemberExpr> in(const Fragment &frag);
  static gap::generator<UnresolvedMemberExpr> in(const File &file);
  static gap::generator<UnresolvedMemberExpr> in(const Index &index);
  static gap::generator<UnresolvedMemberExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedMemberExpr> by_id(const Index &, EntityId);

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

  inline static std::optional<UnresolvedMemberExpr> from(const Reference &r) {
    return UnresolvedMemberExpr::from(r.as_statement());
  }

  inline static std::optional<UnresolvedMemberExpr> from(const TokenContext &t) {
    return UnresolvedMemberExpr::from(t.as_statement());
  }

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
