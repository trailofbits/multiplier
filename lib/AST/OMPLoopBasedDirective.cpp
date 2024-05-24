// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPLoopBasedDirective.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/OMPExecutableDirective.h>
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
#include <multiplier/AST/OMPTileDirective.h>
#include <multiplier/AST/OMPUnrollDirective.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kOMPLoopBasedDirectiveDerivedKinds[] = {
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
    OMPTileDirective::static_kind(),
    OMPUnrollDirective::static_kind(),
};
}  // namespace

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPLoopBasedDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPLoopBasedDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPLoopBasedDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPLoopBasedDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPLoopBasedDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPLoopBasedDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPLoopBasedDirective, ir::Operation>> OMPLoopBasedDirective::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kOMPLoopBasedDirectiveDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPLoopBasedDirective, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopBasedDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopBasedDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPLoopBasedDirective::contains(const Decl &decl) {
  for (auto &parent : OMPLoopBasedDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPLoopBasedDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPLoopBasedDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from_base(const Stmt &parent) {
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
    case OMPTileDirective::static_kind():
    case OMPUnrollDirective::static_kind():
      return reinterpret_cast<const OMPLoopBasedDirective &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const Reference &r) {
  return OMPLoopBasedDirective::from(r.as_statement());
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
