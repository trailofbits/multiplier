// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypedefDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeDecl.h>
#include <multiplier/Entities/TypedefNameDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypedefDecl> TypedefDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypedefDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypedefDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypedefDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypedefDecl> TypedefDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypedefDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypedefDecl> TypedefDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypedefDecl> TypedefDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypedefDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypedefDecl> TypedefDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypedefDecl::contains(const Decl &decl) {
  for (auto &parent : TypedefDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TypedefDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypedefDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TypedefDecl TypedefDecl::canonical_declaration(void) const {
  if (auto canon = TypedefDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TypedefDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TypedefDecl> TypedefDecl::definition(void) const {
  return TypedefDecl::from(this->Decl::definition());
}

gap::generator<TypedefDecl> TypedefDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypedefDecl> dr = TypedefDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TypedefDecl> TypedefDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TypedefDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTypedefDeclDerivedKinds[] = {
    TypedefDecl::static_kind(),
};

std::optional<TypedefDecl> TypedefDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case TypedefDecl::static_kind():
      return reinterpret_cast<const TypedefDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypedefDecl> TypedefDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTypedefDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypedefDecl> e = TypedefDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefDecl> TypedefDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypedefDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypedefDecl> e = TypedefDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefDecl> TypedefDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypedefDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypedefDecl> e = TypedefDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypedefDecl> TypedefDecl::from(const Reference &r) {
  return TypedefDecl::from(r.as_declaration());
}

std::optional<TypedefDecl> TypedefDecl::from(const TokenContext &t) {
  return TypedefDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
