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
class OMPOrderedDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPOrderedDirectiveRange = DerivedEntityRange<StmtIterator, OMPOrderedDirective>;
using OMPOrderedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPOrderedDirective>;
using OMPOrderedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPOrderedDirective>;

class OMPOrderedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPOrderedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPOrderedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPOrderedDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ORDERED_DIRECTIVE;
  }

  static OMPOrderedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPOrderedDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPOrderedDirective> from(const TokenContext &c);
  static std::optional<OMPOrderedDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPOrderedDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPOrderedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPOrderedDirective> from(const Stmt &parent);

  inline static std::optional<OMPOrderedDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPOrderedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPOrderedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
