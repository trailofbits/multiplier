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
class OMPTargetParallelGenericLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetParallelGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetParallelGenericLoopDirective> in(const Index &index);
  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetParallelGenericLoopDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetParallelGenericLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetParallelGenericLoopDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetParallelGenericLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetParallelGenericLoopDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTargetParallelGenericLoopDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTargetParallelGenericLoopDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTargetParallelGenericLoopDirective> from(const Reference &r);
  static std::optional<OMPTargetParallelGenericLoopDirective> from(const VariantEntity &e);
  static std::optional<OMPTargetParallelGenericLoopDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPTargetParallelGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
