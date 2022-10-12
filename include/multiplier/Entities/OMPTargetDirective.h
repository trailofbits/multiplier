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
class OMPTargetDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetDirective>;
using OMPTargetDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetDirective>;
using OMPTargetDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetDirective>;

class OMPTargetDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPTargetDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_DIRECTIVE;
  }

  static OMPTargetDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetDirective> from(const TokenContext &c);
  static std::optional<OMPTargetDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
