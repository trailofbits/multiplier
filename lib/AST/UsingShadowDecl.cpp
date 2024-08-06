// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UsingShadowDecl.h>
#include <multiplier/AST/BaseUsingDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ConstructorUsingShadowDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kUsingShadowDeclDerivedKinds[] = {
    UsingShadowDecl::static_kind(),
    ConstructorUsingShadowDecl::static_kind(),
};
}  // namespace

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingShadowDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingShadowDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingShadowDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<UsingShadowDecl> UsingShadowDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingShadowDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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

std::optional<UsingShadowDecl> UsingShadowDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<UsingShadowDecl, ir::Operation>> UsingShadowDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kUsingShadowDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<UsingShadowDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool UsingShadowDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingShadowDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UsingShadowDecl UsingShadowDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UsingShadowDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UsingShadowDecl> UsingShadowDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<UsingShadowDecl> UsingShadowDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingShadowDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<UsingShadowDecl> UsingShadowDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case UsingShadowDecl::static_kind():
    case ConstructorUsingShadowDecl::static_kind():
      return reinterpret_cast<const UsingShadowDecl &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const Reference &r) {
  return UsingShadowDecl::from(r.as_declaration());
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

BaseUsingDecl UsingShadowDecl::introducer(void) const {
  RawEntityId eid = impl->reader.getVal48();
  return BaseUsingDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

std::optional<UsingShadowDecl> UsingShadowDecl::next_using_shadow_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal49();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return UsingShadowDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

NamedDecl UsingShadowDecl::target_declaration(void) const {
  RawEntityId eid = impl->reader.getVal50();
  return NamedDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
