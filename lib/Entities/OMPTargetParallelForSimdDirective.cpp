// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTargetParallelForSimdDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/OMPLoopBasedDirective.h>
#include <multiplier/Entities/OMPLoopDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTargetParallelForSimdDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTargetParallelForSimdDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTargetParallelForSimdDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTargetParallelForSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTargetParallelForSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTargetParallelForSimdDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTargetParallelForSimdDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTargetParallelForSimdDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTargetParallelForSimdDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTargetParallelForSimdDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTargetParallelForSimdDirectiveDerivedKinds[] = {
    OMPTargetParallelForSimdDirective::static_kind(),
};

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTargetParallelForSimdDirective::static_kind():
      return reinterpret_cast<const OMPTargetParallelForSimdDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTargetParallelForSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTargetParallelForSimdDirective> e = OMPTargetParallelForSimdDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTargetParallelForSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTargetParallelForSimdDirective> e = OMPTargetParallelForSimdDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTargetParallelForSimdDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTargetParallelForSimdDirective> e = OMPTargetParallelForSimdDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const Reference &r) {
  return OMPTargetParallelForSimdDirective::from(r.as_statement());
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const TokenContext &t) {
  return OMPTargetParallelForSimdDirective::from(t.as_statement());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
