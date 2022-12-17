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
class OMPParallelForDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelForDirective>;
using OMPParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelForDirective>;
using OMPParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelForDirective>;

class OMPParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPParallelForDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_FOR_DIRECTIVE;
  }

  static OMPParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPParallelForDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPParallelForDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelForDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPParallelForDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelForDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelForDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelForDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelForDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
