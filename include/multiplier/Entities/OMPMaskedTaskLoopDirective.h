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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedTaskLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMaskedTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMaskedTaskLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASKED_TASK_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<OMPMaskedTaskLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPMaskedTaskLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPMaskedTaskLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPMaskedTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
