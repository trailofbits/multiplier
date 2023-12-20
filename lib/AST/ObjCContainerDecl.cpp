// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCMethodDecl.h>
#include <multiplier/AST/ObjCPropertyDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/ObjCCategoryDecl.h>
#include <multiplier/AST/ObjCCategoryImplDecl.h>
#include <multiplier/AST/ObjCImplementationDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCProtocolDecl.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kObjCContainerDeclDerivedKinds[] = {
    ObjCInterfaceDecl::static_kind(),
    ObjCProtocolDecl::static_kind(),
    ObjCCategoryDecl::static_kind(),
    ObjCImplementationDecl::static_kind(),
    ObjCCategoryImplDecl::static_kind(),
};
}  // namespace

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

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCContainerDecl, ir::Operation>> ObjCContainerDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCContainerDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCContainerDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
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
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCContainerDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCContainerDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCContainerDecl ObjCContainerDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCContainerDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCContainerDecl> dr = from_base(r)) {
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
    if (auto base = index.declaration(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from_base(const Decl &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCContainerDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCContainerDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCContainerDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCContainerDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCContainerDecl> ObjCContainerDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCContainerDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCContainerDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const Reference &r) {
  return ObjCContainerDecl::from(r.as_declaration());
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

unsigned ObjCContainerDecl::num_class_methods(void) const {
  return impl->reader.getVal51().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_class_method(unsigned n) const {
  auto list = impl->reader.getVal51();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from_base(std::move(e));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::class_methods(void) const & {
  auto list = impl->reader.getVal51();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d51 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from_base(std::move(d51))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_class_properties(void) const {
  return impl->reader.getVal52().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_class_propertie(unsigned n) const {
  auto list = impl->reader.getVal52();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from_base(std::move(e));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::class_properties(void) const & {
  auto list = impl->reader.getVal52();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d52 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from_base(std::move(d52))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

TokenRange ObjCContainerDecl::at_end_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal56(), impl->reader.getVal57());
}

Token ObjCContainerDecl::at_start_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal58());
}

unsigned ObjCContainerDecl::num_instance_methods(void) const {
  return impl->reader.getVal62().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_instance_method(unsigned n) const {
  auto list = impl->reader.getVal62();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from_base(std::move(e));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::instance_methods(void) const & {
  auto list = impl->reader.getVal62();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d62 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from_base(std::move(d62))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_instance_properties(void) const {
  return impl->reader.getVal179().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_instance_propertie(unsigned n) const {
  auto list = impl->reader.getVal179();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from_base(std::move(e));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::instance_properties(void) const & {
  auto list = impl->reader.getVal179();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d179 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from_base(std::move(d179))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_methods(void) const {
  return impl->reader.getVal187().size();
}

std::optional<ObjCMethodDecl> ObjCContainerDecl::nth_method(unsigned n) const {
  auto list = impl->reader.getVal187();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCMethodDecl::from_base(std::move(e));
}

gap::generator<ObjCMethodDecl> ObjCContainerDecl::methods(void) const & {
  auto list = impl->reader.getVal187();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d187 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCMethodDecl::from_base(std::move(d187))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

unsigned ObjCContainerDecl::num_properties(void) const {
  return impl->reader.getVal188().size();
}

std::optional<ObjCPropertyDecl> ObjCContainerDecl::nth_propertie(unsigned n) const {
  auto list = impl->reader.getVal188();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCPropertyDecl::from_base(std::move(e));
}

gap::generator<ObjCPropertyDecl> ObjCContainerDecl::properties(void) const & {
  auto list = impl->reader.getVal188();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d188 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCPropertyDecl::from_base(std::move(d188))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

gap::generator<Decl> ObjCContainerDecl::declarations_in_context(void) const & {
  EntityProviderPtr ep = impl->ep;
  auto list = impl->reader.getVal189();
  for (auto v : list) {
    if (auto eptr = ep->DeclFor(ep, v)) {
      co_yield std::move(eptr);
    }
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
