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

#include "OMPLoopTransformationDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPUnrollDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPUnrollDirective : public OMPLoopTransformationDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopTransformationDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static gap::generator<OMPUnrollDirective> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OMPUnrollDirective> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPUnrollDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_UNROLL_DIRECTIVE;
  }

  static gap::generator<OMPUnrollDirective> containing(const Decl &decl);
  static gap::generator<OMPUnrollDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPUnrollDirective> from(const TokenContext &c);
  static std::optional<OMPUnrollDirective> from(const OMPLoopTransformationDirective &parent);

  inline static std::optional<OMPUnrollDirective> from(const std::optional<OMPLoopTransformationDirective> &parent) {
    if (parent) {
      return OMPUnrollDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPUnrollDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPUnrollDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPUnrollDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPUnrollDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPUnrollDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPUnrollDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPUnrollDirective> from(const Stmt &parent);

  inline static std::optional<OMPUnrollDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPUnrollDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPUnrollDirective) == sizeof(OMPLoopTransformationDirective));

#endif
} // namespace mx
