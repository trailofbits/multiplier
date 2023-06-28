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
class Expr;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetTeamsDistributeParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> in(const File &file);
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> in(const Index &index);
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
  }

  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetTeamsDistributeParallelForDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetTeamsDistributeParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const Reference &r);
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTargetTeamsDistributeParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
