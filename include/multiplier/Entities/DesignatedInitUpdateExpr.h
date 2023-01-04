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
class DesignatedInitUpdateExpr;
class Expr;
class InitListExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DesignatedInitUpdateExprRange = DerivedEntityRange<StmtIterator, DesignatedInitUpdateExpr>;
using DesignatedInitUpdateExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DesignatedInitUpdateExpr>;
using DesignatedInitUpdateExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DesignatedInitUpdateExpr>;

class DesignatedInitUpdateExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DesignatedInitUpdateExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DesignatedInitUpdateExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DesignatedInitUpdateExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
  }

  static DesignatedInitUpdateExprContainingStmtRange containing(const Decl &decl);
  static DesignatedInitUpdateExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DesignatedInitUpdateExpr> from(const TokenContext &c);
  static std::optional<DesignatedInitUpdateExpr> from(const Expr &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitUpdateExpr> from(const ValueStmt &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DesignatedInitUpdateExpr> from(const Stmt &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  InitListExpr updater(void) const;
};

static_assert(sizeof(DesignatedInitUpdateExpr) == sizeof(Expr));

#endif
} // namespace mx
