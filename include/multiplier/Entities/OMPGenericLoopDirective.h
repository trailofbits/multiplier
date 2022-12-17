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
class OMPGenericLoopDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPGenericLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPGenericLoopDirective>;
using OMPGenericLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPGenericLoopDirective>;
using OMPGenericLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPGenericLoopDirective>;

class OMPGenericLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPGenericLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPGenericLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPGenericLoopDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_GENERIC_LOOP_DIRECTIVE;
  }

  static OMPGenericLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPGenericLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPGenericLoopDirective> from(const TokenContext &c);
  static std::optional<OMPGenericLoopDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPGenericLoopDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPGenericLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPGenericLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPGenericLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPGenericLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPGenericLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPGenericLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPGenericLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPGenericLoopDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
