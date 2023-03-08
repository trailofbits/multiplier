// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UsingDirectiveDecl.h>

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

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingDirectiveDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingDirectiveDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingDirectiveDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingDirectiveDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingDirectiveDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingDirectiveDecl::contains(const Decl &decl) {
  for (auto &parent : UsingDirectiveDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UsingDirectiveDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingDirectiveDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingDirectiveDecl> dr = UsingDirectiveDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingDirectiveDecl> UsingDirectiveDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UsingDirectiveDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUsingDirectiveDeclDerivedKinds[] = {
    UsingDirectiveDecl::static_kind(),
};

std::optional<UsingDirectiveDecl> UsingDirectiveDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingDirectiveDecl::static_kind():
      return reinterpret_cast<const UsingDirectiveDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUsingDirectiveDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingDirectiveDecl> e = UsingDirectiveDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingDirectiveDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingDirectiveDecl> e = UsingDirectiveDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingDirectiveDecl> UsingDirectiveDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingDirectiveDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingDirectiveDecl> e = UsingDirectiveDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Token UsingDirectiveDecl::identifier_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal52());
}

Token UsingDirectiveDecl::namespace_key_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal53());
}

NamedDecl UsingDirectiveDecl::nominated_namespace_as_written(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token UsingDirectiveDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal62());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
