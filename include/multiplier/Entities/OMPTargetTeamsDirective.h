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

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPTargetTeamsDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetTeamsDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDirective>;
using OMPTargetTeamsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDirective>;
using OMPTargetTeamsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDirective>;

class OMPTargetTeamsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPTargetTeamsDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_TEAMS_DIRECTIVE;
  }

  static OMPTargetTeamsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetTeamsDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetTeamsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetTeamsDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetTeamsDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetTeamsDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetTeamsDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
