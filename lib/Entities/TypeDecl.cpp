// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeDecl.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/Entities/ClassTemplateSpecializationDecl.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/EnumDecl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCTypeParamDecl.h>
#include <multiplier/Entities/RecordDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateTypeParmDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeAliasDecl.h>
#include <multiplier/Entities/TypedefDecl.h>
#include <multiplier/Entities/UnresolvedUsingTypenameDecl.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeDecl> TypeDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypeDecl> TypeDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeDecl> TypeDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypeDecl> TypeDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeDecl> TypeDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypeDecl::contains(const Decl &decl) {
  for (auto &parent : TypeDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool TypeDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypeDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<TypeDecl> TypeDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypeDecl> dr = TypeDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TypeDecl> TypeDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TypeDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTypeDeclDerivedKinds[] = {
    UnresolvedUsingTypenameDecl::static_kind(),
    TemplateTypeParmDecl::static_kind(),
    ObjCTypeParamDecl::static_kind(),
    TypeAliasDecl::static_kind(),
    TypedefDecl::static_kind(),
    EnumDecl::static_kind(),
    RecordDecl::static_kind(),
    CXXRecordDecl::static_kind(),
    ClassTemplateSpecializationDecl::static_kind(),
    ClassTemplatePartialSpecializationDecl::static_kind(),
};

std::optional<TypeDecl> TypeDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingTypenameDecl::static_kind():
    case TemplateTypeParmDecl::static_kind():
    case ObjCTypeParamDecl::static_kind():
    case TypeAliasDecl::static_kind():
    case TypedefDecl::static_kind():
    case EnumDecl::static_kind():
    case RecordDecl::static_kind():
    case CXXRecordDecl::static_kind():
    case ClassTemplateSpecializationDecl::static_kind():
    case ClassTemplatePartialSpecializationDecl::static_kind():
      return reinterpret_cast<const TypeDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeDecl> TypeDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kTypeDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypeDecl> e = TypeDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeDecl> TypeDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypeDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypeDecl> e = TypeDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeDecl> TypeDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypeDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypeDecl> e = TypeDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeDecl> TypeDecl::from(const Reference &r) {
  return TypeDecl::from(r.as_declaration());
}

std::optional<TypeDecl> TypeDecl::from(const TokenContext &t) {
  return TypeDecl::from(t.as_declaration());
}

std::optional<Type> TypeDecl::type_for_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal52();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
