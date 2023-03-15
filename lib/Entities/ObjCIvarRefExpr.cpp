// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCIvarRefExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCIvarRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCIvarRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCIvarRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCIvarRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCIvarRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCIvarRefExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCIvarRefExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCIvarRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCIvarRefExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCIvarRefExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCIvarRefExprDerivedKinds[] = {
    ObjCIvarRefExpr::static_kind(),
};

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCIvarRefExpr::static_kind():
      return reinterpret_cast<const ObjCIvarRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCIvarRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCIvarRefExpr> e = ObjCIvarRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCIvarRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCIvarRefExpr> e = ObjCIvarRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIvarRefExpr> ObjCIvarRefExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCIvarRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCIvarRefExpr> e = ObjCIvarRefExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const Reference &r) {
  return ObjCIvarRefExpr::from(r.as_statement());
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const TokenContext &t) {
  return ObjCIvarRefExpr::from(t.as_statement());
}

Expr ObjCIvarRefExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ObjCIvarDecl ObjCIvarRefExpr::declaration(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return ObjCIvarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCIvarRefExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal40());
}

Token ObjCIvarRefExpr::operation_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal41());
}

bool ObjCIvarRefExpr::is_arrow(void) const {
  return impl->reader.getVal88();
}

bool ObjCIvarRefExpr::is_free_instance_variable(void) const {
  return impl->reader.getVal89();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
