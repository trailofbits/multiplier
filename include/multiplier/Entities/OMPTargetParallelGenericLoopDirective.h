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

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTargetParallelGenericLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetParallelGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static gap::generator<OMPTargetParallelGenericLoopDirective> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPTargetParallelGenericLoopDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetParallelGenericLoopDirective> from(const TokenContext &c);
  static std::optional<OMPTargetParallelGenericLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTargetParallelGenericLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTargetParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelGenericLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTargetParallelGenericLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTargetParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelGenericLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetParallelGenericLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelGenericLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetParallelGenericLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetParallelGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
