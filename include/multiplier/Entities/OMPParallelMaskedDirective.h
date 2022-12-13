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
class Expr;
class OMPExecutableDirective;
class OMPParallelMaskedDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelMaskedDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMaskedDirective>;
using OMPParallelMaskedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMaskedDirective>;
using OMPParallelMaskedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMaskedDirective>;

class OMPParallelMaskedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMaskedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMaskedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPParallelMaskedDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASKED_DIRECTIVE;
  }

  static OMPParallelMaskedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMaskedDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMaskedDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMaskedDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelMaskedDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelMaskedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMaskedDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelMaskedDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelMaskedDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
};

static_assert(sizeof(OMPParallelMaskedDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
