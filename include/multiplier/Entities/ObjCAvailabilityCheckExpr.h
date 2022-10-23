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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCAvailabilityCheckExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCAvailabilityCheckExprRange = DerivedEntityRange<StmtIterator, ObjCAvailabilityCheckExpr>;
using ObjCAvailabilityCheckExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAvailabilityCheckExpr>;
using ObjCAvailabilityCheckExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAvailabilityCheckExpr>;

class ObjCAvailabilityCheckExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCAvailabilityCheckExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAvailabilityCheckExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCAvailabilityCheckExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR;
  }

  static ObjCAvailabilityCheckExprContainingStmtRange containing(const Decl &decl);
  static ObjCAvailabilityCheckExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAvailabilityCheckExpr> from(const TokenContext &c);
  static std::optional<ObjCAvailabilityCheckExpr> from(const Expr &parent);

  inline static std::optional<ObjCAvailabilityCheckExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCAvailabilityCheckExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAvailabilityCheckExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCAvailabilityCheckExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCAvailabilityCheckExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCAvailabilityCheckExpr> from(const Stmt &parent);

  inline static std::optional<ObjCAvailabilityCheckExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCAvailabilityCheckExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_version(void) const;
};

static_assert(sizeof(ObjCAvailabilityCheckExpr) == sizeof(Expr));

#endif
} // namespace mx