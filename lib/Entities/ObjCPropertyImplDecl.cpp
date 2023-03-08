// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCPropertyImplDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/ObjCPropertyDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCPropertyImplDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCPropertyImplDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCPropertyImplDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCPropertyImplDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCPropertyImplDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCPropertyImplDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyImplDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCPropertyImplDecl> dr = ObjCPropertyImplDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCPropertyImplDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCPropertyImplDeclDerivedKinds[] = {
    ObjCPropertyImplDecl::static_kind(),
};

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCPropertyImplDecl::static_kind():
      return reinterpret_cast<const ObjCPropertyImplDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCPropertyImplDecl> e = ObjCPropertyImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyImplDecl> e = ObjCPropertyImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyImplDecl> e = ObjCPropertyImplDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Expr ObjCPropertyImplDecl::getter_cxx_constructor(void) const {
  RawEntityId eid = impl->reader.getVal45();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::getter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal52();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCPropertyDecl ObjCPropertyImplDecl::property_declaration(void) const {
  RawEntityId eid = impl->reader.getVal53();
  return ObjCPropertyDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCPropertyImplDeclKind ObjCPropertyImplDecl::property_implementation(void) const {
  return static_cast<ObjCPropertyImplDeclKind>(impl->reader.getVal61());
}

ObjCIvarDecl ObjCPropertyImplDecl::property_instance_variable_declaration(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return ObjCIvarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCPropertyImplDecl::property_instance_variable_declaration_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal62());
}

Expr ObjCPropertyImplDecl::setter_cxx_assignment(void) const {
  RawEntityId eid = impl->reader.getVal63();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::setter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal64();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool ObjCPropertyImplDecl::is_instance_variable_name_specified(void) const {
  return impl->reader.getVal46();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
