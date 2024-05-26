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
class File;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPParallelForDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPParallelForDirective> in(const Index &index);
  static gap::generator<OMPParallelForDirective> in(const Fragment &frag);
  static gap::generator<OMPParallelForDirective> in(const File &file);
  static gap::generator<OMPParallelForDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPParallelForDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPParallelForDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_FOR_DIRECTIVE;
  }

  static gap::generator<OMPParallelForDirective> containing(const Decl &decl);
  static gap::generator<OMPParallelForDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPParallelForDirective> containing(const Stmt &stmt);
  static gap::generator<OMPParallelForDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelForDirective> by_id(const Index &, EntityId);

  static std::optional<OMPParallelForDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPParallelForDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPParallelForDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPParallelForDirective> from(const Reference &r);
  static std::optional<OMPParallelForDirective> from(const VariantEntity &e);
  static std::optional<OMPParallelForDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
