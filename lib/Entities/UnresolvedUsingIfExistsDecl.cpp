// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedUsingIfExistsDecl.h>

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

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedUsingIfExistsDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedUsingIfExistsDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedUsingIfExistsDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingIfExistsDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingIfExistsDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedUsingIfExistsDecl::contains(const Decl &decl) {
  for (auto &parent : UnresolvedUsingIfExistsDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UnresolvedUsingIfExistsDecl::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedUsingIfExistsDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UnresolvedUsingIfExistsDecl> dr = UnresolvedUsingIfExistsDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UnresolvedUsingIfExistsDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUnresolvedUsingIfExistsDeclDerivedKinds[] = {
    UnresolvedUsingIfExistsDecl::static_kind(),
};

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingIfExistsDecl::static_kind():
      return reinterpret_cast<const UnresolvedUsingIfExistsDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUnresolvedUsingIfExistsDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UnresolvedUsingIfExistsDecl> e = UnresolvedUsingIfExistsDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUnresolvedUsingIfExistsDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedUsingIfExistsDecl> e = UnresolvedUsingIfExistsDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUnresolvedUsingIfExistsDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedUsingIfExistsDecl> e = UnresolvedUsingIfExistsDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const Reference &r) {
  return UnresolvedUsingIfExistsDecl::from(r.as_declaration());
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const TokenContext &t) {
  return UnresolvedUsingIfExistsDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
