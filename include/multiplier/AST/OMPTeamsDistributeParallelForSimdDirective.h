// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPLoopDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> in(const Index &index);
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPTeamsDistributeParallelForSimdDirective, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTeamsDistributeParallelForSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const Reference &r);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTeamsDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
