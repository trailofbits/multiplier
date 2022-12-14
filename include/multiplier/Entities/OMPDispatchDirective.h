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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPDispatchDirective;
class OMPExecutableDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDispatchDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDispatchDirective>;
using OMPDispatchDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDispatchDirective>;

class OMPDispatchDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static gap::generator<OMPDispatchDirective> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static OMPDispatchDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPDispatchDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_DISPATCH_DIRECTIVE;
  }

  static OMPDispatchDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDispatchDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPDispatchDirective> from(const TokenContext &c);
  static std::optional<OMPDispatchDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPDispatchDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPDispatchDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDispatchDirective> from(const Stmt &parent);

  inline static std::optional<OMPDispatchDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPDispatchDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token target_call_token(void) const;
};

static_assert(sizeof(OMPDispatchDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
