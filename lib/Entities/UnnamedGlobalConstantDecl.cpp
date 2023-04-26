// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnnamedGlobalConstantDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/ValueDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnnamedGlobalConstantDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnnamedGlobalConstantDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnnamedGlobalConstantDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnnamedGlobalConstantDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnnamedGlobalConstantDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnnamedGlobalConstantDecl::contains(const Decl &decl) {
  for (auto &parent : UnnamedGlobalConstantDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UnnamedGlobalConstantDecl::contains(const Stmt &stmt) {
  for (auto &parent : UnnamedGlobalConstantDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UnnamedGlobalConstantDecl UnnamedGlobalConstantDecl::canonical_declaration(void) const {
  if (auto canon = UnnamedGlobalConstantDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UnnamedGlobalConstantDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::definition(void) const {
  return UnnamedGlobalConstantDecl::from(this->Decl::definition());
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UnnamedGlobalConstantDecl> dr = UnnamedGlobalConstantDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UnnamedGlobalConstantDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUnnamedGlobalConstantDeclDerivedKinds[] = {
    UnnamedGlobalConstantDecl::static_kind(),
};

std::optional<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UnnamedGlobalConstantDecl::static_kind():
      return reinterpret_cast<const UnnamedGlobalConstantDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUnnamedGlobalConstantDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UnnamedGlobalConstantDecl> e = UnnamedGlobalConstantDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUnnamedGlobalConstantDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UnnamedGlobalConstantDecl> e = UnnamedGlobalConstantDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUnnamedGlobalConstantDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UnnamedGlobalConstantDecl> e = UnnamedGlobalConstantDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::from(const Reference &r) {
  return UnnamedGlobalConstantDecl::from(r.as_declaration());
}

std::optional<UnnamedGlobalConstantDecl> UnnamedGlobalConstantDecl::from(const TokenContext &t) {
  return UnnamedGlobalConstantDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
