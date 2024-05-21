// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCImplDecl.h>
#include "../Reference.h"
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCPropertyImplDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ObjCCategoryImplDecl.h>
#include <multiplier/AST/ObjCImplementationDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kObjCImplDeclDerivedKinds[] = {
    ObjCImplementationDecl::static_kind(),
    ObjCCategoryImplDecl::static_kind(),
};
}  // namespace

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCImplDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCImplDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCImplDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCImplDecl, ir::Operation>> ObjCImplDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCImplDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCImplDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCImplDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCImplDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCImplDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCImplDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCImplDecl ObjCImplDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCImplDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCImplDecl> ObjCImplDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCImplDecl> ObjCImplDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCImplDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCImplDecl> ObjCImplDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCImplDecl> ObjCImplDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCImplDecl> ObjCImplDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCImplementationDecl::static_kind():
    case ObjCCategoryImplDecl::static_kind():
      return reinterpret_cast<const ObjCImplDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCImplDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCImplDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCImplDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplDecl> ObjCImplDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCImplDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCImplDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const Reference &r) {
  return ObjCImplDecl::from(r.as_declaration());
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

ObjCInterfaceDecl ObjCImplDecl::class_interface(void) const {
  RawEntityId eid = impl->reader.getVal55();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

unsigned ObjCImplDecl::num_property_implementations(void) const {
  return impl->reader.getVal323().size();
}

std::optional<ObjCPropertyImplDecl> ObjCImplDecl::nth_property_implementation(unsigned n) const {
  auto list = impl->reader.getVal323();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyImplDecl::from_base(std::move(e));
}

gap::generator<ObjCPropertyImplDecl> ObjCImplDecl::property_implementations(void) const & {
  auto list = impl->reader.getVal323();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d323 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyImplDecl::from_base(std::move(d323))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
