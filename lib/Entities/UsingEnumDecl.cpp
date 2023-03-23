// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UsingEnumDecl.h>

#include <multiplier/Entities/BaseUsingDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/EnumDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingEnumDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingEnumDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingEnumDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingEnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingEnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingEnumDecl::contains(const Decl &decl) {
  for (auto &parent : UsingEnumDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UsingEnumDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingEnumDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<UsingEnumDecl> UsingEnumDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingEnumDecl> dr = UsingEnumDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingEnumDecl> UsingEnumDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UsingEnumDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUsingEnumDeclDerivedKinds[] = {
    UsingEnumDecl::static_kind(),
};

std::optional<UsingEnumDecl> UsingEnumDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingEnumDecl::static_kind():
      return reinterpret_cast<const UsingEnumDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUsingEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingEnumDecl> e = UsingEnumDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingEnumDecl> e = UsingEnumDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingEnumDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingEnumDecl> e = UsingEnumDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const Reference &r) {
  return UsingEnumDecl::from(r.as_declaration());
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const TokenContext &t) {
  return UsingEnumDecl::from(t.as_declaration());
}

EnumDecl UsingEnumDecl::enum_declaration(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return EnumDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token UsingEnumDecl::enum_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

Type UsingEnumDecl::enum_type(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token UsingEnumDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal64());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
