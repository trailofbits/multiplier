// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCIvarDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclaratorDecl.h>
#include <multiplier/Entities/FieldDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCIvarDecl> ObjCIvarDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCIvarDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCIvarDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCIvarDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCIvarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCIvarDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCIvarDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCIvarDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCIvarDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCIvarDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCIvarDecl ObjCIvarDecl::canonical_declaration(void) const {
  if (auto canon = ObjCIvarDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCIvarDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::definition(void) const {
  return ObjCIvarDecl::from(this->Decl::definition());
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCIvarDecl> dr = ObjCIvarDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCIvarDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCIvarDeclDerivedKinds[] = {
    ObjCIvarDecl::static_kind(),
};

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCIvarDecl::static_kind():
      return reinterpret_cast<const ObjCIvarDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCIvarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCIvarDecl> e = ObjCIvarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCIvarDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCIvarDecl> e = ObjCIvarDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCIvarDecl> ObjCIvarDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCIvarDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCIvarDecl> e = ObjCIvarDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const Reference &r) {
  return ObjCIvarDecl::from(r.as_declaration());
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const TokenContext &t) {
  return ObjCIvarDecl::from(t.as_declaration());
}

ObjCIvarDeclAccessControl ObjCIvarDecl::access_control(void) const {
  return static_cast<ObjCIvarDeclAccessControl>(impl->reader.getVal85());
}

ObjCIvarDeclAccessControl ObjCIvarDecl::canonical_access_control(void) const {
  return static_cast<ObjCIvarDeclAccessControl>(impl->reader.getVal87());
}

ObjCInterfaceDecl ObjCIvarDecl::containing_interface(void) const {
  RawEntityId eid = impl->reader.getVal84();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCIvarDecl ObjCIvarDecl::next_instance_variable(void) const {
  RawEntityId eid = impl->reader.getVal86();
  return ObjCIvarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool ObjCIvarDecl::synthesize(void) const {
  return impl->reader.getVal103();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
