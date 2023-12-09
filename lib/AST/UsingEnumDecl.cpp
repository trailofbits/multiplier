// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UsingEnumDecl.h>
#include <multiplier/AST/BaseUsingDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/EnumDecl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/Stmt.h>
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
static const DeclKind kUsingEnumDeclDerivedKinds[] = {
    UsingEnumDecl::static_kind(),
};
}  // namespace

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UsingEnumDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UsingEnumDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UsingEnumDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const ir::hl::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<UsingEnumDecl, ir::hl::Operation>> UsingEnumDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::hl::Operation> res : Decl::in(tu, kUsingEnumDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<UsingEnumDecl, ir::hl::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingEnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = UsingEnumDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool UsingEnumDecl::contains(const Decl &decl) {
  for (auto &parent : UsingEnumDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool UsingEnumDecl::contains(const Stmt &stmt) {
  for (auto &parent : UsingEnumDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

UsingEnumDecl UsingEnumDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (UsingEnumDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<UsingEnumDecl> UsingEnumDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<UsingEnumDecl> UsingEnumDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<UsingEnumDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<UsingEnumDecl> UsingEnumDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<UsingEnumDecl> UsingEnumDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<UsingEnumDecl> UsingEnumDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case UsingEnumDecl::static_kind():
      return reinterpret_cast<const UsingEnumDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kUsingEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<UsingEnumDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kUsingEnumDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<UsingEnumDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UsingEnumDecl> UsingEnumDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kUsingEnumDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<UsingEnumDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const Reference &r) {
  return UsingEnumDecl::from(r.as_declaration());
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

EnumDecl UsingEnumDecl::enum_declaration(void) const {
  RawEntityId eid = impl->reader.getVal56();
  return EnumDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token UsingEnumDecl::enum_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal57());
}

Type UsingEnumDecl::enum_type(void) const {
  RawEntityId eid = impl->reader.getVal58();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token UsingEnumDecl::using_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
