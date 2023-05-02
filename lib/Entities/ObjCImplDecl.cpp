// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCImplDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCCategoryImplDecl.h>
#include <multiplier/Entities/ObjCContainerDecl.h>
#include <multiplier/Entities/ObjCImplementationDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCPropertyImplDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCImplDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCImplDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCImplDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCImplDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCImplDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCImplDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCImplDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCImplDecl ObjCImplDecl::canonical_declaration(void) const {
  if (auto canon = ObjCImplDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCImplDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCImplDecl> ObjCImplDecl::definition(void) const {
  return ObjCImplDecl::from(this->Decl::definition());
}

gap::generator<ObjCImplDecl> ObjCImplDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCImplDecl> dr = ObjCImplDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCImplDecl> ObjCImplDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCImplDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCImplDeclDerivedKinds[] = {
    ObjCImplementationDecl::static_kind(),
    ObjCCategoryImplDecl::static_kind(),
};

std::optional<ObjCImplDecl> ObjCImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCImplementationDecl::static_kind():
    case ObjCCategoryImplDecl::static_kind():
      return reinterpret_cast<const ObjCImplDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCImplDecl> e = ObjCImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCImplDecl> e = ObjCImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCImplDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCImplDecl> e = ObjCImplDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const Reference &r) {
  return ObjCImplDecl::from(r.as_declaration());
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const TokenContext &t) {
  return ObjCImplDecl::from(t.as_declaration());
}

ObjCInterfaceDecl ObjCImplDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal64();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

unsigned ObjCImplDecl::num_property_implementations(void) const {
  return impl->reader.getVal313().size();
}

std::optional<ObjCPropertyImplDecl> ObjCImplDecl::nth_property_implementation(unsigned n) const {
  auto list = impl->reader.getVal313();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyImplDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCPropertyImplDecl> ObjCImplDecl::property_implementations(void) const & {
  auto list = impl->reader.getVal313();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d313 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyImplDecl::from(Decl(std::move(d313)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
