// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPLoopDirective.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/OMPExecutableDirective.h>
#include <multiplier/AST/OMPLoopBasedDirective.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/OMPDistributeDirective.h>
#include <multiplier/AST/OMPDistributeParallelForDirective.h>
#include <multiplier/AST/OMPDistributeParallelForSimdDirective.h>
#include <multiplier/AST/OMPDistributeSimdDirective.h>
#include <multiplier/AST/OMPForDirective.h>
#include <multiplier/AST/OMPForSimdDirective.h>
#include <multiplier/AST/OMPGenericLoopDirective.h>
#include <multiplier/AST/OMPMaskedTaskLoopDirective.h>
#include <multiplier/AST/OMPMaskedTaskLoopSimdDirective.h>
#include <multiplier/AST/OMPMasterTaskLoopDirective.h>
#include <multiplier/AST/OMPMasterTaskLoopSimdDirective.h>
#include <multiplier/AST/OMPParallelForDirective.h>
#include <multiplier/AST/OMPParallelForSimdDirective.h>
#include <multiplier/AST/OMPParallelGenericLoopDirective.h>
#include <multiplier/AST/OMPParallelMaskedTaskLoopDirective.h>
#include <multiplier/AST/OMPParallelMaskedTaskLoopSimdDirective.h>
#include <multiplier/AST/OMPParallelMasterTaskLoopDirective.h>
#include <multiplier/AST/OMPParallelMasterTaskLoopSimdDirective.h>
#include <multiplier/AST/OMPSimdDirective.h>
#include <multiplier/AST/OMPTargetParallelForDirective.h>
#include <multiplier/AST/OMPTargetParallelForSimdDirective.h>
#include <multiplier/AST/OMPTargetParallelGenericLoopDirective.h>
#include <multiplier/AST/OMPTargetSimdDirective.h>
#include <multiplier/AST/OMPTargetTeamsDistributeDirective.h>
#include <multiplier/AST/OMPTargetTeamsDistributeParallelForDirective.h>
#include <multiplier/AST/OMPTargetTeamsDistributeParallelForSimdDirective.h>
#include <multiplier/AST/OMPTargetTeamsDistributeSimdDirective.h>
#include <multiplier/AST/OMPTargetTeamsGenericLoopDirective.h>
#include <multiplier/AST/OMPTaskLoopDirective.h>
#include <multiplier/AST/OMPTaskLoopSimdDirective.h>
#include <multiplier/AST/OMPTeamsDistributeDirective.h>
#include <multiplier/AST/OMPTeamsDistributeParallelForDirective.h>
#include <multiplier/AST/OMPTeamsDistributeParallelForSimdDirective.h>
#include <multiplier/AST/OMPTeamsDistributeSimdDirective.h>
#include <multiplier/AST/OMPTeamsGenericLoopDirective.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kOMPLoopDirectiveDerivedKinds[] = {
    OMPMaskedTaskLoopDirective::static_kind(),
    OMPMaskedTaskLoopSimdDirective::static_kind(),
    OMPMasterTaskLoopDirective::static_kind(),
    OMPMasterTaskLoopSimdDirective::static_kind(),
    OMPParallelForDirective::static_kind(),
    OMPParallelForSimdDirective::static_kind(),
    OMPParallelGenericLoopDirective::static_kind(),
    OMPParallelMaskedTaskLoopDirective::static_kind(),
    OMPParallelMaskedTaskLoopSimdDirective::static_kind(),
    OMPParallelMasterTaskLoopDirective::static_kind(),
    OMPParallelMasterTaskLoopSimdDirective::static_kind(),
    OMPSimdDirective::static_kind(),
    OMPTargetParallelForDirective::static_kind(),
    OMPTargetParallelForSimdDirective::static_kind(),
    OMPTargetParallelGenericLoopDirective::static_kind(),
    OMPTargetSimdDirective::static_kind(),
    OMPTargetTeamsDistributeDirective::static_kind(),
    OMPTargetTeamsDistributeParallelForDirective::static_kind(),
    OMPTargetTeamsDistributeParallelForSimdDirective::static_kind(),
    OMPTargetTeamsDistributeSimdDirective::static_kind(),
    OMPTargetTeamsGenericLoopDirective::static_kind(),
    OMPTaskLoopDirective::static_kind(),
    OMPTaskLoopSimdDirective::static_kind(),
    OMPTeamsDistributeDirective::static_kind(),
    OMPTeamsDistributeParallelForDirective::static_kind(),
    OMPTeamsDistributeParallelForSimdDirective::static_kind(),
    OMPTeamsDistributeSimdDirective::static_kind(),
    OMPTeamsGenericLoopDirective::static_kind(),
    OMPDistributeDirective::static_kind(),
    OMPDistributeParallelForDirective::static_kind(),
    OMPDistributeParallelForSimdDirective::static_kind(),
    OMPDistributeSimdDirective::static_kind(),
    OMPForDirective::static_kind(),
    OMPForSimdDirective::static_kind(),
    OMPGenericLoopDirective::static_kind(),
};
}  // namespace

