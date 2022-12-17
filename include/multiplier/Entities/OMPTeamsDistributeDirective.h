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
class OMPTeamsDistributeDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTeamsDistributeDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDistributeDirective>;
using OMPTeamsDistributeDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDistributeDirective>;
using OMPTeamsDistributeDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDistributeDirective>;

class OMPTeamsDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDistributeDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDistributeDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPTeamsDistributeDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE;
  }

  static OMPTeamsDistributeDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDistributeDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDistributeDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPTeamsDistributeDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPTeamsDistributeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsDistributeDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTeamsDistributeDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTeamsDistributeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsDistributeDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTeamsDistributeDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTeamsDistributeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTeamsDistributeDirective> from(const Stmt &parent);

  inline static std::optional<OMPTeamsDistributeDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTeamsDistributeDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTeamsDistributeDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
