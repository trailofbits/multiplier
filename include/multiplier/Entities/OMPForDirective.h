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

#include "OMPLoopDirective.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OMPExecutableDirective;
class OMPForDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPForDirectiveRange = DerivedEntityRange<StmtIterator, OMPForDirective>;
using OMPForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPForDirective>;
using OMPForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPForDirective>;

class OMPForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPForDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_FOR_DIRECTIVE;
  }

  static OMPForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPForDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPForDirective> from(const TokenContext &c);
  static std::optional<OMPForDirective> from(const OMPLoopDirective &parent);

  inline static std::optional<OMPForDirective> from(const std::optional<OMPLoopDirective> &parent) {
    if (parent) {
      return OMPForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPForDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPForDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPForDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPForDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPForDirective> from(const Stmt &parent);

  inline static std::optional<OMPForDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPForDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPForDirective) == sizeof(OMPLoopDirective));

#endif
} // namespace mx
