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

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMaskedTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMaskedTaskLoopSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> in(const Index &index);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMaskedTaskLoopSimdDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPMaskedTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
