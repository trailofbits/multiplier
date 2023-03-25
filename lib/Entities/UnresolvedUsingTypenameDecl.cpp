// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedUsingTypenameDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedUsingTypenameDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UnresolvedUsingTypenameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UnresolvedUsingTypenameDecl::contains(const Decl &decl) {
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool UnresolvedUsingTypenameDecl::contains(const Stmt &stmt) {
  for (auto &parent : UnresolvedUsingTypenameDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::canonical_declaration(void) const {
  if (auto canon = UnresolvedUsingTypenameDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UnresolvedUsingTypenameDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::definition(void) const {
  return UnresolvedUsingTypenameDecl::from(this->Decl::definition());
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UnresolvedUsingTypenameDecl> dr = UnresolvedUsingTypenameDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return UnresolvedUsingTypenameDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kUnresolvedUsingTypenameDeclDerivedKinds[] = {
    UnresolvedUsingTypenameDecl::static_kind(),
};

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingTypenameDecl::static_kind():
      return reinterpret_cast<const UnresolvedUsingTypenameDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UnresolvedUsingTypenameDecl> e = UnresolvedUsingTypenameDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedUsingTypenameDecl> e = UnresolvedUsingTypenameDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUnresolvedUsingTypenameDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedUsingTypenameDecl> e = UnresolvedUsingTypenameDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const Reference &r) {
  return UnresolvedUsingTypenameDecl::from(r.as_declaration());
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const TokenContext &t) {
  return UnresolvedUsingTypenameDecl::from(t.as_declaration());
}

Token UnresolvedUsingTypenameDecl::ellipsis_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal55());
}

Token UnresolvedUsingTypenameDecl::typename_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

Token UnresolvedUsingTypenameDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal64());
}

bool UnresolvedUsingTypenameDecl::is_pack_expansion(void) const {
  return impl->reader.getVal72();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
