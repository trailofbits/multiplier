// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UsingPackDecl.h>

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

gap::generator<UsingPackDecl> UsingPackDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingPackDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingPackDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingPackDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UsingPackDecl> UsingPackDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingPackDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingPackDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingPackDecl::contains(const Decl &decl) {
  for (auto &parent : UsingPackDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UsingPackDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingPackDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

UsingPackDecl UsingPackDecl::canonical_declaration(void) const {
  if (auto canon = UsingPackDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UsingPackDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UsingPackDecl> UsingPackDecl::definition(void) const {
  return UsingPackDecl::from(this->Decl::definition());
}

gap::generator<UsingPackDecl> UsingPackDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingPackDecl> dr = UsingPackDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingPackDecl> UsingPackDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UsingPackDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUsingPackDeclDerivedKinds[] = {
    UsingPackDecl::static_kind(),
};

std::optional<UsingPackDecl> UsingPackDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingPackDecl::static_kind():
      return reinterpret_cast<const UsingPackDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUsingPackDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingPackDecl> e = UsingPackDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingPackDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingPackDecl> e = UsingPackDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingPackDecl> UsingPackDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingPackDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingPackDecl> e = UsingPackDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UsingPackDecl> UsingPackDecl::from(const Reference &r) {
  return UsingPackDecl::from(r.as_declaration());
}

std::optional<UsingPackDecl> UsingPackDecl::from(const TokenContext &t) {
  return UsingPackDecl::from(t.as_declaration());
}

unsigned UsingPackDecl::num_expansions(void) const {
  return impl->reader.getVal49().size();
}

std::optional<NamedDecl> UsingPackDecl::nth_expansion(unsigned n) const {
  auto list = impl->reader.getVal49();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return NamedDecl::from(Decl(std::move(e)));
}

gap::generator<NamedDecl> UsingPackDecl::expansions(void) const & {
  auto list = impl->reader.getVal49();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d49 = ep->DeclFor(ep, v)) {
      if (auto e = NamedDecl::from(Decl(std::move(d49)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

NamedDecl UsingPackDecl::instantiated_from_using_declaration(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
