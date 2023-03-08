// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FriendDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateParameterList.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FriendDecl> FriendDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FriendDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FriendDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FriendDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<FriendDecl> FriendDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FriendDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FriendDecl> FriendDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<FriendDecl> FriendDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = FriendDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<FriendDecl> FriendDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool FriendDecl::contains(const Decl &decl) {
  for (auto &parent : FriendDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool FriendDecl::contains(const Stmt &stmt) {
  for (auto &parent : FriendDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<FriendDecl> FriendDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FriendDecl> dr = FriendDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<FriendDecl> FriendDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return FriendDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kFriendDeclDerivedKinds[] = {
    FriendDecl::static_kind(),
};

std::optional<FriendDecl> FriendDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case FriendDecl::static_kind():
      return reinterpret_cast<const FriendDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FriendDecl> FriendDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kFriendDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FriendDecl> e = FriendDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendDecl> FriendDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFriendDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FriendDecl> e = FriendDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendDecl> FriendDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFriendDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FriendDecl> e = FriendDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NamedDecl> FriendDecl::friend_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal45();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token FriendDecl::friend_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal52());
}

std::optional<Type> FriendDecl::friend_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal53();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool FriendDecl::is_unsupported_friend(void) const {
  return impl->reader.getVal46();
}

unsigned FriendDecl::num_friend_type_template_parameter_lists(void) const {
  return impl->reader.getVal47().size();
}

std::optional<TemplateParameterList> FriendDecl::nth_friend_type_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal47();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateParameterListFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateParameterList(std::move(e));
}

gap::generator<TemplateParameterList> FriendDecl::friend_type_template_parameter_lists(void) const & {
  auto list = impl->reader.getVal47();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d47 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d47));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
