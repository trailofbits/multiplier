// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPTargetExitDataDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPTargetExitDataDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPTargetExitDataDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPTargetExitDataDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTargetExitDataDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPTargetExitDataDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPTargetExitDataDirective::contains(const Decl &decl) {
  for (auto &parent : OMPTargetExitDataDirective::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool OMPTargetExitDataDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPTargetExitDataDirective::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPTargetExitDataDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPTargetExitDataDirectiveDerivedKinds[] = {
    OMPTargetExitDataDirective::static_kind(),
};

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTargetExitDataDirective::static_kind():
      return reinterpret_cast<const OMPTargetExitDataDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPTargetExitDataDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPTargetExitDataDirective> e = OMPTargetExitDataDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPTargetExitDataDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPTargetExitDataDirective> e = OMPTargetExitDataDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPTargetExitDataDirective> OMPTargetExitDataDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPTargetExitDataDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPTargetExitDataDirective> e = OMPTargetExitDataDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const Reference &r) {
  return OMPTargetExitDataDirective::from(r.as_statement());
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const TokenContext &t) {
  return OMPTargetExitDataDirective::from(t.as_statement());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
