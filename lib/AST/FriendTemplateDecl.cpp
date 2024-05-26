// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FriendTemplateDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
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
static const DeclKind kFriendTemplateDeclDerivedKinds[] = {
    FriendTemplateDecl::static_kind(),
};
}  // namespace

gap::generator<FriendTemplateDecl> FriendTemplateDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kFriendTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<FriendTemplateDecl> e = from_base(std::move(eptr))) {
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
        if (std::optional<FriendTemplateDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kFriendTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<FriendTemplateDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<FriendTemplateDecl, ir::Operation>> FriendTemplateDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kFriendTemplateDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<FriendTemplateDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (FriendTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<FriendTemplateDecl> FriendTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<FriendTemplateDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case FriendTemplateDecl::static_kind():
      return reinterpret_cast<const FriendTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const Reference &r) {
  return FriendTemplateDecl::from(r.as_declaration());
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

NamedDecl FriendTemplateDecl::friend_declaration(void) const {
  RawEntityId eid = impl->reader.getVal38();
  return NamedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token FriendTemplateDecl::friend_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal45());
}

Type FriendTemplateDecl::friend_type(void) const {
  RawEntityId eid = impl->reader.getVal46();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

unsigned FriendTemplateDecl::num_template_parameter_lists(void) const {
  return impl->reader.getVal40().size();
}

std::optional<TemplateParameterList> FriendTemplateDecl::nth_template_parameter_list(unsigned n) const {
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

gap::generator<TemplateParameterList> FriendTemplateDecl::template_parameter_lists(void) const & {
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
