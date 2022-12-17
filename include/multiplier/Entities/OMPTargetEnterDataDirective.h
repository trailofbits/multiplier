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
class OMPTargetEnterDataDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTargetEnterDataDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetEnterDataDirective>;
using OMPTargetEnterDataDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetEnterDataDirective>;
using OMPTargetEnterDataDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetEnterDataDirective>;

class OMPTargetEnterDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetEnterDataDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetEnterDataDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPTargetEnterDataDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE;
  }

  static OMPTargetEnterDataDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetEnterDataDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetEnterDataDirective> from(const TokenContext &c);
  static std::optional<OMPTargetEnterDataDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTargetEnterDataDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTargetEnterDataDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTargetEnterDataDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetEnterDataDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetEnterDataDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTargetEnterDataDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
