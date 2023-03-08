// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPExecutableDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPDistributeDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeSimdDirective;
class OMPExecutableDirective;
class OMPForDirective;
class OMPForSimdDirective;
class OMPGenericLoopDirective;
class OMPLoopBasedDirective;
class OMPMaskedTaskLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelGenericLoopDirective;
class OMPParallelMaskedTaskLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPSimdDirective;
class OMPTargetParallelForDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetParallelGenericLoopDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetTeamsGenericLoopDirective;
class OMPTaskLoopDirective;
class OMPTaskLoopSimdDirective;
class OMPTeamsDistributeDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeSimdDirective;
class OMPTeamsGenericLoopDirective;
class OMPTileDirective;
class OMPUnrollDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPLoopBasedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPLoopBasedDirective> in(const Fragment &frag);
  static gap::generator<OMPLoopBasedDirective> in(const File &file);
  static gap::generator<OMPLoopBasedDirective> in(const Index &index);
  static gap::generator<OMPLoopBasedDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPLoopBasedDirective> by_id(const Index &, EntityId);

  static gap::generator<OMPLoopBasedDirective> containing(const Decl &decl);
  static gap::generator<OMPLoopBasedDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPLoopBasedDirective> containing(const Stmt &stmt);
  static gap::generator<OMPLoopBasedDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopBasedDirective> from(const Stmt &parent);

  inline static std::optional<OMPLoopBasedDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPLoopBasedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopBasedDirective> from(const Reference &r);
  static std::optional<OMPLoopBasedDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPLoopBasedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
