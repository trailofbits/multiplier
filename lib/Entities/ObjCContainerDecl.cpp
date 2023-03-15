// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCContainerDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCCategoryDecl.h>
#include <multiplier/Entities/ObjCCategoryImplDecl.h>
#include <multiplier/Entities/ObjCImplementationDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCMethodDecl.h>
#include <multiplier/Entities/ObjCPropertyDecl.h>
#include <multiplier/Entities/ObjCProtocolDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCContainerDecl> ObjCContainerDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCContainerDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCContainerDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCContainerDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCContainerDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCContainerDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCContainerDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCContainerDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCContainerDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCContainerDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCContainerDecl> dr = ObjCContainerDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCContainerDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCContainerDeclDerivedKinds[] = {
    ObjCInterfaceDecl::static_kind(),
    ObjCProtocolDecl::static_kind(),
    ObjCCategoryDecl::static_kind(),
    ObjCImplementationDecl::static_kind(),
    ObjCCategoryImplDecl::static_kind(),
};

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCInterfaceDecl::static_kind():
    case ObjCProtocolDecl::static_kind():
    case ObjCCategoryDecl::static_kind():
    case ObjCImplementationDecl::static_kind():
    case ObjCCategoryImplDecl::static_kind():
      return reinterpret_cast<const ObjCContainerDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCContainerDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCContainerDecl> e = ObjCContainerDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCContainerDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCContainerDecl> e = ObjCContainerDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCContainerDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCContainerDecl> e = ObjCContainerDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const Reference &r) {
  return ObjCContainerDecl::from(r.as_declaration());
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const TokenContext &t) {
  return ObjCContainerDecl::from(t.as_declaration());
}

unsigned ObjCContainerDecl::num_class_methods(void) const {
  return impl->reader.getVal47().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_class_method(unsigned n) const {
  auto list = impl->reader.getVal47();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::class_methods(void) const & {
  auto list = impl->reader.getVal47();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d47 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from(Decl(std::move(d47)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_class_properties(void) const {
  return impl->reader.getVal48().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_class_propertie(unsigned n) const {
  auto list = impl->reader.getVal48();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::class_properties(void) const & {
  auto list = impl->reader.getVal48();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d48 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from(Decl(std::move(d48)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

TokenRange ObjCContainerDecl::at_end_range(void) const {
  auto &ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  return fragment->TokenRangeFor(fragment, impl->reader.getVal52(), impl->reader.getVal53());
}

Token ObjCContainerDecl::at_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal54());
}

unsigned ObjCContainerDecl::num_instance_methods(void) const {
  return impl->reader.getVal58().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_instance_method(unsigned n) const {
  auto list = impl->reader.getVal58();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::instance_methods(void) const & {
  auto list = impl->reader.getVal58();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d58 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from(Decl(std::move(d58)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_instance_properties(void) const {
  return impl->reader.getVal169().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_instance_propertie(unsigned n) const {
  auto list = impl->reader.getVal169();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::instance_properties(void) const & {
  auto list = impl->reader.getVal169();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d169 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from(Decl(std::move(d169)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_methods(void) const {
  return impl->reader.getVal177().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_method(unsigned n) const {
  auto list = impl->reader.getVal177();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::methods(void) const & {
  auto list = impl->reader.getVal177();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d177 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from(Decl(std::move(d177)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_properties(void) const {
  return impl->reader.getVal178().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_propertie(unsigned n) const {
  auto list = impl->reader.getVal178();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::properties(void) const & {
  auto list = impl->reader.getVal178();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d178 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from(Decl(std::move(d178)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<Decl> ObjCContainerDecl::declarations_in_context(void) const & {
  EntityProvider::Ptr ep = impl->ep;
  auto list = impl->reader.getVal179();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
