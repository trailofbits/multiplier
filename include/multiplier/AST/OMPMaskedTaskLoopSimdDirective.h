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
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPMaskedTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMaskedTaskLoopSimdDirective> in(const Index &index);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMaskedTaskLoopSimdDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> in(const Fragment &frag);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> in(const File &file);

  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<OMPMaskedTaskLoopSimdDirective, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Decl &decl);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMaskedTaskLoopSimdDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMaskedTaskLoopSimdDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPMaskedTaskLoopSimdDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const Reference &r);
  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const VariantEntity &e);
  static std::optional<OMPMaskedTaskLoopSimdDirective> from(const TokenContext &t);

};

static_assert(sizeof(OMPMaskedTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
