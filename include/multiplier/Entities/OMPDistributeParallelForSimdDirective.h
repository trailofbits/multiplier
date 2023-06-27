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
class OMPDistributeParallelForSimdDirective;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPDistributeParallelForSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPDistributeParallelForSimdDirective> in(const File &file);
  static gap::generator<OMPDistributeParallelForSimdDirective> in(const Index &index);
  static gap::generator<OMPDistributeParallelForSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDistributeParallelForSimdDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPDistributeParallelForSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPDistributeParallelForSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDistributeParallelForSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPDistributeParallelForSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDistributeParallelForSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPDistributeParallelForSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPDistributeParallelForSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDistributeParallelForSimdDirective> from(const Reference &r);
  static std::optional<OMPDistributeParallelForSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
