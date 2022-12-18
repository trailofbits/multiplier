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
class OMPParallelGenericLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelGenericLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelGenericLoopDirective>;
using OMPParallelGenericLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelGenericLoopDirective>;
using OMPParallelGenericLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelGenericLoopDirective>;

class OMPParallelGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelGenericLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelGenericLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPParallelGenericLoopDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_GENERIC_LOOP_DIRECTIVE;
  }

  static OMPParallelGenericLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelGenericLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelGenericLoopDirective> from(const TokenContext &c);
  static std::optional<OMPParallelGenericLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPParallelGenericLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelGenericLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPParallelGenericLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelGenericLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelGenericLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelGenericLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelGenericLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPParallelGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
