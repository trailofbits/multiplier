// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCTypeParamDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/TypedefNameDecl.h>

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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCTypeParamDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCTypeParamDecl> ObjCTypeParamDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCTypeParamDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kObjCTypeParamDeclDerivedKinds[] = {
    ObjCTypeParamDecl::static_kind(),
};

}  // namespace

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from_base(const Decl &parent) {
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
      if (std::optional<ObjCTypeParamDecl> e = from_base(std::move(eptr))) {
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
      if (std::optional<ObjCTypeParamDecl> e = from_base(std::move(eptr))) {
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
        if (std::optional<ObjCTypeParamDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const Reference &r) {
  return ObjCTypeParamDecl::from(r.as_declaration());
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCTypeParamDecl::colon_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

ObjCTypeParamVariance ObjCTypeParamDecl::variance(void) const {
  return static_cast<ObjCTypeParamVariance>(impl->reader.getVal80());
}

Token ObjCTypeParamDecl::variance_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal67());
}

bool ObjCTypeParamDecl::has_explicit_bound(void) const {
  return impl->reader.getVal76();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
