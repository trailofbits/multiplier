// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypedefNameDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCTypeParamDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeAliasDecl.h>
#include <multiplier/Entities/TypeDecl.h>
#include <multiplier/Entities/TypedefDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypedefNameDecl> TypedefNameDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypedefNameDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypedefNameDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypedefNameDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypedefNameDecl> TypedefNameDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypedefNameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypedefNameDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypedefNameDecl::contains(const Decl &decl) {
  for (auto &parent : TypedefNameDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool TypedefNameDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypedefNameDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<TypedefNameDecl> TypedefNameDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypedefNameDecl> dr = TypedefNameDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TypedefNameDecl> TypedefNameDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TypedefNameDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTypedefNameDeclDerivedKinds[] = {
    ObjCTypeParamDecl::static_kind(),
    TypeAliasDecl::static_kind(),
    TypedefDecl::static_kind(),
};

std::optional<TypedefNameDecl> TypedefNameDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCTypeParamDecl::static_kind():
    case TypeAliasDecl::static_kind():
    case TypedefDecl::static_kind():
      return reinterpret_cast<const TypedefNameDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kTypedefNameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypedefNameDecl> e = TypedefNameDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypedefNameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypedefNameDecl> e = TypedefNameDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypedefNameDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypedefNameDecl> e = TypedefNameDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TagDecl> TypedefNameDecl::anonymous_declaration_with_typedef_name(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal53();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TagDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Type TypedefNameDecl::underlying_type(void) const {
  RawEntityId eid = impl->reader.getVal54();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool TypedefNameDecl::is_moded(void) const {
  return impl->reader.getVal70();
}

bool TypedefNameDecl::is_transparent_tag(void) const {
  return impl->reader.getVal71();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
