// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypedefNameDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeDecl.h>
#include <multiplier/AST/ObjCTypeParamDecl.h>
#include <multiplier/AST/TypeAliasDecl.h>
#include <multiplier/AST/TypedefDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kTypedefNameDeclDerivedKinds[] = {
    ObjCTypeParamDecl::static_kind(),
    TypeAliasDecl::static_kind(),
    TypedefDecl::static_kind(),
};
}  // namespace

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

#ifndef MX_DISABLE_VAST
std::optional<TypedefNameDecl> TypedefNameDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<TypedefNameDecl, ir::Operation>> TypedefNameDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kTypedefNameDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<TypedefNameDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

#endif  // MX_DISABLE_VAST

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
    if (*this == parent) { return true; }
  }
  return false;
}

bool TypedefNameDecl::contains(const Stmt &stmt) {
  for (auto &parent : TypedefNameDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

TypedefNameDecl TypedefNameDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (TypedefNameDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<TypedefNameDecl> TypedefNameDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<TypedefNameDecl> TypedefNameDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<TypedefNameDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TypedefNameDecl> TypedefNameDecl::from_base(const Decl &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kTypedefNameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<TypedefNameDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kTypedefNameDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<TypedefNameDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypedefNameDecl> TypedefNameDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kTypedefNameDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<TypedefNameDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const Reference &r) {
  return TypedefNameDecl::from(r.as_declaration());
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<TagDecl> TypedefNameDecl::anonymous_declaration_with_typedef_name(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal57();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TagDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type TypedefNameDecl::underlying_type(void) const {
  RawEntityId eid = impl->reader.getVal58();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool TypedefNameDecl::is_moded(void) const {
  return impl->reader.getVal74();
}

bool TypedefNameDecl::is_transparent_tag(void) const {
  return impl->reader.getVal75();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
