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
class OMPCriticalDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPCriticalDirectiveRange = DerivedEntityRange<StmtIterator, OMPCriticalDirective>;
using OMPCriticalDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCriticalDirective>;
using OMPCriticalDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCriticalDirective>;

class OMPCriticalDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPCriticalDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCriticalDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPCriticalDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CRITICAL_DIRECTIVE;
  }

  static OMPCriticalDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPCriticalDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCriticalDirective> from(const TokenContext &c);
  static std::optional<OMPCriticalDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPCriticalDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPCriticalDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPCriticalDirective> from(const Stmt &parent);

  inline static std::optional<OMPCriticalDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPCriticalDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPCriticalDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
