// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPParallelMaskedTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const Index &index);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const File &file);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPParallelMaskedTaskLoopSimdDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> by_id(const Index &, EntityId);

  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const Reference &r);
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPParallelMaskedTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
