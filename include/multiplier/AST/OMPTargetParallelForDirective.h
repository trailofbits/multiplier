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
class Expr;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTargetParallelForDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPTargetParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetParallelForDirective> in(const Index &index);
  static gap::generator<OMPTargetParallelForDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetParallelForDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPTargetParallelForDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetParallelForDirective> in(const File &file);

  static std::optional<OMPTargetParallelForDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPTargetParallelForDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE;
  }

  static gap::generator<OMPTargetParallelForDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetParallelForDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetParallelForDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetParallelForDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetParallelForDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPTargetParallelForDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPTargetParallelForDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPTargetParallelForDirective> from(const Reference &r);
  static std::optional<OMPTargetParallelForDirective> from(const VariantEntity &e);
  static std::optional<OMPTargetParallelForDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTargetParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
