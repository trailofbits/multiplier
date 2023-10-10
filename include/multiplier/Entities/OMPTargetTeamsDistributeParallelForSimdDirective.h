// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPLoopDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> in(const Index &index);
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetTeamsDistributeParallelForSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetTeamsDistributeParallelForSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const Reference &r);
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetTeamsDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
