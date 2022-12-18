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

#include "OMPLoopBasedDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPLoopTransformationDirectiveRange = DerivedEntityRange<StmtIterator, OMPLoopTransformationDirective>;
using OMPLoopTransformationDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPLoopTransformationDirective>;
using OMPLoopTransformationDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPLoopTransformationDirective>;

class OMPLoopTransformationDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPLoopTransformationDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPLoopTransformationDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPLoopTransformationDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static OMPLoopTransformationDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPLoopTransformationDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopTransformationDirective> from(const TokenContext &c);
  static std::optional<OMPLoopTransformationDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopTransformationDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopTransformationDirective> from(const Stmt &parent);

  inline static std::optional<OMPLoopTransformationDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPLoopTransformationDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt pre_initializers(void) const;
  Stmt transformed_statement(void) const;
};

static_assert(sizeof(OMPLoopTransformationDirective) == sizeof(OMPLoopBasedDirective));

#endif
} // namespace mx