gap::generator<OMPLoopDirective> OMPLoopDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPLoopDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPLoopDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPLoopDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const ir::hl::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPLoopDirective, ir::hl::Operation>> OMPLoopDirective::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::hl::Operation> res : Stmt::in(tu, kOMPLoopDirectiveDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPLoopDirective, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPLoopDirective::contains(const Decl &decl) {
  for (auto &parent : OMPLoopDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPLoopDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPLoopDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPLoopDirective> OMPLoopDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    if (auto base = index.statement(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPLoopDirective> OMPLoopDirective::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPMaskedTaskLoopDirective::static_kind():
    case OMPMaskedTaskLoopSimdDirective::static_kind():
    case OMPMasterTaskLoopDirective::static_kind():
    case OMPMasterTaskLoopSimdDirective::static_kind():
    case OMPParallelForDirective::static_kind():
    case OMPParallelForSimdDirective::static_kind():
    case OMPParallelGenericLoopDirective::static_kind():
    case OMPParallelMaskedTaskLoopDirective::static_kind():
    case OMPParallelMaskedTaskLoopSimdDirective::static_kind():
    case OMPParallelMasterTaskLoopDirective::static_kind():
    case OMPParallelMasterTaskLoopSimdDirective::static_kind():
    case OMPSimdDirective::static_kind():
    case OMPTargetParallelForDirective::static_kind():
    case OMPTargetParallelForSimdDirective::static_kind():
    case OMPTargetParallelGenericLoopDirective::static_kind():
    case OMPTargetSimdDirective::static_kind():
    case OMPTargetTeamsDistributeDirective::static_kind():
    case OMPTargetTeamsDistributeParallelForDirective::static_kind():
    case OMPTargetTeamsDistributeParallelForSimdDirective::static_kind():
    case OMPTargetTeamsDistributeSimdDirective::static_kind():
    case OMPTargetTeamsGenericLoopDirective::static_kind():
    case OMPTaskLoopDirective::static_kind():
    case OMPTaskLoopSimdDirective::static_kind():
    case OMPTeamsDistributeDirective::static_kind():
    case OMPTeamsDistributeParallelForDirective::static_kind():
    case OMPTeamsDistributeParallelForSimdDirective::static_kind():
    case OMPTeamsDistributeSimdDirective::static_kind():
    case OMPTeamsGenericLoopDirective::static_kind():
    case OMPDistributeDirective::static_kind():
    case OMPDistributeParallelForDirective::static_kind():
    case OMPDistributeParallelForSimdDirective::static_kind():
    case OMPDistributeSimdDirective::static_kind():
    case OMPForDirective::static_kind():
    case OMPForSimdDirective::static_kind():
    case OMPGenericLoopDirective::static_kind():
      return reinterpret_cast<const OMPLoopDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPLoopDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPLoopDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPLoopDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPLoopDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopDirective> OMPLoopDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPLoopDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPLoopDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const Reference &r) {
  return OMPLoopDirective::from(r.as_statement());
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned OMPLoopDirective::num_counters(void) const {
  return impl->reader.getVal15().size();
}

std::optional<Expr> OMPLoopDirective::nth_counter(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::counters(void) const & {
  auto list = impl->reader.getVal15();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d15))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_dependent_counters(void) const {
  return impl->reader.getVal26().size();
}

std::optional<Expr> OMPLoopDirective::nth_dependent_counter(unsigned n) const {
  auto list = impl->reader.getVal26();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::dependent_counters(void) const & {
  auto list = impl->reader.getVal26();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d26 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d26))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_dependent_initializers(void) const {
  return impl->reader.getVal27().size();
}

std::optional<Expr> OMPLoopDirective::nth_dependent_initializer(unsigned n) const {
  auto list = impl->reader.getVal27();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::dependent_initializers(void) const & {
  auto list = impl->reader.getVal27();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d27 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d27))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_finals(void) const {
  return impl->reader.getVal28().size();
}

std::optional<Expr> OMPLoopDirective::nth_final(unsigned n) const {
  auto list = impl->reader.getVal28();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::finals(void) const & {
  auto list = impl->reader.getVal28();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d28 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d28))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_finals_conditions(void) const {
  return impl->reader.getVal29().size();
}

std::optional<Expr> OMPLoopDirective::nth_finals_condition(unsigned n) const {
  auto list = impl->reader.getVal29();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::finals_conditions(void) const & {
  auto list = impl->reader.getVal29();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d29 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d29))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

Stmt OMPLoopDirective::body(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr OMPLoopDirective::calculate_last_iteration(void) const {
  RawEntityId eid = impl->reader.getVal17();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_condition(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_distance_condition(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_ensure_upper_bound(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_initializer(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_lower_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_next_lower_bound(void) const {
  RawEntityId eid = impl->reader.getVal30();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_next_upper_bound(void) const {
  RawEntityId eid = impl->reader.getVal31();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_parallel_for_in_distance_condition(void) const {
  RawEntityId eid = impl->reader.getVal32();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::combined_upper_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal33();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::condition(void) const {
  RawEntityId eid = impl->reader.getVal34();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::distance_increment(void) const {
  RawEntityId eid = impl->reader.getVal35();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::ensure_upper_bound(void) const {
  RawEntityId eid = impl->reader.getVal36();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::increment(void) const {
  RawEntityId eid = impl->reader.getVal37();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::initializer(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::is_last_iteration_variable(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::iteration_variable(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::last_iteration(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::lower_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::next_lower_bound(void) const {
  RawEntityId eid = impl->reader.getVal43();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::next_upper_bound(void) const {
  RawEntityId eid = impl->reader.getVal44();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::pre_condition(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Stmt OMPLoopDirective::pre_initializers(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr OMPLoopDirective::prev_ensure_upper_bound(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::prev_lower_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal48();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::prev_upper_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::stride_variable(void) const {
  RawEntityId eid = impl->reader.getVal50();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr OMPLoopDirective::upper_bound_variable(void) const {
  RawEntityId eid = impl->reader.getVal51();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

unsigned OMPLoopDirective::num_initializers(void) const {
  return impl->reader.getVal52().size();
}

std::optional<Expr> OMPLoopDirective::nth_initializer(unsigned n) const {
  auto list = impl->reader.getVal52();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::initializers(void) const & {
  auto list = impl->reader.getVal52();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d52 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d52))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_private_counters(void) const {
  return impl->reader.getVal53().size();
}

std::optional<Expr> OMPLoopDirective::nth_private_counter(unsigned n) const {
  auto list = impl->reader.getVal53();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::private_counters(void) const & {
  auto list = impl->reader.getVal53();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d53 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d53))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned OMPLoopDirective::num_updates(void) const {
  return impl->reader.getVal54().size();
}

std::optional<Expr> OMPLoopDirective::nth_update(unsigned n) const {
  auto list = impl->reader.getVal54();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Expr::from_base(std::move(e));
}

gap::generator<Expr> OMPLoopDirective::updates(void) const & {
  auto list = impl->reader.getVal54();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d54 = ep->StmtFor(ep, v)) {
      if (auto e = Expr::from_base(std::move(d54))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
