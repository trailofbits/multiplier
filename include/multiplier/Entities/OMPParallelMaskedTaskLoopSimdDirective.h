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
class OMPParallelMaskedTaskLoopSimdDirective;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPParallelMaskedTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const File &file);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> in(const Index &index);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPParallelMaskedTaskLoopSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelMaskedTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const Reference &r);
  static std::optional<OMPParallelMaskedTaskLoopSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPParallelMaskedTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
