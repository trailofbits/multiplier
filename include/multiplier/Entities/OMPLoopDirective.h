// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPLoopBasedDirective.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class OMPDistributeDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeSimdDirective;
class OMPExecutableDirective;
class OMPForDirective;
class OMPForSimdDirective;
class OMPGenericLoopDirective;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedTaskLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelGenericLoopDirective;
class OMPParallelMaskedTaskLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPSimdDirective;
class OMPTargetParallelForDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetParallelGenericLoopDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetTeamsGenericLoopDirective;
class OMPTaskLoopDirective;
class OMPTaskLoopSimdDirective;
class OMPTeamsDistributeDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeSimdDirective;
class OMPTeamsGenericLoopDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPLoopDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPLoopDirective> in(const Index &index);
  static gap::generator<OMPLoopDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPLoopDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPLoopDirective> in(const Fragment &frag);
  static gap::generator<OMPLoopDirective> in(const File &file);

  static gap::generator<OMPLoopDirective> containing(const Decl &decl);
  static gap::generator<OMPLoopDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPLoopDirective> containing(const Stmt &stmt);
  static gap::generator<OMPLoopDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPLoopDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPLoopDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPLoopDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPLoopDirective> from(const Reference &r);
  static std::optional<OMPLoopDirective> from(const VariantEntity &e);
  static std::optional<OMPLoopDirective> from(const TokenContext &t);

  std::optional<Expr> nth_counter(unsigned n) const;
  unsigned num_counters(void) const;
  gap::generator<Expr> counters(void) const &;
  std::optional<Expr> nth_dependent_counter(unsigned n) const;
  unsigned num_dependent_counters(void) const;
  gap::generator<Expr> dependent_counters(void) const &;
  std::optional<Expr> nth_dependent_initializer(unsigned n) const;
  unsigned num_dependent_initializers(void) const;
  gap::generator<Expr> dependent_initializers(void) const &;
  std::optional<Expr> nth_final(unsigned n) const;
  unsigned num_finals(void) const;
  gap::generator<Expr> finals(void) const &;
  std::optional<Expr> nth_finals_condition(unsigned n) const;
  unsigned num_finals_conditions(void) const;
  gap::generator<Expr> finals_conditions(void) const &;
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
  Expr pre_condition(void) const;
  Stmt pre_initializers(void) const;
  Expr prev_ensure_upper_bound(void) const;
  Expr prev_lower_bound_variable(void) const;
  Expr prev_upper_bound_variable(void) const;
  Expr stride_variable(void) const;
  Expr upper_bound_variable(void) const;
  std::optional<Expr> nth_initializer(unsigned n) const;
  unsigned num_initializers(void) const;
  gap::generator<Expr> initializers(void) const &;
  std::optional<Expr> nth_private_counter(unsigned n) const;
  unsigned num_private_counters(void) const;
  gap::generator<Expr> private_counters(void) const &;
  std::optional<Expr> nth_update(unsigned n) const;
  unsigned num_updates(void) const;
  gap::generator<Expr> updates(void) const &;
};

static_assert(sizeof(OMPLoopDirective) == sizeof(OMPLoopBasedDirective));

#endif
} // namespace mx
