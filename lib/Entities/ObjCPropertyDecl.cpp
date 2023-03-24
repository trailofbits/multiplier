// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCPropertyDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCPropertyDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCPropertyDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCPropertyDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCPropertyDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCPropertyDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCPropertyDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCPropertyDecl> dr = ObjCPropertyDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCPropertyDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCPropertyDeclDerivedKinds[] = {
    ObjCPropertyDecl::static_kind(),
};

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCPropertyDecl::static_kind():
      return reinterpret_cast<const ObjCPropertyDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCPropertyDecl> e = ObjCPropertyDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyDecl> e = ObjCPropertyDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyDecl> e = ObjCPropertyDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const Reference &r) {
  return ObjCPropertyDecl::from(r.as_declaration());
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const TokenContext &t) {
  return ObjCPropertyDecl::from(t.as_declaration());
}

Token ObjCPropertyDecl::at_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal54());
}

ObjCMethodDecl ObjCPropertyDecl::getter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCPropertyDecl::getter_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

Token ObjCPropertyDecl::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal64());
}

ObjCPropertyDeclPropertyControl ObjCPropertyDecl::property_implementation(void) const {
  return static_cast<ObjCPropertyDeclPropertyControl>(impl->reader.getVal77());
}

ObjCIvarDecl ObjCPropertyDecl::property_instance_variable_declaration(void) const {
  RawEntityId eid = impl->reader.getVal65();
  return ObjCIvarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCPropertyQueryKind ObjCPropertyDecl::query_kind(void) const {
  return static_cast<ObjCPropertyQueryKind>(impl->reader.getVal82());
}

ObjCPropertyDeclSetterKind ObjCPropertyDecl::setter_kind(void) const {
  return static_cast<ObjCPropertyDeclSetterKind>(impl->reader.getVal84());
}

ObjCMethodDecl ObjCPropertyDecl::setter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal66();
  return ObjCMethodDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCPropertyDecl::setter_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal76());
}

Type ObjCPropertyDecl::type(void) const {
  RawEntityId eid = impl->reader.getVal78();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCPropertyDecl::is_atomic(void) const {
  return impl->reader.getVal72();
}

bool ObjCPropertyDecl::is_class_property(void) const {
  return impl->reader.getVal73();
}

bool ObjCPropertyDecl::is_direct_property(void) const {
  return impl->reader.getVal74();
}

bool ObjCPropertyDecl::is_instance_property(void) const {
  return impl->reader.getVal75();
}

bool ObjCPropertyDecl::is_optional(void) const {
  return impl->reader.getVal91();
}

bool ObjCPropertyDecl::is_read_only(void) const {
  return impl->reader.getVal92();
}

bool ObjCPropertyDecl::is_retaining(void) const {
  return impl->reader.getVal93();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
