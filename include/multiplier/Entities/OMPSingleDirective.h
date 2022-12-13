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
class OMPExecutableDirective;
class OMPSingleDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPSingleDirectiveRange = DerivedEntityRange<StmtIterator, OMPSingleDirective>;
using OMPSingleDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPSingleDirective>;
using OMPSingleDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPSingleDirective>;

class OMPSingleDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPSingleDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPSingleDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPSingleDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SINGLE_DIRECTIVE;
  }

  static OMPSingleDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPSingleDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSingleDirective> from(const TokenContext &c);
  static std::optional<OMPSingleDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPSingleDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPSingleDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPSingleDirective> from(const Stmt &parent);

  inline static std::optional<OMPSingleDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPSingleDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPSingleDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
