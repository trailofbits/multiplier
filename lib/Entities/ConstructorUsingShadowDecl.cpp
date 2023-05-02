// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConstructorUsingShadowDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UsingShadowDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConstructorUsingShadowDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConstructorUsingShadowDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConstructorUsingShadowDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ConstructorUsingShadowDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ConstructorUsingShadowDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ConstructorUsingShadowDecl::contains(const Decl &decl) {
  for (auto &parent : ConstructorUsingShadowDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ConstructorUsingShadowDecl::contains(const Stmt &stmt) {
  for (auto &parent : ConstructorUsingShadowDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ConstructorUsingShadowDecl ConstructorUsingShadowDecl::canonical_declaration(void) const {
  if (auto canon = ConstructorUsingShadowDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ConstructorUsingShadowDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::definition(void) const {
  return ConstructorUsingShadowDecl::from(this->Decl::definition());
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ConstructorUsingShadowDecl> dr = ConstructorUsingShadowDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ConstructorUsingShadowDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kConstructorUsingShadowDeclDerivedKinds[] = {
    ConstructorUsingShadowDecl::static_kind(),
};

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ConstructorUsingShadowDecl::static_kind():
      return reinterpret_cast<const ConstructorUsingShadowDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kConstructorUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ConstructorUsingShadowDecl> e = ConstructorUsingShadowDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kConstructorUsingShadowDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ConstructorUsingShadowDecl> e = ConstructorUsingShadowDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kConstructorUsingShadowDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ConstructorUsingShadowDecl> e = ConstructorUsingShadowDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const Reference &r) {
  return ConstructorUsingShadowDecl::from(r.as_declaration());
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const TokenContext &t) {
  return ConstructorUsingShadowDecl::from(t.as_declaration());
}

bool ConstructorUsingShadowDecl::constructs_virtual_base(void) const {
  return impl->reader.getVal72();
}

CXXRecordDecl ConstructorUsingShadowDecl::constructed_base_class(void) const {
  RawEntityId eid = impl->reader.getVal64();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::constructed_base_class_shadow_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal65();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ConstructorUsingShadowDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

CXXRecordDecl ConstructorUsingShadowDecl::nominated_base_class(void) const {
  RawEntityId eid = impl->reader.getVal66();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::nominated_base_class_shadow_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal76();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ConstructorUsingShadowDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
