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
#include "StmtKind.h"

namespace mx {
class Expr;
class OverloadExpr;
class Stmt;
class UnresolvedLookupExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedLookupExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnresolvedLookupExpr> in(const Fragment &frag);
  static gap::generator<UnresolvedLookupExpr> in(const Index &index);
  static gap::generator<UnresolvedLookupExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedLookupExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_LOOKUP_EXPR;
  }

  static gap::generator<UnresolvedLookupExpr> containing(const Decl &decl);
  static gap::generator<UnresolvedLookupExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedLookupExpr> containing(const Stmt &stmt);
  static gap::generator<UnresolvedLookupExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<UnresolvedLookupExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<UnresolvedLookupExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<UnresolvedLookupExpr> from(const OverloadExpr &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<OverloadExpr> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const Expr &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const ValueStmt &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedLookupExpr> from(const Stmt &parent);

  inline static std::optional<UnresolvedLookupExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return UnresolvedLookupExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_overloaded(void) const;
  bool requires_adl(void) const;
};

static_assert(sizeof(UnresolvedLookupExpr) == sizeof(OverloadExpr));

#endif
} // namespace mx
