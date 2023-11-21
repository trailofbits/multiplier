// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeAliasDecl.h>

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/TypeAliasTemplateDecl.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/TypedefNameDecl.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeAliasDecl> TypeAliasDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeAliasDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeAliasDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeAliasDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<TypeAliasDecl> TypeAliasDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = TypeAliasDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool TypeAliasDecl::contains(const Decl &decl) {
  for (auto &parent : TypeAliasDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool TypeAliasDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypeAliasDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TypeAliasDecl TypeAliasDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TypeAliasDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TypeAliasDecl> TypeAliasDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TypeAliasDecl> TypeAliasDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypeAliasDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<TypeAliasDecl> TypeAliasDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<TypeAliasDecl> TypeAliasDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const DeclKind kTypeAliasDeclDerivedKinds[] = {
    TypeAliasDecl::static_kind(),
};

}  // namespace

std::optional<TypeAliasDecl> TypeAliasDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case TypeAliasDecl::static_kind():
      return reinterpret_cast<const TypeAliasDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTypeAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypeAliasDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypeAliasDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypeAliasDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAliasDecl> TypeAliasDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypeAliasDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypeAliasDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const Reference &r) {
  return TypeAliasDecl::from(r.as_declaration());
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<TypeAliasTemplateDecl> TypeAliasDecl::described_alias_template(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal66();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TypeAliasTemplateDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
