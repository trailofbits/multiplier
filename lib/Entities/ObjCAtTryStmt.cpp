// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCAtTryStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/ObjCAtCatchStmt.h>
#include <multiplier/Entities/ObjCAtFinallyStmt.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAtTryStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAtTryStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAtTryStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtTryStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAtTryStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCAtTryStmt::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCAtTryStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAtTryStmt::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCAtTryStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCAtTryStmtDerivedKinds[] = {
    ObjCAtTryStmt::static_kind(),
};

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCAtTryStmt::static_kind():
      return reinterpret_cast<const ObjCAtTryStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCAtTryStmt> e = ObjCAtTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAtTryStmt> e = ObjCAtTryStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtTryStmt> ObjCAtTryStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCAtTryStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAtTryStmt> e = ObjCAtTryStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token ObjCAtTryStmt::at_try_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

ObjCAtFinallyStmt ObjCAtTryStmt::finally_statement(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return ObjCAtFinallyStmt::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Stmt ObjCAtTryStmt::try_body(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

unsigned ObjCAtTryStmt::num_catch_statements(void) const {
  return impl->reader.getVal15().size();
}

std::optional<ObjCAtCatchStmt> ObjCAtTryStmt::nth_catch_statement(unsigned n) const {
  auto list = impl->reader.getVal15();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->StmtFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCAtCatchStmt::from(Stmt(std::move(e)));
}

gap::generator<ObjCAtCatchStmt> ObjCAtTryStmt::catch_statements(void) const & {
  auto list = impl->reader.getVal15();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d15 = ep->StmtFor(ep, v)) {
      if (auto e = ObjCAtCatchStmt::from(Stmt(std::move(d15)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
