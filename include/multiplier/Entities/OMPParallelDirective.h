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
class OMPParallelDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelDirective>;
using OMPParallelDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelDirective>;
using OMPParallelDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelDirective>;

class OMPParallelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPParallelDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_DIRECTIVE;
  }

  static OMPParallelDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelDirective> from(const TokenContext &c);
  static std::optional<OMPParallelDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPParallelDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
