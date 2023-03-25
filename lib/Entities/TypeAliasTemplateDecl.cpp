// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeAliasTemplateDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/RedeclarableTemplateDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/TemplateDecl.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeAliasTemplateDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeAliasTemplateDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeAliasTemplateDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeAliasTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeAliasTemplateDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypeAliasTemplateDecl::contains(const Decl &decl) {
  for (auto &parent : TypeAliasTemplateDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool TypeAliasTemplateDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypeAliasTemplateDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

TypeAliasTemplateDecl TypeAliasTemplateDecl::canonical_declaration(void) const {
  if (auto canon = TypeAliasTemplateDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TypeAliasTemplateDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::definition(void) const {
  return TypeAliasTemplateDecl::from(this->Decl::definition());
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypeAliasTemplateDecl> dr = TypeAliasTemplateDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return TypeAliasTemplateDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kTypeAliasTemplateDeclDerivedKinds[] = {
    TypeAliasTemplateDecl::static_kind(),
};

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case TypeAliasTemplateDecl::static_kind():
      return reinterpret_cast<const TypeAliasTemplateDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kTypeAliasTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypeAliasTemplateDecl> e = TypeAliasTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypeAliasTemplateDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypeAliasTemplateDecl> e = TypeAliasTemplateDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAliasTemplateDecl> TypeAliasTemplateDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypeAliasTemplateDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypeAliasTemplateDecl> e = TypeAliasTemplateDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const Reference &r) {
  return TypeAliasTemplateDecl::from(r.as_declaration());
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const TokenContext &t) {
  return TypeAliasTemplateDecl::from(t.as_declaration());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
