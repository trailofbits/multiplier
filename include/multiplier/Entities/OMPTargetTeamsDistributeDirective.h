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
class OMPTargetTeamsDistributeDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetTeamsDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const File &file);
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const Index &index);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetTeamsDistributeDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE;
  }

  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetTeamsDistributeDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetTeamsDistributeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPTargetTeamsDistributeDirective> from(const Reference &r) {
    return OMPTargetTeamsDistributeDirective::from(r.as_statement());
  }

  inline static std::optional<OMPTargetTeamsDistributeDirective> from(const TokenContext &t) {
    return OMPTargetTeamsDistributeDirective::from(t.as_statement());
  }

};

static_assert(sizeof(OMPTargetTeamsDistributeDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
