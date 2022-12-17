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
class OMPLoopBasedDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPLoopBasedDirectiveRange = DerivedEntityRange<StmtIterator, OMPLoopBasedDirective>;
using OMPLoopBasedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPLoopBasedDirective>;
using OMPLoopBasedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPLoopBasedDirective>;

class OMPLoopBasedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPLoopBasedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPLoopBasedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPLoopBasedDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  static OMPLoopBasedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPLoopBasedDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopBasedDirective> from(const TokenContext &c);
  static std::optional<OMPLoopBasedDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPLoopBasedDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPLoopBasedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopBasedDirective> from(const Stmt &parent);

  inline static std::optional<OMPLoopBasedDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPLoopBasedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPLoopBasedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
