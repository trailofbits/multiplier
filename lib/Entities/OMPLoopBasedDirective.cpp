// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPLoopBasedDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPDistributeDirective.h>
#include <multiplier/Entities/OMPDistributeParallelForDirective.h>
#include <multiplier/Entities/OMPDistributeParallelForSimdDirective.h>
#include <multiplier/Entities/OMPDistributeSimdDirective.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/OMPForDirective.h>
#include <multiplier/Entities/OMPForSimdDirective.h>
#include <multiplier/Entities/OMPGenericLoopDirective.h>
#include <multiplier/Entities/OMPMaskedTaskLoopDirective.h>
#include <multiplier/Entities/OMPMaskedTaskLoopSimdDirective.h>
#include <multiplier/Entities/OMPMasterTaskLoopDirective.h>
#include <multiplier/Entities/OMPMasterTaskLoopSimdDirective.h>
#include <multiplier/Entities/OMPParallelForDirective.h>
#include <multiplier/Entities/OMPParallelForSimdDirective.h>
#include <multiplier/Entities/OMPParallelGenericLoopDirective.h>
#include <multiplier/Entities/OMPParallelMaskedTaskLoopDirective.h>
#include <multiplier/Entities/OMPParallelMaskedTaskLoopSimdDirective.h>
#include <multiplier/Entities/OMPParallelMasterTaskLoopDirective.h>
#include <multiplier/Entities/OMPParallelMasterTaskLoopSimdDirective.h>
#include <multiplier/Entities/OMPSimdDirective.h>
#include <multiplier/Entities/OMPTargetParallelForDirective.h>
#include <multiplier/Entities/OMPTargetParallelForSimdDirective.h>
#include <multiplier/Entities/OMPTargetParallelGenericLoopDirective.h>
#include <multiplier/Entities/OMPTargetSimdDirective.h>
#include <multiplier/Entities/OMPTargetTeamsDistributeDirective.h>
#include <multiplier/Entities/OMPTargetTeamsDistributeParallelForDirective.h>
#include <multiplier/Entities/OMPTargetTeamsDistributeParallelForSimdDirective.h>
#include <multiplier/Entities/OMPTargetTeamsDistributeSimdDirective.h>
#include <multiplier/Entities/OMPTargetTeamsGenericLoopDirective.h>
#include <multiplier/Entities/OMPTaskLoopDirective.h>
#include <multiplier/Entities/OMPTaskLoopSimdDirective.h>
#include <multiplier/Entities/OMPTeamsDistributeDirective.h>
#include <multiplier/Entities/OMPTeamsDistributeParallelForDirective.h>
#include <multiplier/Entities/OMPTeamsDistributeParallelForSimdDirective.h>
#include <multiplier/Entities/OMPTeamsDistributeSimdDirective.h>
#include <multiplier/Entities/OMPTeamsGenericLoopDirective.h>
#include <multiplier/Entities/OMPTileDirective.h>
#include <multiplier/Entities/OMPUnrollDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPLoopBasedDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPLoopBasedDirective::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPLoopBasedDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

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

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const Stmt &parent) {
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

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPLoopBasedDirective> e = OMPLoopBasedDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPLoopBasedDirective> e = OMPLoopBasedDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopBasedDirective> OMPLoopBasedDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPLoopBasedDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPLoopBasedDirective> e = OMPLoopBasedDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
