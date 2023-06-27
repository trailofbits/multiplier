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
class OMPTargetTeamsDistributeSimdDirective;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetTeamsDistributeSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> in(const File &file);
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> in(const Index &index);
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetTeamsDistributeSimdDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPTargetTeamsDistributeSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetTeamsDistributeSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetTeamsDistributeSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetTeamsDistributeSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const Reference &r);
  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetTeamsDistributeSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
