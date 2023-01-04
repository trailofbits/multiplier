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
class OMPTeamsGenericLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTeamsGenericLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsGenericLoopDirective>;
using OMPTeamsGenericLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsGenericLoopDirective>;
using OMPTeamsGenericLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsGenericLoopDirective>;

class OMPTeamsGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsGenericLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsGenericLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPTeamsGenericLoopDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TEAMS_GENERIC_LOOP_DIRECTIVE;
  }

  static OMPTeamsGenericLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsGenericLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTeamsGenericLoopDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsGenericLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTeamsGenericLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTeamsGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsGenericLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTeamsGenericLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTeamsGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsGenericLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTeamsGenericLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTeamsGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsGenericLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPTeamsGenericLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTeamsGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTeamsGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
