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
class OMPParallelMasterDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPParallelMasterDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMasterDirective>;
using OMPParallelMasterDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMasterDirective>;
using OMPParallelMasterDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMasterDirective>;

class OMPParallelMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMasterDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMasterDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPParallelMasterDirective::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE;
  }

  static OMPParallelMasterDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMasterDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPParallelMasterDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMasterDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPParallelMasterDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPParallelMasterDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPParallelMasterDirective> from(const Stmt &parent);

  inline static std::optional<OMPParallelMasterDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPParallelMasterDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr task_reduction_reference_expression(void) const;
};

static_assert(sizeof(OMPParallelMasterDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
