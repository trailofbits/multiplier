// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCImplementationDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCContainerDecl.h>
#include <multiplier/Entities/ObjCImplDecl.h>
#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
  if (auto canon = ObjCImplementationDecl::from(this->Decl::canonical_declaration())) {
    return std::move(canon.value());
  }
  for (ObjCImplementationDecl redecl : redeclarations()) {
    return redecl;
  }
  __builtin_unreachable();
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::definition(void) const {
  return ObjCImplementationDecl::from(this->Decl::definition());
}

gap::generator<ObjCImplementationDecl> ObjCImplementationDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCImplementationDecl> dr = ObjCImplementationDecl::from(r)) {
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
    return ObjCImplementationDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCImplementationDeclDerivedKinds[] = {
    ObjCImplementationDecl::static_kind(),
};

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const Decl &parent) {
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
      if (std::optional<ObjCImplementationDecl> e = ObjCImplementationDecl::from(Decl(std::move(eptr)))) {
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
      if (std::optional<ObjCImplementationDecl> e = ObjCImplementationDecl::from(Decl(std::move(eptr)))) {
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
        if (std::optional<ObjCImplementationDecl> e = ObjCImplementationDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const Reference &r) {
  return ObjCImplementationDecl::from(r.as_declaration());
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const TokenContext &t) {
  return ObjCImplementationDecl::from(t.as_declaration());
}

Token ObjCImplementationDecl::instance_variable_l_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal68());
}

Token ObjCImplementationDecl::instance_variable_r_brace_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal69());
}

std::string_view ObjCImplementationDecl::obj_c_runtime_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal74();
  return std::string_view(data.cStr(), data.size());
}

ObjCInterfaceDecl ObjCImplementationDecl::super_class(void) const {
  RawEntityId eid = impl->reader.getVal79();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
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

unsigned ObjCImplementationDecl::num_instance_variables(void) const {
  return impl->reader.getVal340().size();
}

std::optional<ObjCIvarDecl> ObjCImplementationDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal340();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCIvarDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCIvarDecl> ObjCImplementationDecl::instance_variables(void) const & {
  auto list = impl->reader.getVal340();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d340 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from(Decl(std::move(d340)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
