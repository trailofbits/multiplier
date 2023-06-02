// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCCategoryImplDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCCategoryDecl.h>
#include <multiplier/Entities/ObjCContainerDecl.h>
#include <multiplier/Entities/ObjCImplDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCCategoryImplDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCCategoryImplDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCCategoryImplDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCategoryImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCCategoryImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCCategoryImplDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCCategoryImplDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCCategoryImplDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCCategoryImplDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCCategoryImplDecl ObjCCategoryImplDecl::canonical_declaration(void) const {
  if (auto canon = ObjCCategoryImplDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCCategoryImplDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::definition(void) const {
  return ObjCCategoryImplDecl::from(this->Decl::definition());
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCCategoryImplDecl> dr = ObjCCategoryImplDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCCategoryImplDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCCategoryImplDeclDerivedKinds[] = {
    ObjCCategoryImplDecl::static_kind(),
};

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCCategoryImplDecl::static_kind():
      return reinterpret_cast<const ObjCCategoryImplDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCCategoryImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCCategoryImplDecl> e = ObjCCategoryImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCCategoryImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCCategoryImplDecl> e = ObjCCategoryImplDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCCategoryImplDecl> ObjCCategoryImplDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCCategoryImplDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCCategoryImplDecl> e = ObjCCategoryImplDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const Reference &r) {
  return ObjCCategoryImplDecl::from(r.as_declaration());
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const TokenContext &t) {
  return ObjCCategoryImplDecl::from(t.as_declaration());
}

ObjCCategoryDecl ObjCCategoryImplDecl::category_declaration(void) const {
  RawEntityId eid = impl->reader.getVal65();
  return ObjCCategoryDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token ObjCCategoryImplDecl::category_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
