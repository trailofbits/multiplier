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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OMPExecutableDirective;
class OMPTargetParallelDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPTargetParallelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPTargetParallelDirective> in(const Fragment &frag);
  static gap::generator<OMPTargetParallelDirective> in(const File &file);
  static gap::generator<OMPTargetParallelDirective> in(const Index &index);
  static gap::generator<OMPTargetParallelDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPTargetParallelDirective> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE;
  }

  static gap::generator<OMPTargetParallelDirective> containing(const Decl &decl);
  static gap::generator<OMPTargetParallelDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPTargetParallelDirective> containing(const Stmt &stmt);
  static gap::generator<OMPTargetParallelDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPTargetParallelDirective> from(const Stmt &parent);

  inline static std::optional<OMPTargetParallelDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPTargetParallelDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPTargetParallelDirective> from(const Reference &r) {
    return OMPTargetParallelDirective::from(r.as_statement());
  }

  inline static std::optional<OMPTargetParallelDirective> from(const TokenContext &t) {
    return OMPTargetParallelDirective::from(t.as_statement());
  }

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPTargetParallelDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
