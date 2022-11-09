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
class OMPParallelMaskedTaskLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelMaskedTaskLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMaskedTaskLoopDirective>;
using OMPParallelMaskedTaskLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMaskedTaskLoopDirective>;
using OMPParallelMaskedTaskLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMaskedTaskLoopDirective>;

class OMPParallelMaskedTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMaskedTaskLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMaskedTaskLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPParallelMaskedTaskLoopDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASKED_TASK_LOOP_DIRECTIVE;
  }

  static OMPParallelMaskedTaskLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMaskedTaskLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMaskedTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMaskedTaskLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPParallelMaskedTaskLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPParallelMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMaskedTaskLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPParallelMaskedTaskLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPParallelMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMaskedTaskLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelMaskedTaskLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMaskedTaskLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelMaskedTaskLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelMaskedTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelMaskedTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
