// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedUsingValueDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedUsingValueDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedUsingValueDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedUsingValueDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingValueDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedUsingValueDecl::contains(const Decl &decl) {
  for (auto &parent : UnresolvedUsingValueDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UnresolvedUsingValueDecl::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedUsingValueDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UnresolvedUsingValueDecl UnresolvedUsingValueDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UnresolvedUsingValueDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UnresolvedUsingValueDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kUnresolvedUsingValueDeclDerivedKinds[] = {
    UnresolvedUsingValueDecl::static_kind(),
};

}  // namespace

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingValueDecl::static_kind():
      return reinterpret_cast<const UnresolvedUsingValueDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kUnresolvedUsingValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UnresolvedUsingValueDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUnresolvedUsingValueDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedUsingValueDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUnresolvedUsingValueDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedUsingValueDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const Reference &r) {
  return UnresolvedUsingValueDecl::from(r.as_declaration());
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token UnresolvedUsingValueDecl::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal58());
}

Token UnresolvedUsingValueDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

bool UnresolvedUsingValueDecl::is_access_declaration(void) const {
  return impl->reader.getVal76();
}

bool UnresolvedUsingValueDecl::is_pack_expansion(void) const {
  return impl->reader.getVal77();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
