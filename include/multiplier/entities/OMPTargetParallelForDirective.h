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
class Expr;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPTargetParallelForDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetParallelForDirective>;
using OMPTargetParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetParallelForDirective>;
using OMPTargetParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetParallelForDirective>;

class OMPTargetParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPTargetParallelForDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE;
  }

  static OMPTargetParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPTargetParallelForDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTargetParallelForDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTargetParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelForDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTargetParallelForDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTargetParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelForDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetParallelForDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetParallelForDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetParallelForDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTargetParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
