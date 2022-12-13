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
class OMPTargetDataDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetDataDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetDataDirective>;
using OMPTargetDataDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetDataDirective>;
using OMPTargetDataDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetDataDirective>;

class OMPTargetDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetDataDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetDataDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPTargetDataDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_DATA_DIRECTIVE;
  }

  static OMPTargetDataDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetDataDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetDataDirective> from(const TokenContext &c);
  static std::optional<OMPTargetDataDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetDataDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetDataDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetDataDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetDataDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetDataDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetDataDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
