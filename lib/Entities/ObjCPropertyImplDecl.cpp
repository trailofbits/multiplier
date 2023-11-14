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

#include "../EntityProvider.h"
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCPropertyImplDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyImplDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCPropertyImplDecl ObjCPropertyImplDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCPropertyImplDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCPropertyImplDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kObjCPropertyImplDeclDerivedKinds[] = {
    ObjCPropertyImplDecl::static_kind(),
};

}  // namespace

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCPropertyImplDecl::static_kind():
      return reinterpret_cast<const ObjCPropertyImplDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCPropertyImplDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyImplDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyImplDecl> ObjCPropertyImplDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCPropertyImplDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyImplDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const Reference &r) {
  return ObjCPropertyImplDecl::from(r.as_declaration());
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Expr ObjCPropertyImplDecl::getter_cxx_constructor(void) const {
  RawEntityId eid = impl->reader.getVal49();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::getter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCPropertyDecl ObjCPropertyImplDecl::property_declaration(void) const {
  RawEntityId eid = impl->reader.getVal57();
  return ObjCPropertyDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCPropertyImplDeclKind ObjCPropertyImplDecl::property_implementation(void) const {
  return static_cast<ObjCPropertyImplDeclKind>(impl->reader.getVal65());
}

ObjCIvarDecl ObjCPropertyImplDecl::property_instance_variable_declaration(void) const {
  RawEntityId eid = impl->reader.getVal58();
  return ObjCIvarDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCPropertyImplDecl::property_instance_variable_declaration_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

Expr ObjCPropertyImplDecl::setter_cxx_assignment(void) const {
  RawEntityId eid = impl->reader.getVal67();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::setter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal68();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool ObjCPropertyImplDecl::is_instance_variable_name_specified(void) const {
  return impl->reader.getVal50();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
