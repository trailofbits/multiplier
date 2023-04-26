// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTeamsDistributeParallelForDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
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

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTeamsDistributeParallelForDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTeamsDistributeParallelForDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTeamsDistributeParallelForDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeParallelForDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeParallelForDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTeamsDistributeParallelForDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTeamsDistributeParallelForDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTeamsDistributeParallelForDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTeamsDistributeParallelForDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTeamsDistributeParallelForDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTeamsDistributeParallelForDirectiveDerivedKinds[] = {
    OMPTeamsDistributeParallelForDirective::static_kind(),
};

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTeamsDistributeParallelForDirective::static_kind():
      return reinterpret_cast<const OMPTeamsDistributeParallelForDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTeamsDistributeParallelForDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTeamsDistributeParallelForDirective> e = OMPTeamsDistributeParallelForDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTeamsDistributeParallelForDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTeamsDistributeParallelForDirective> e = OMPTeamsDistributeParallelForDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTeamsDistributeParallelForDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTeamsDistributeParallelForDirective> e = OMPTeamsDistributeParallelForDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const Reference &r) {
  return OMPTeamsDistributeParallelForDirective::from(r.as_statement());
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const TokenContext &t) {
  return OMPTeamsDistributeParallelForDirective::from(t.as_statement());
}

Expr OMPTeamsDistributeParallelForDirective::task_reduction_reference_expression(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool OMPTeamsDistributeParallelForDirective::has_cancel(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
