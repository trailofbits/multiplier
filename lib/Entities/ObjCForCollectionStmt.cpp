// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCForCollectionStmt.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCForCollectionStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCForCollectionStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCForCollectionStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCForCollectionStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCForCollectionStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCForCollectionStmt::contains(const Decl &decl) {
  for (auto &parent : ObjCForCollectionStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCForCollectionStmt::contains(const Stmt &stmt) {
  for (auto &parent : ObjCForCollectionStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCForCollectionStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCForCollectionStmtDerivedKinds[] = {
    ObjCForCollectionStmt::static_kind(),
};

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCForCollectionStmt::static_kind():
      return reinterpret_cast<const ObjCForCollectionStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCForCollectionStmt> e = ObjCForCollectionStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCForCollectionStmt> e = ObjCForCollectionStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCForCollectionStmt> ObjCForCollectionStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCForCollectionStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCForCollectionStmt> e = ObjCForCollectionStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const Reference &r) {
  return ObjCForCollectionStmt::from(r.as_statement());
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const TokenContext &t) {
  return ObjCForCollectionStmt::from(t.as_statement());
}

Stmt ObjCForCollectionStmt::body(void) const {
  RawEntityId eid = impl->reader.getVal9();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Expr ObjCForCollectionStmt::collection(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Stmt ObjCForCollectionStmt::element(void) const {
  RawEntityId eid = impl->reader.getVal11();
  return Stmt(impl->ep->StmtFor(impl->ep, eid));
}

Token ObjCForCollectionStmt::for_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal13());
}

Token ObjCForCollectionStmt::r_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
