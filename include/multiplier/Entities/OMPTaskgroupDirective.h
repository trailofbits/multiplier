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
class Expr;
class OMPExecutableDirective;
class OMPTaskgroupDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTaskgroupDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskgroupDirective>;
using OMPTaskgroupDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskgroupDirective>;
using OMPTaskgroupDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskgroupDirective>;

class OMPTaskgroupDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskgroupDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskgroupDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OMPTaskgroupDirective::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TASKGROUP_DIRECTIVE;
  }

  static OMPTaskgroupDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskgroupDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTaskgroupDirective> from(const TokenContext &c);
  static std::optional<OMPTaskgroupDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTaskgroupDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTaskgroupDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTaskgroupDirective> from(const Stmt &parent);

  inline static std::optional<OMPTaskgroupDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTaskgroupDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr reduction_reference(void) const;
};

static_assert(sizeof(OMPTaskgroupDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
