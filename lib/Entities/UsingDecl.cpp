// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UsingDecl.h>

#include <multiplier/Entities/BaseUsingDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UsingDecl> UsingDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UsingDecl> UsingDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingDecl> UsingDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingDecl> UsingDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingDecl> UsingDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingDecl::contains(const Decl &decl) {
  for (auto &parent : UsingDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UsingDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UsingDecl UsingDecl::canonical_declaration(void) const {
  if (auto canon = UsingDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UsingDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UsingDecl> UsingDecl::definition(void) const {
  return UsingDecl::from(this->Decl::definition());
}

gap::generator<UsingDecl> UsingDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingDecl> dr = UsingDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingDecl> UsingDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UsingDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUsingDeclDerivedKinds[] = {
    UsingDecl::static_kind(),
};

std::optional<UsingDecl> UsingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingDecl::static_kind():
      return reinterpret_cast<const UsingDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingDecl> UsingDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUsingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingDecl> e = UsingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingDecl> UsingDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingDecl> e = UsingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingDecl> UsingDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingDecl> e = UsingDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UsingDecl> UsingDecl::from(const Reference &r) {
  return UsingDecl::from(r.as_declaration());
}

std::optional<UsingDecl> UsingDecl::from(const TokenContext &t) {
  return UsingDecl::from(t.as_declaration());
}

Token UsingDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal54());
}

bool UsingDecl::has_typename(void) const {
  return impl->reader.getVal72();
}

bool UsingDecl::is_access_declaration(void) const {
  return impl->reader.getVal73();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
