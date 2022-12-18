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
class OMPDistributeParallelForDirective;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDistributeParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPDistributeParallelForDirective>;
using OMPDistributeParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDistributeParallelForDirective>;
using OMPDistributeParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDistributeParallelForDirective>;

class OMPDistributeParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDistributeParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDistributeParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPDistributeParallelForDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
  }

  static OMPDistributeParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDistributeParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDistributeParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPDistributeParallelForDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPDistributeParallelForDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPDistributeParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDistributeParallelForDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPDistributeParallelForDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPDistributeParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDistributeParallelForDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPDistributeParallelForDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPDistributeParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDistributeParallelForDirective> from(const Stmt &parent);

  inline static std::optional<OMPDistributeParallelForDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPDistributeParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPDistributeParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
