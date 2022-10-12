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

#include "OMPLoopTransformationDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPTileDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPTileDirectiveRange = DerivedEntityRange<StmtIterator, OMPTileDirective>;
using OMPTileDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTileDirective>;
using OMPTileDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTileDirective>;

class OMPTileDirective : public OMPLoopTransformationDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopTransformationDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTileDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTileDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPTileDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TILE_DIRECTIVE;
  }

  static OMPTileDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTileDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTileDirective> from(const TokenContext &c);
  static std::optional<OMPTileDirective> from(const OMPLoopTransformationDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPLoopTransformationDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPTileDirective> from(const Stmt &parent);

  inline static std::optional<OMPTileDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTileDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPTileDirective) == sizeof(OMPLoopTransformationDirective));

#endif
} // namespace mx
