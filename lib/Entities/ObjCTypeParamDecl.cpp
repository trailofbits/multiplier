// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCTypeParamDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeDecl.h>
#include <multiplier/Entities/TypedefNameDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCTypeParamDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCTypeParamDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCTypeParamDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCTypeParamDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCTypeParamDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCTypeParamDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCTypeParamDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCTypeParamDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCTypeParamDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCTypeParamDecl ObjCTypeParamDecl::canonical_declaration(void) const {
  if (auto canon = ObjCTypeParamDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCTypeParamDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::definition(void) const {
  return ObjCTypeParamDecl::from(this->Decl::definition());
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCTypeParamDecl> dr = ObjCTypeParamDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCTypeParamDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCTypeParamDeclDerivedKinds[] = {
    ObjCTypeParamDecl::static_kind(),
};

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCTypeParamDecl::static_kind():
      return reinterpret_cast<const ObjCTypeParamDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCTypeParamDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCTypeParamDecl> e = ObjCTypeParamDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCTypeParamDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCTypeParamDecl> e = ObjCTypeParamDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCTypeParamDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCTypeParamDecl> e = ObjCTypeParamDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const Reference &r) {
  return ObjCTypeParamDecl::from(r.as_declaration());
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const TokenContext &t) {
  return ObjCTypeParamDecl::from(t.as_declaration());
}

Token ObjCTypeParamDecl::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal70());
}

ObjCTypeParamVariance ObjCTypeParamDecl::variance(void) const {
  return static_cast<ObjCTypeParamVariance>(impl->reader.getVal83());
}

Token ObjCTypeParamDecl::variance_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal71());
}

bool ObjCTypeParamDecl::has_explicit_bound(void) const {
  return impl->reader.getVal79();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
