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
class OMPCancellationPointDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPCancellationPointDirectiveRange = DerivedEntityRange<StmtIterator, OMPCancellationPointDirective>;
using OMPCancellationPointDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCancellationPointDirective>;
using OMPCancellationPointDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCancellationPointDirective>;

class OMPCancellationPointDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPCancellationPointDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCancellationPointDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPCancellationPointDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE;
  }

  static OMPCancellationPointDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPCancellationPointDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPCancellationPointDirective> from(const TokenContext &c);
  static std::optional<OMPCancellationPointDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPCancellationPointDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPCancellationPointDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPCancellationPointDirective> from(const Stmt &parent);

  inline static std::optional<OMPCancellationPointDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPCancellationPointDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPCancellationPointDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
