// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NamespaceAliasDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = NamespaceAliasDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool NamespaceAliasDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : NamespaceAliasDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NamespaceAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = NamespaceAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool NamespaceAliasDecl::contains(const Decl &decl) {
  for (auto &parent : NamespaceAliasDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool NamespaceAliasDecl::contains(const Stmt &stmt) {
  for (auto &parent : NamespaceAliasDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

NamespaceAliasDecl NamespaceAliasDecl::canonical_declaration(void) const {
  if (auto canon = NamespaceAliasDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (NamespaceAliasDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::definition(void) const {
  return NamespaceAliasDecl::from(this->Decl::definition());
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<NamespaceAliasDecl> dr = NamespaceAliasDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return NamespaceAliasDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kNamespaceAliasDeclDerivedKinds[] = {
    NamespaceAliasDecl::static_kind(),
};

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case NamespaceAliasDecl::static_kind():
      return reinterpret_cast<const NamespaceAliasDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kNamespaceAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<NamespaceAliasDecl> e = NamespaceAliasDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kNamespaceAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<NamespaceAliasDecl> e = NamespaceAliasDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NamespaceAliasDecl> NamespaceAliasDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kNamespaceAliasDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<NamespaceAliasDecl> e = NamespaceAliasDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const Reference &r) {
  return NamespaceAliasDecl::from(r.as_declaration());
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const TokenContext &t) {
  return NamespaceAliasDecl::from(t.as_declaration());
}

Token NamespaceAliasDecl::alias_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal54());
}

NamedDecl NamespaceAliasDecl::aliased_namespace(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token NamespaceAliasDecl::namespace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

Token NamespaceAliasDecl::target_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal64());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
