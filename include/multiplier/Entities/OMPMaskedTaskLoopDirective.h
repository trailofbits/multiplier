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
class OMPMaskedTaskLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPMaskedTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPMaskedTaskLoopDirective> in(const Index &index);
  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPMaskedTaskLoopDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPMaskedTaskLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPMaskedTaskLoopDirective> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_MASKED_TASK_LOOP_DIRECTIVE;
  }

  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPMaskedTaskLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPMaskedTaskLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPMaskedTaskLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPMaskedTaskLoopDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPMaskedTaskLoopDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPMaskedTaskLoopDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPMaskedTaskLoopDirective> from(const Reference &r);
  static std::optional<OMPMaskedTaskLoopDirective> from(const VariantEntity &e);
  static std::optional<OMPMaskedTaskLoopDirective> from(const TokenContext &t);

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPMaskedTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
