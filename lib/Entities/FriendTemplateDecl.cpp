// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FriendTemplateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FriendTemplateDecl> FriendTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FriendTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FriendTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FriendTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FriendTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FriendTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FriendTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : FriendTemplateDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool FriendTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : FriendTemplateDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FriendTemplateDecl FriendTemplateDecl::canonical_declaration(void) const {
  if (auto canon = FriendTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FriendTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::definition(void) const {
  return FriendTemplateDecl::from(this->Decl::definition());
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FriendTemplateDecl> dr = FriendTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return FriendTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kFriendTemplateDeclDerivedKinds[] = {
    FriendTemplateDecl::static_kind(),
};

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case FriendTemplateDecl::static_kind():
      return reinterpret_cast<const FriendTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFriendTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FriendTemplateDecl> e = FriendTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFriendTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FriendTemplateDecl> e = FriendTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFriendTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FriendTemplateDecl> e = FriendTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const Reference &r) {
  return FriendTemplateDecl::from(r.as_declaration());
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const TokenContext &t) {
  return FriendTemplateDecl::from(t.as_declaration());
}

NamedDecl FriendTemplateDecl::friend_declaration(void) const {
  RawEntityId eid = impl->reader.getVal52();
  return NamedDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Token FriendTemplateDecl::friend_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal59());
}

Type FriendTemplateDecl::friend_type(void) const {
  RawEntityId eid = impl->reader.getVal60();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

unsigned FriendTemplateDecl::num_template_parameter_lists(void) const {
  return impl->reader.getVal54().size();
}

std::optional<TemplateParameterList> FriendTemplateDecl::nth_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal54();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateParameterListFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateParameterList(std::move(e));
}

gap::generator<TemplateParameterList> FriendTemplateDecl::template_parameter_lists(void) const & {
  auto list = impl->reader.getVal54();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d54 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d54));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
