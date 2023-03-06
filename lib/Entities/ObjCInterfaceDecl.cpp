// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCInterfaceDecl.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/NamedDecl.h>
#include <multiplier/Entities/ObjCCategoryDecl.h>
#include <multiplier/Entities/ObjCContainerDecl.h>
#include <multiplier/Entities/ObjCImplementationDecl.h>
#include <multiplier/Entities/ObjCIvarDecl.h>
#include <multiplier/Entities/ObjCProtocolDecl.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Fragment.h"
#include "../Decl.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCInterfaceDecl::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCInterfaceDecl::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCInterfaceDecl::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCInterfaceDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_declaration(); ancestor.has_value();
       ancestor = ancestor->parent_declaration()) {
    if (auto d = ObjCInterfaceDecl::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ObjCInterfaceDecl::contains(const Decl &decl) {
  for (auto &parent : ObjCInterfaceDecl::containing(decl)) {
    if (parent == *this) { return true; }
  }
  return false;
}

bool ObjCInterfaceDecl::contains(const Stmt &stmt) {
  for (auto &parent : ObjCInterfaceDecl::containing(stmt)) {
    if (parent == *this) { return true; }
  }
  return false;
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::redeclarations(void) const & {
  for (Decl r : Decl::redeclarations()) {
    if (std::optional<ObjCInterfaceDecl> dr = ObjCInterfaceDecl::from(r)) {
      co_yield std::move(dr.value());
      continue;
    }
    assert(false);
  // Wrong type?
  }
  co_return;
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<DeclId>(vid)) {
    return ObjCInterfaceDecl::from(index.declaration(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const DeclKind kObjCInterfaceDeclDerivedKinds[] = {
    ObjCInterfaceDecl::static_kind(),
};

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case ObjCInterfaceDecl::static_kind():
      return reinterpret_cast<const ObjCInterfaceDecl &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k)) {
      if (std::optional<ObjCInterfaceDecl> e = ObjCInterfaceDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
    for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
      if (std::optional<ObjCInterfaceDecl> e = ObjCInterfaceDecl::from(Decl(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCInterfaceDecl> ObjCInterfaceDecl::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (DeclKind k : kObjCInterfaceDeclDerivedKinds) {
      for (DeclImplPtr eptr : ep->DeclsFor(ep, k, frag_id)) {
        if (std::optional<ObjCInterfaceDecl> e = ObjCInterfaceDecl::from(Decl(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_all_referenced_protocol(unsigned n) const {
  auto list = impl->reader.getVal313();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCInterfaceDecl::all_referenced_protocols(void) const & {
  auto list = impl->reader.getVal313();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d313 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d313)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

bool ObjCInterfaceDecl::declares_or_inherits_designated_initializers(void) const {
  return impl->reader.getVal70();
}

Token ObjCInterfaceDecl::end_of_definition_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal62());
}

ObjCImplementationDecl ObjCInterfaceDecl::implementation(void) const {
  RawEntityId eid = impl->reader.getVal63();
  return ObjCImplementationDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::string_view ObjCInterfaceDecl::obj_c_runtime_name_as_string(void) const {
  capnp::Text::Reader data = impl->reader.getVal69();
  return std::string_view(data.cStr(), data.size());
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::super_class(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal64();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return ObjCInterfaceDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

Token ObjCInterfaceDecl::super_class_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal73());
}

std::optional<Type> ObjCInterfaceDecl::super_class_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal75();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

Type ObjCInterfaceDecl::type_for_declaration(void) const {
  RawEntityId eid = impl->reader.getVal76();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ObjCInterfaceDecl::has_definition(void) const {
  return impl->reader.getVal71();
}

bool ObjCInterfaceDecl::has_designated_initializers(void) const {
  return impl->reader.getVal72();
}

bool ObjCInterfaceDecl::is_arc_weakref_unavailable(void) const {
  return impl->reader.getVal88();
}

bool ObjCInterfaceDecl::is_implicit_interface_declaration(void) const {
  return impl->reader.getVal89();
}

ObjCInterfaceDecl ObjCInterfaceDecl::is_obj_c_requires_property_definitions(void) const {
  RawEntityId eid = impl->reader.getVal77();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool ObjCInterfaceDecl::is_this_declaration_a_definition(void) const {
  return impl->reader.getVal90();
}

std::optional<ObjCIvarDecl> ObjCInterfaceDecl::nth_instance_variable(unsigned n) const {
  auto list = impl->reader.getVal339();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCIvarDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCIvarDecl> ObjCInterfaceDecl::instance_variables(void) const & {
  auto list = impl->reader.getVal339();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d339 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCIvarDecl::from(Decl(std::move(d339)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_known_categorie(unsigned n) const {
  auto list = impl->reader.getVal341();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::known_categories(void) const & {
  auto list = impl->reader.getVal341();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d341 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from(Decl(std::move(d341)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_known_extension(unsigned n) const {
  auto list = impl->reader.getVal342();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::known_extensions(void) const & {
  auto list = impl->reader.getVal342();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d342 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from(Decl(std::move(d342)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<Token> ObjCInterfaceDecl::nth_protocol_token(unsigned n) const {
  auto list = impl->reader.getVal347();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TokenFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Token(std::move(e));
}

gap::generator<Token> ObjCInterfaceDecl::protocol_tokens(void) const & {
  auto list = impl->reader.getVal347();
  EntityProvider::Ptr ep = impl->ep;
  auto fragment = ep->FragmentFor(ep, impl->fragment_id);
  if (!fragment) {
    assert(false);
    co_return;
  }
  auto tok_reader = fragment->ParsedTokenReader(fragment);
  for (auto v : list) {
    EntityId id(v);
    if (auto t347 = ep->TokenFor(ep, tok_reader, v)) {
      co_yield t347;
    }
  }
  co_return;
}

std::optional<ObjCProtocolDecl> ObjCInterfaceDecl::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal348();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCInterfaceDecl::protocols(void) const & {
  auto list = impl->reader.getVal348();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d348 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d348)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_categorie(unsigned n) const {
  auto list = impl->reader.getVal349();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::visible_categories(void) const & {
  auto list = impl->reader.getVal349();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d349 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from(Decl(std::move(d349)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

std::optional<ObjCCategoryDecl> ObjCInterfaceDecl::nth_visible_extension(unsigned n) const {
  auto list = impl->reader.getVal350();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCCategoryDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCCategoryDecl> ObjCInterfaceDecl::visible_extensions(void) const & {
  auto list = impl->reader.getVal350();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d350 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCCategoryDecl::from(Decl(std::move(d350)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
