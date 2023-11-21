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
class OMPParallelMasterTaskLoopSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPParallelMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> in(const Index &index);
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPParallelMasterTaskLoopSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const Reference &r);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPParallelMasterTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
