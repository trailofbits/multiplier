// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCCompatibleAliasDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCCompatibleAliasDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCCompatibleAliasDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCCompatibleAliasDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCompatibleAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCompatibleAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCCompatibleAliasDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCCompatibleAliasDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCCompatibleAliasDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCCompatibleAliasDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCCompatibleAliasDecl ObjCCompatibleAliasDecl::canonical_declaration(void) const {
  if (auto canon = ObjCCompatibleAliasDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCCompatibleAliasDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::definition(void) const {
  return ObjCCompatibleAliasDecl::from(this->Decl::definition());
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCCompatibleAliasDecl> dr = ObjCCompatibleAliasDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCCompatibleAliasDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCCompatibleAliasDeclDerivedKinds[] = {
    ObjCCompatibleAliasDecl::static_kind(),
};

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCCompatibleAliasDecl::static_kind():
      return reinterpret_cast<const ObjCCompatibleAliasDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCCompatibleAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCCompatibleAliasDecl> e = ObjCCompatibleAliasDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCCompatibleAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCCompatibleAliasDecl> e = ObjCCompatibleAliasDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCCompatibleAliasDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCCompatibleAliasDecl> e = ObjCCompatibleAliasDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const Reference &r) {
  return ObjCCompatibleAliasDecl::from(r.as_declaration());
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const TokenContext &t) {
  return ObjCCompatibleAliasDecl::from(t.as_declaration());
}

ObjCInterfaceDecl ObjCCompatibleAliasDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
