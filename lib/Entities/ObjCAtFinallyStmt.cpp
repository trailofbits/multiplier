// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCAtFinallyStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCAtFinallyStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCAtFinallyStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCAtFinallyStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtFinallyStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCAtFinallyStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCAtFinallyStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCAtFinallyStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCAtFinallyStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCAtFinallyStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCAtFinallyStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCAtFinallyStmtDerivedKinds[] = {
    ObjCAtFinallyStmt::static_kind(),
};

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCAtFinallyStmt::static_kind():
      return reinterpret_cast<const ObjCAtFinallyStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCAtFinallyStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCAtFinallyStmt> e = ObjCAtFinallyStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCAtFinallyStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCAtFinallyStmt> e = ObjCAtFinallyStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCAtFinallyStmt> ObjCAtFinallyStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCAtFinallyStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCAtFinallyStmt> e = ObjCAtFinallyStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const Reference &r) {
  return ObjCAtFinallyStmt::from(r.as_statement());
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const TokenContext &t) {
  return ObjCAtFinallyStmt::from(t.as_statement());
}

Token ObjCAtFinallyStmt::at_finally_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal9());
}

Stmt ObjCAtFinallyStmt::finally_body(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
