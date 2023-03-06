// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPLoopTransformationDirective.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/OMPExecutableDirective.h>
#include <multiplier/Entities/OMPLoopBasedDirective.h>
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

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPLoopTransformationDirective::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPLoopTransformationDirective::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPLoopTransformationDirective::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopTransformationDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPLoopTransformationDirective::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPLoopTransformationDirective::contains(const Decl &decl) {
  for (auto &parent : OMPLoopTransformationDirective::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPLoopTransformationDirective::contains(const Stmt &stmt) {
  for (auto &parent : OMPLoopTransformationDirective::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPLoopTransformationDirective> OMPLoopTransformationDirective::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPLoopTransformationDirective::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPLoopTransformationDirectiveDerivedKinds[] = {
    OMPTileDirective::static_kind(),
    OMPUnrollDirective::static_kind(),
};

std::optional<OMPLoopTransformationDirective> OMPLoopTransformationDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPTileDirective::static_kind():
    case OMPUnrollDirective::static_kind():
      return reinterpret_cast<const OMPLoopTransformationDirective &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPLoopTransformationDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPLoopTransformationDirective> e = OMPLoopTransformationDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPLoopTransformationDirectiveDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPLoopTransformationDirective> e = OMPLoopTransformationDirective::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPLoopTransformationDirective> OMPLoopTransformationDirective::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPLoopTransformationDirectiveDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPLoopTransformationDirective> e = OMPLoopTransformationDirective::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Stmt OMPLoopTransformationDirective::pre_initializers(void) const {
  RawEntityId eid = impl->reader.getVal14();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Stmt OMPLoopTransformationDirective::transformed_statement(void) const {
  RawEntityId eid = impl->reader.getVal17();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
