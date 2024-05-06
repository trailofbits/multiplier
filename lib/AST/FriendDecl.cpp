// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FriendDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kFriendDeclDerivedKinds[] = {
    FriendDecl::static_kind(),
};
}  // namespace

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

std::optional<FriendDecl> FriendDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<FriendDecl, ir::Operation>> FriendDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kFriendDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<FriendDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool FriendDecl::contains(const Stmt &stmt) {
  for (auto &parent : FriendDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

FriendDecl FriendDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FriendDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FriendDecl> FriendDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FriendDecl> FriendDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FriendDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<FriendDecl> FriendDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FriendDecl> FriendDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case FriendDecl::static_kind():
      return reinterpret_cast<const FriendDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FriendDecl> FriendDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFriendDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FriendDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendDecl> FriendDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFriendDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FriendDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<FriendDecl> FriendDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kFriendDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<FriendDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<FriendDecl> FriendDecl::from(const Reference &r) {
  return FriendDecl::from(r.as_declaration());
}

std::optional<FriendDecl> FriendDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FriendDecl> FriendDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<NamedDecl> FriendDecl::friend_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal38();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return NamedDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Token FriendDecl::friend_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

std::optional<Type> FriendDecl::friend_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal46();
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
  return impl->reader.getVal39();
}

unsigned FriendDecl::num_friend_type_template_parameter_lists(void) const {
  return impl->reader.getVal40().size();
}

std::optional<TemplateParameterList> FriendDecl::nth_friend_type_template_parameter_list(unsigned n) const {
  auto list = impl->reader.getVal40();
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

gap::generator<TemplateParameterList> FriendDecl::friend_type_template_parameter_lists(void) const & {
  auto list = impl->reader.getVal40();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d40 = ep->TemplateParameterListFor(ep, v)) {
      co_yield TemplateParameterList(std::move(d40));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
