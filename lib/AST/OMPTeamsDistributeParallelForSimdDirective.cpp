// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPTeamsDistributeParallelForSimdDirective.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/OMPExecutableDirective.h>
#include <multiplier/AST/OMPLoopBasedDirective.h>
#include <multiplier/AST/OMPLoopDirective.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const StmtKind kOMPTeamsDistributeParallelForSimdDirectiveDerivedKinds[] = {
    OMPTeamsDistributeParallelForSimdDirective::static_kind(),
};
}  // namespace

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTeamsDistributeParallelForSimdDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTeamsDistributeParallelForSimdDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTeamsDistributeParallelForSimdDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

#ifndef MX_DISABLE_VAST
std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const ir::Operation &op) {
  if (auto val = Stmt::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<OMPTeamsDistributeParallelForSimdDirective, ir::Operation>> OMPTeamsDistributeParallelForSimdDirective::in(const Compilation &tu) {
  for (std::pair<Stmt, ir::Operation> res : Stmt::in(tu, kOMPTeamsDistributeParallelForSimdDirectiveDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<OMPTeamsDistributeParallelForSimdDirective, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeParallelForSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTeamsDistributeParallelForSimdDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTeamsDistributeParallelForSimdDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTeamsDistributeParallelForSimdDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTeamsDistributeParallelForSimdDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTeamsDistributeParallelForSimdDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const std::optional<Stmt> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from_base(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTeamsDistributeParallelForSimdDirective::static_kind():
      return reinterpret_cast<const OMPTeamsDistributeParallelForSimdDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTeamsDistributeParallelForSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTeamsDistributeParallelForSimdDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTeamsDistributeParallelForSimdDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTeamsDistributeParallelForSimdDirective> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTeamsDistributeParallelForSimdDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTeamsDistributeParallelForSimdDirective> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const Reference &r) {
  return OMPTeamsDistributeParallelForSimdDirective::from(r.as_statement());
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const VariantEntity &e) {
  if (!std::holds_alternative<Stmt>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Stmt>(e));
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const TokenContext &t) {
  if (auto base = t.as_statement()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
