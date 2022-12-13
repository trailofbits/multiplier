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

#include "OMPLoopBasedDirective.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class OMPExecutableDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPLoopDirective>;
using OMPLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPLoopDirective>;
using OMPLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPLoopDirective>;

class OMPLoopDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPLoopDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static OMPLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopDirective> from(const TokenContext &c);
  static std::optional<OMPLoopDirective> from(const OMPLoopBasedDirective &parent);

  inline static std::optional<OMPLoopDirective> from(const std::optional<OMPLoopBasedDirective> &parent) {
    if (parent) {
      return OMPLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPLoopDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPLoopDirective> from(const Stmt &parent);

  inline static std::optional<OMPLoopDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPLoopDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> counters(void) const;
  std::vector<Expr> dependent_counters(void) const;
  std::vector<Expr> dependent_initializers(void) const;
  std::vector<Expr> finals(void) const;
  std::vector<Expr> finals_conditions(void) const;
  Stmt body(void) const;
  Expr calculate_last_iteration(void) const;
  Expr combined_condition(void) const;
  Expr combined_distance_condition(void) const;
  Expr combined_ensure_upper_bound(void) const;
  Expr combined_initializer(void) const;
  Expr combined_lower_bound_variable(void) const;
  Expr combined_next_lower_bound(void) const;
  Expr combined_next_upper_bound(void) const;
  Expr combined_parallel_for_in_distance_condition(void) const;
  Expr combined_upper_bound_variable(void) const;
  Expr condition(void) const;
  Expr distance_increment(void) const;
  Expr ensure_upper_bound(void) const;
  Expr increment(void) const;
  Expr initializer(void) const;
  Expr is_last_iteration_variable(void) const;
  Expr iteration_variable(void) const;
  Expr last_iteration(void) const;
  Expr lower_bound_variable(void) const;
  Expr next_lower_bound(void) const;
  Expr next_upper_bound(void) const;
  Expr num_iterations(void) const;
  Expr pre_condition(void) const;
  Stmt pre_initializers(void) const;
  Expr prev_ensure_upper_bound(void) const;
  Expr prev_lower_bound_variable(void) const;
  Expr prev_upper_bound_variable(void) const;
  Expr stride_variable(void) const;
  Expr upper_bound_variable(void) const;
  std::vector<Expr> initializers(void) const;
  std::vector<Expr> private_counters(void) const;
  std::vector<Expr> updates(void) const;
};

static_assert(sizeof(OMPLoopDirective) == sizeof(OMPLoopBasedDirective));

#endif
} // namespace mx
