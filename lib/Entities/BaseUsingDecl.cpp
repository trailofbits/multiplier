// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BaseUsingDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UsingDecl.h>
#include <multiplier/Entities/UsingEnumDecl.h>
#include <multiplier/Entities/UsingShadowDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BaseUsingDecl> BaseUsingDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BaseUsingDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BaseUsingDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BaseUsingDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<BaseUsingDecl> BaseUsingDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BaseUsingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = BaseUsingDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool BaseUsingDecl::contains(const Decl &decl) {
  for (auto &parent : BaseUsingDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool BaseUsingDecl::contains(const Stmt &stmt) {
  for (auto &parent : BaseUsingDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

BaseUsingDecl BaseUsingDecl::canonical_declaration(void) const {
  if (auto canon = BaseUsingDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (BaseUsingDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<BaseUsingDecl> BaseUsingDecl::definition(void) const {
  return BaseUsingDecl::from(this->Decl::definition());
}

gap::generator<BaseUsingDecl> BaseUsingDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<BaseUsingDecl> dr = BaseUsingDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<BaseUsingDecl> BaseUsingDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return BaseUsingDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kBaseUsingDeclDerivedKinds[] = {
    UsingDecl::static_kind(),
    UsingEnumDecl::static_kind(),
};

std::optional<BaseUsingDecl> BaseUsingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UsingDecl::static_kind():
    case UsingEnumDecl::static_kind():
      return reinterpret_cast<const BaseUsingDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kBaseUsingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<BaseUsingDecl> e = BaseUsingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kBaseUsingDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<BaseUsingDecl> e = BaseUsingDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BaseUsingDecl> BaseUsingDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kBaseUsingDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<BaseUsingDecl> e = BaseUsingDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BaseUsingDecl> BaseUsingDecl::from(const Reference &r) {
  return BaseUsingDecl::from(r.as_declaration());
}

std::optional<BaseUsingDecl> BaseUsingDecl::from(const TokenContext &t) {
  return BaseUsingDecl::from(t.as_declaration());
}

unsigned BaseUsingDecl::num_shadows(void) const {
  return impl->reader.getVal54().size();
}

std::optional<UsingShadowDecl> BaseUsingDecl::nth_shadow(unsigned n) const {
  auto list = impl->reader.getVal54();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return UsingShadowDecl::from(Decl(std::move(e)));
}

gap::generator<UsingShadowDecl> BaseUsingDecl::shadows(void) const & {
  auto list = impl->reader.getVal54();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d54 = ep->DeclFor(ep, v)) {
      if (auto e = UsingShadowDecl::from(Decl(std::move(d54)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
