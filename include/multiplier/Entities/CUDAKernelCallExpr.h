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

#include "CallExpr.h"
#include "StmtKind.h"

namespace mx {
class CUDAKernelCallExpr;
class CallExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CUDAKernelCallExprRange = DerivedEntityRange<StmtIterator, CUDAKernelCallExpr>;
using CUDAKernelCallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CUDAKernelCallExpr>;
using CUDAKernelCallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CUDAKernelCallExpr>;

class CUDAKernelCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CUDAKernelCallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CUDAKernelCallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : CUDAKernelCallExpr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CUDA_KERNEL_CALL_EXPR;
  }

  static CUDAKernelCallExprContainingStmtRange containing(const Decl &decl);
  static CUDAKernelCallExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CUDAKernelCallExpr> from(const TokenContext &c);
  static std::optional<CUDAKernelCallExpr> from(const CallExpr &parent);

  inline static std::optional<CUDAKernelCallExpr> from(const std::optional<CallExpr> &parent) {
    if (parent) {
      return CUDAKernelCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CUDAKernelCallExpr> from(const Expr &parent);

  inline static std::optional<CUDAKernelCallExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CUDAKernelCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CUDAKernelCallExpr> from(const ValueStmt &parent);

  inline static std::optional<CUDAKernelCallExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CUDAKernelCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CUDAKernelCallExpr> from(const Stmt &parent);

  inline static std::optional<CUDAKernelCallExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CUDAKernelCallExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CallExpr config(void) const;
};

static_assert(sizeof(CUDAKernelCallExpr) == sizeof(CallExpr));

#endif
} // namespace mx
