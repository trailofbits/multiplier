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

namespace mx {
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMasterTaskLoopDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMasterTaskLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPMasterTaskLoopDirective> in(const File &file);
  static gap::generator<OMPMasterTaskLoopDirective> in(const Index &index);
  static gap::generator<OMPMasterTaskLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMasterTaskLoopDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPMasterTaskLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPMasterTaskLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMasterTaskLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMasterTaskLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMasterTaskLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPMasterTaskLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPMasterTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPMasterTaskLoopDirective> from(const Reference &r) {
    return OMPMasterTaskLoopDirective::from(r.as_statement());
  }

  inline static std::optional<OMPMasterTaskLoopDirective> from(const TokenContext &t) {
    return OMPMasterTaskLoopDirective::from(t.as_statement());
  }

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPMasterTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
