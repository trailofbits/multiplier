// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelMasterTaskLoopSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMasterTaskLoopSimdDirective>;
using OMPParallelMasterTaskLoopSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMasterTaskLoopSimdDirective>;
using OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMasterTaskLoopSimdDirective>;

class OMPParallelMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMasterTaskLoopSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMasterTaskLoopSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPParallelMasterTaskLoopSimdDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
  }

  static OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPParallelMasterTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPParallelMasterTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelMasterTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelMasterTaskLoopSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPParallelMasterTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
