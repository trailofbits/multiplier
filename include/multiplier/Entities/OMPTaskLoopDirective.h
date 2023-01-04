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
class OMPTaskLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTaskLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskLoopDirective>;
using OMPTaskLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskLoopDirective>;
using OMPTaskLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskLoopDirective>;

class OMPTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPTaskLoopDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TASK_LOOP_DIRECTIVE;
  }

  static OMPTaskLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPTaskLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTaskLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTaskLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTaskLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTaskLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTaskLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTaskLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPTaskLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTaskLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTaskLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
