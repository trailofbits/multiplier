// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCPropertyDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/ObjCMethodDecl.h>
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
static const DeclKind kObjCPropertyDeclDerivedKinds[] = {
    ObjCPropertyDecl::static_kind(),
};
}  // namespace

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCPropertyDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCPropertyDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCPropertyDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCPropertyDecl, ir::Operation>> ObjCPropertyDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCPropertyDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCPropertyDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCPropertyDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCPropertyDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCPropertyDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCPropertyDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCPropertyDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCPropertyDecl ObjCPropertyDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCPropertyDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCPropertyDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCPropertyDecl::static_kind():
      return reinterpret_cast<const ObjCPropertyDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCPropertyDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCPropertyDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCPropertyDecl> ObjCPropertyDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCPropertyDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCPropertyDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const Reference &r) {
  return ObjCPropertyDecl::from(r.as_declaration());
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCPropertyDecl::at_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal56());
}

ObjCMethodDecl ObjCPropertyDecl::getter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal57();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCPropertyDecl::getter_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal58());
}

Token ObjCPropertyDecl::l_paren_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal66());
}

ObjCPropertyDeclPropertyControl ObjCPropertyDecl::property_implementation(void) const {
  return static_cast<ObjCPropertyDeclPropertyControl>(impl->reader.getVal81());
}

ObjCIvarDecl ObjCPropertyDecl::property_instance_variable_declaration(void) const {
  RawEntityId eid = impl->reader.getVal67();
  return ObjCIvarDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

ObjCPropertyQueryKind ObjCPropertyDecl::query_kind(void) const {
  return static_cast<ObjCPropertyQueryKind>(impl->reader.getVal86());
}

ObjCPropertyDeclSetterKind ObjCPropertyDecl::setter_kind(void) const {
  return static_cast<ObjCPropertyDeclSetterKind>(impl->reader.getVal88());
}

ObjCMethodDecl ObjCPropertyDecl::setter_method_declaration(void) const {
  RawEntityId eid = impl->reader.getVal68();
  return ObjCMethodDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCPropertyDecl::setter_name_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal79());
}

Type ObjCPropertyDecl::type(void) const {
  RawEntityId eid = impl->reader.getVal80();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCPropertyDecl::is_atomic(void) const {
  return impl->reader.getVal75();
}

bool ObjCPropertyDecl::is_class_property(void) const {
  return impl->reader.getVal76();
}

bool ObjCPropertyDecl::is_direct_property(void) const {
  return impl->reader.getVal77();
}

bool ObjCPropertyDecl::is_instance_property(void) const {
  return impl->reader.getVal78();
}

bool ObjCPropertyDecl::is_optional(void) const {
  return impl->reader.getVal95();
}

bool ObjCPropertyDecl::is_read_only(void) const {
  return impl->reader.getVal96();
}

bool ObjCPropertyDecl::is_retaining(void) const {
  return impl->reader.getVal97();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
