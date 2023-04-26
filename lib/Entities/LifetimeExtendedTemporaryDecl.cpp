// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LifetimeExtendedTemporaryDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LifetimeExtendedTemporaryDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = LifetimeExtendedTemporaryDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool LifetimeExtendedTemporaryDecl::contains(const Decl &decl) {
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool LifetimeExtendedTemporaryDecl::contains(const Stmt &stmt) {
  for (auto &parent : LifetimeExtendedTemporaryDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

LifetimeExtendedTemporaryDecl LifetimeExtendedTemporaryDecl::canonical_declaration(void) const {
  if (auto canon = LifetimeExtendedTemporaryDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (LifetimeExtendedTemporaryDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::definition(void) const {
  return LifetimeExtendedTemporaryDecl::from(this->Decl::definition());
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<LifetimeExtendedTemporaryDecl> dr = LifetimeExtendedTemporaryDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return LifetimeExtendedTemporaryDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kLifetimeExtendedTemporaryDeclDerivedKinds[] = {
    LifetimeExtendedTemporaryDecl::static_kind(),
};

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case LifetimeExtendedTemporaryDecl::static_kind():
      return reinterpret_cast<const LifetimeExtendedTemporaryDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<LifetimeExtendedTemporaryDecl> e = LifetimeExtendedTemporaryDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<LifetimeExtendedTemporaryDecl> e = LifetimeExtendedTemporaryDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kLifetimeExtendedTemporaryDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<LifetimeExtendedTemporaryDecl> e = LifetimeExtendedTemporaryDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const Reference &r) {
  return LifetimeExtendedTemporaryDecl::from(r.as_declaration());
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const TokenContext &t) {
  return LifetimeExtendedTemporaryDecl::from(t.as_declaration());
}

gap::generator<Stmt> LifetimeExtendedTemporaryDecl::children(void) const & {
  auto list = impl->reader.getVal49();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d49 = ep->StmtFor(ep, v)) {
      co_yield Stmt(std::move(d49));
    }
  }
  co_return;
}

ValueDecl LifetimeExtendedTemporaryDecl::extending_declaration(void) const {
  RawEntityId eid = impl->reader.getVal47();
  return ValueDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

StorageDuration LifetimeExtendedTemporaryDecl::storage_duration(void) const {
  return static_cast<StorageDuration>(impl->reader.getVal63());
}

Expr LifetimeExtendedTemporaryDecl::temporary_expression(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
