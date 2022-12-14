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

#include "CallExpr.h"
#include "StmtKind.h"

namespace mx {
class CUDAKernelCallExpr;
class CallExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CUDAKernelCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<CUDAKernelCallExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CUDAKernelCallExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CUDAKernelCallExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CUDA_KERNEL_CALL_EXPR;
  }

  static gap::generator<CUDAKernelCallExpr> containing(const Decl &decl);
  static gap::generator<CUDAKernelCallExpr> containing(const Stmt &stmt);

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
