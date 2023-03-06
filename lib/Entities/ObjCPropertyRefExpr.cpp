// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCPropertyRefExpr.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/ObjCPropertyDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/ValueStmt.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCPropertyRefExpr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCPropertyRefExpr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCPropertyRefExpr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCPropertyRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ObjCPropertyRefExpr::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCPropertyRefExpr::contains(const Decl &decl) {
  for (auto &parent : ObjCPropertyRefExpr::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCPropertyRefExpr::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyRefExpr::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ObjCPropertyRefExpr::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kObjCPropertyRefExprDerivedKinds[] = {
    ObjCPropertyRefExpr::static_kind(),
};

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case ObjCPropertyRefExpr::static_kind():
      return reinterpret_cast<const ObjCPropertyRefExpr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ObjCPropertyRefExpr> e = ObjCPropertyRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyRefExpr> e = ObjCPropertyRefExpr::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyRefExpr> ObjCPropertyRefExpr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kObjCPropertyRefExprDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyRefExpr> e = ObjCPropertyRefExpr::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Expr ObjCPropertyRefExpr::base(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ObjCInterfaceDecl ObjCPropertyRefExpr::class_receiver(void) const {
  RawEntityId eid = impl->reader.getVal39();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCPropertyDecl ObjCPropertyRefExpr::explicit_property(void) const {
  RawEntityId eid = impl->reader.getVal40();
  return ObjCPropertyDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_getter(void) const {
  RawEntityId eid = impl->reader.getVal41();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_setter(void) const {
  RawEntityId eid = impl->reader.getVal42();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCPropertyRefExpr::token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal43());
}

Token ObjCPropertyRefExpr::receiver_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal44());
}

Type ObjCPropertyRefExpr::receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ObjCPropertyRefExpr::super_receiver_type(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCPropertyRefExpr::is_class_receiver(void) const {
  return impl->reader.getVal89();
}

bool ObjCPropertyRefExpr::is_explicit_property(void) const {
  return impl->reader.getVal90();
}

bool ObjCPropertyRefExpr::is_implicit_property(void) const {
  return impl->reader.getVal91();
}

bool ObjCPropertyRefExpr::is_messaging_getter(void) const {
  return impl->reader.getVal92();
}

bool ObjCPropertyRefExpr::is_messaging_setter(void) const {
  return impl->reader.getVal93();
}

bool ObjCPropertyRefExpr::is_object_receiver(void) const {
  return impl->reader.getVal95();
}

bool ObjCPropertyRefExpr::is_super_receiver(void) const {
  return impl->reader.getVal97();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
