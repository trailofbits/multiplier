// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPCanonicalLoop.h>

#include <multiplier/Entities/CapturedStmt.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclRefExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPCanonicalLoop::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPCanonicalLoop::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPCanonicalLoop::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPCanonicalLoop::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = OMPCanonicalLoop::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool OMPCanonicalLoop::contains(const Decl &decl) {
  for (auto &parent : OMPCanonicalLoop::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool OMPCanonicalLoop::contains(const Stmt &stmt) {
  for (auto &parent : OMPCanonicalLoop::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<OMPCanonicalLoop> OMPCanonicalLoop::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return OMPCanonicalLoop::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kOMPCanonicalLoopDerivedKinds[] = {
    OMPCanonicalLoop::static_kind(),
};

std::optional<OMPCanonicalLoop> OMPCanonicalLoop::from(const Stmt &parent) {
  switch (parent.kind()) {
    case OMPCanonicalLoop::static_kind():
      return reinterpret_cast<const OMPCanonicalLoop &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kOMPCanonicalLoopDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<OMPCanonicalLoop> e = OMPCanonicalLoop::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kOMPCanonicalLoopDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<OMPCanonicalLoop> e = OMPCanonicalLoop::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPCanonicalLoop> OMPCanonicalLoop::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kOMPCanonicalLoopDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<OMPCanonicalLoop> e = OMPCanonicalLoop::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

CapturedStmt OMPCanonicalLoop::distance_func(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return CapturedStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Stmt OMPCanonicalLoop::loop_statement(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

CapturedStmt OMPCanonicalLoop::loop_variable_func(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return CapturedStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

DeclRefExpr OMPCanonicalLoop::loop_variable_reference(void) const {
  RawEntityId eid = impl->reader.getVal13();
  return DeclRefExpr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx