// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTeamsDistributeSimdDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/OMPLoopBasedDirective.h>
#include <multiplier/Entities/OMPLoopDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTeamsDistributeSimdDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTeamsDistributeSimdDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTeamsDistributeSimdDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTeamsDistributeSimdDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTeamsDistributeSimdDirective::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPTeamsDistributeSimdDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTeamsDistributeSimdDirective::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTeamsDistributeSimdDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTeamsDistributeSimdDirectiveDerivedKinds[] = {
    OMPTeamsDistributeSimdDirective::static_kind(),
};

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTeamsDistributeSimdDirective::static_kind():
      return reinterpret_cast<const OMPTeamsDistributeSimdDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTeamsDistributeSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTeamsDistributeSimdDirective> e = OMPTeamsDistributeSimdDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTeamsDistributeSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTeamsDistributeSimdDirective> e = OMPTeamsDistributeSimdDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTeamsDistributeSimdDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTeamsDistributeSimdDirective> e = OMPTeamsDistributeSimdDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
