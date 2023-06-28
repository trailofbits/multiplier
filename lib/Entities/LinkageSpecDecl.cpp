// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LinkageSpecDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LinkageSpecDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LinkageSpecDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LinkageSpecDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LinkageSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LinkageSpecDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LinkageSpecDecl::contains(const Decl &decl) {
  for (auto &parent : LinkageSpecDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LinkageSpecDecl::contains(const Stmt &stmt) {
  for (auto &parent : LinkageSpecDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

LinkageSpecDecl LinkageSpecDecl::canonical_declaration(void) const {
  if (auto canon = LinkageSpecDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LinkageSpecDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::definition(void) const {
  return LinkageSpecDecl::from(this->Decl::definition());
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LinkageSpecDecl> dr = LinkageSpecDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return LinkageSpecDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kLinkageSpecDeclDerivedKinds[] = {
    LinkageSpecDecl::static_kind(),
};

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case LinkageSpecDecl::static_kind():
      return reinterpret_cast<const LinkageSpecDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<LinkageSpecDecl> e = LinkageSpecDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<LinkageSpecDecl> e = LinkageSpecDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LinkageSpecDecl> LinkageSpecDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kLinkageSpecDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<LinkageSpecDecl> e = LinkageSpecDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const Reference &r) {
  return LinkageSpecDecl::from(r.as_declaration());
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const TokenContext &t) {
  return LinkageSpecDecl::from(t.as_declaration());
}

gap::generator<Decl> LinkageSpecDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal52();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
