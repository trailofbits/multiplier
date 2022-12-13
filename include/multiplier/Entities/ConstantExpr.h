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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "ConstantExprResultStorageKind.h"
#include "FullExpr.h"
#include "StmtKind.h"

namespace mx {
class ConstantExpr;
class Expr;
class FullExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConstantExprRange = DerivedEntityRange<StmtIterator, ConstantExpr>;
using ConstantExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstantExpr>;
using ConstantExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConstantExpr>;

class ConstantExpr : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConstantExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstantExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConstantExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONSTANT_EXPR;
  }

  static ConstantExprContainingStmtRange containing(const Decl &decl);
  static ConstantExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConstantExpr> from(const TokenContext &c);
  static std::optional<ConstantExpr> from(const FullExpr &parent);

  inline static std::optional<ConstantExpr> from(const std::optional<FullExpr> &parent) {
    if (parent) {
      return ConstantExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantExpr> from(const Expr &parent);

  inline static std::optional<ConstantExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ConstantExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantExpr> from(const ValueStmt &parent);

  inline static std::optional<ConstantExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ConstantExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantExpr> from(const Stmt &parent);

  inline static std::optional<ConstantExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ConstantExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ConstantExprResultStorageKind result_storage_kind(void) const;
  bool has_ap_value_result(void) const;
  bool is_immediate_invocation(void) const;
};

static_assert(sizeof(ConstantExpr) == sizeof(FullExpr));

#endif
} // namespace mx
