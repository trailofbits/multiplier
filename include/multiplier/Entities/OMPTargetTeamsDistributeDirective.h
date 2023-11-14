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
class OMPTargetTeamsDistributeDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetTeamsDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const Index &index);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetTeamsDistributeDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetTeamsDistributeDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE;
  }

  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetTeamsDistributeDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTargetTeamsDistributeDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTargetTeamsDistributeDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const Reference &r);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const VariantEntity &e);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetTeamsDistributeDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
