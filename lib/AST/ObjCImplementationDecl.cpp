// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCImplementationDecl.h>
#include <multiplier/AST/CXXCtorInitializer.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/NamedDecl.h>
#include <multiplier/AST/ObjCContainerDecl.h>
#include <multiplier/AST/ObjCImplDecl.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCIvarDecl.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/Frontend/Token.h>

#include <multiplier/IR/HighLevel/Operation.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const DeclKind kObjCImplementationDeclDerivedKinds[] = {
    ObjCImplementationDecl::static_kind(),
};
}  // namespace

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCImplementationDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCImplementationDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCImplementationDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const ir::Operation &op) {
  if (auto val = Decl::from(op)) {
    return from_base(val.value());
  }
  return std::nullopt;
}

gap::generator<std::pair<ObjCImplementationDecl, ir::Operation>> ObjCImplementationDecl::in(const Compilation &tu) {
  for (std::pair<Decl, ir::Operation> res : Decl::in(tu, kObjCImplementationDeclDerivedKinds)) {
    if (auto val = from_base(res.first)) {
      co_yield std::pair<ObjCImplementationDecl, ir::Operation>(std::move(val.value()), std::move(res.second));
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplementationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCImplementationDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCImplementationDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCImplementationDecl::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ObjCImplementationDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCImplementationDecl::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

ObjCImplementationDecl ObjCImplementationDecl::canonical_declaration(void) const {
  if (auto canon = from_base(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCImplementationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::definition(void) const {
  if (auto def = this->Decl::definition()) {
    return from_base(def.value());
  }
  return std::nullopt;
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCImplementationDecl> dr = from_base(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const std::optional<Decl> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from_base(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCImplementationDecl::static_kind():
      return reinterpret_cast<const ObjCImplementationDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (DeclKind k : kObjCImplementationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCImplementationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCImplementationDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCImplementationDecl> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCImplementationDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCImplementationDecl> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const Reference &r) {
  return ObjCImplementationDecl::from(r.as_declaration());
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const VariantEntity &e) {
  if (!std::holds_alternative<Decl>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Decl>(e));
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const TokenContext &t) {
  if (auto base = t.as_declaration()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token ObjCImplementationDecl::instance_variable_l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal67());
}

Token ObjCImplementationDecl::instance_variable_r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal68());
}

std::string_view ObjCImplementationDecl::obj_c_runtime_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal74();
  return std::string_view(data.cStr(), data.size());
}

ObjCInterfaceDecl ObjCImplementationDecl::super_class(void) const {
  RawEntityId eid = impl->reader.getVal79();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Token ObjCImplementationDecl::super_class_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal80());
}

bool ObjCImplementationDecl::has_destructors(void) const {
  return impl->reader.getVal75();
}

bool ObjCImplementationDecl::has_non_zero_constructors(void) const {
  return impl->reader.getVal76();
}

unsigned ObjCImplementationDecl::num_initializers(void) const {
  return impl->reader.getVal350().size();
}

std::optional<CXXCtorInitializer> ObjCImplementationDecl::nth_initializer(unsigned n) const {
  auto list = impl->reader.getVal350();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->CXXCtorInitializerFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return CXXCtorInitializer(std::move(e));
}

gap::generator<CXXCtorInitializer> ObjCImplementationDecl::initializers(void) const & {
  auto list = impl->reader.getVal350();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d350 = ep->CXXCtorInitializerFor(ep, v)) {
      co_yield CXXCtorInitializer(std::move(d350));
    }
  }
  co_return;
}

unsigned ObjCImplementationDecl::num_instance_variables(void) const {
  return impl->reader.getVal351().size();
}

std::optional<ObjCIvarDecl> ObjCImplementationDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal351();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCIvarDecl::from_base(std::move(e));
}

gap::generator<ObjCIvarDecl> ObjCImplementationDecl::instance_variables(void) const & {
  auto list = impl->reader.getVal351();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d351 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from_base(std::move(d351))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
