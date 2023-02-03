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

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMasterTaskLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static gap::generator<OMPMasterTaskLoopDirective> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OMPMasterTaskLoopDirective> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPMasterTaskLoopDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPMasterTaskLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPMasterTaskLoopDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMasterTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPMasterTaskLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPMasterTaskLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPMasterTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMasterTaskLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPMasterTaskLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPMasterTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMasterTaskLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPMasterTaskLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPMasterTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMasterTaskLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPMasterTaskLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMasterTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPMasterTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
