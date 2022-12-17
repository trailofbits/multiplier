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
class OMPTargetUpdateDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetUpdateDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetUpdateDirective>;
using OMPTargetUpdateDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetUpdateDirective>;
using OMPTargetUpdateDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetUpdateDirective>;

class OMPTargetUpdateDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetUpdateDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetUpdateDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPTargetUpdateDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_UPDATE_DIRECTIVE;
  }

  static OMPTargetUpdateDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetUpdateDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetUpdateDirective> from(const TokenContext &c);
  static std::optional<OMPTargetUpdateDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetUpdateDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetUpdateDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetUpdateDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetUpdateDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetUpdateDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetUpdateDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
