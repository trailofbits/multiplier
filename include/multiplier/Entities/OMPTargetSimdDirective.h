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
class OMPTargetSimdDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetSimdDirective>;
using OMPTargetSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetSimdDirective>;
using OMPTargetSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetSimdDirective>;

class OMPTargetSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPTargetSimdDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_SIMD_DIRECTIVE;
  }

  static OMPTargetSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTargetSimdDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTargetSimdDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTargetSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetSimdDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTargetSimdDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTargetSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetSimdDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetSimdDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetSimdDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetSimdDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetSimdDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetSimdDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
