// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UsingShadowDecl.h>

#include <multiplier/Entities/BaseUsingDecl.h>
#include <multiplier/Entities/ConstructorUsingShadowDecl.h>
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

gap::generator<UsingShadowDecl> UsingShadowDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingShadowDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingShadowDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingShadowDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UsingShadowDecl> UsingShadowDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingShadowDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingShadowDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingShadowDecl::contains(const Decl &decl) {
  for (auto &parent : UsingShadowDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UsingShadowDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingShadowDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<UsingShadowDecl> UsingShadowDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingShadowDecl> dr = UsingShadowDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingShadowDecl> UsingShadowDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UsingShadowDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUsingShadowDeclDerivedKinds[] = {
    UsingShadowDecl::static_kind(),
    ConstructorUsingShadowDecl::static_kind(),
};

std::optional<UsingShadowDecl> UsingShadowDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingShadowDecl::static_kind():
    case ConstructorUsingShadowDecl::static_kind():
      return reinterpret_cast<const UsingShadowDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingShadowDecl> e = UsingShadowDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingShadowDecl> e = UsingShadowDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingShadowDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingShadowDecl> e = UsingShadowDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

BaseUsingDecl UsingShadowDecl::introducer(void) const {
  RawEntityId eid = impl->reader.getVal52();
  return BaseUsingDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<UsingShadowDecl> UsingShadowDecl::next_using_shadow_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal53();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return UsingShadowDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

NamedDecl UsingShadowDecl::target_declaration(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
