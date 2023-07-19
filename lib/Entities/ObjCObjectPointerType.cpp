// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCObjectPointerType.h>

#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCInterfaceType.h>
#include <multiplier/Entities/ObjCObjectType.h>
#include <multiplier/Entities/ObjCProtocolDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCObjectPointerType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCObjectPointerType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCObjectPointerType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ObjCObjectPointerType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kObjCObjectPointerTypeDerivedKinds[] = {
    ObjCObjectPointerType::static_kind(),
};

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::from(const Type &parent) {
  switch (parent.kind()) {
    case ObjCObjectPointerType::static_kind():
      return reinterpret_cast<const ObjCObjectPointerType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCObjectPointerType> ObjCObjectPointerType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kObjCObjectPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCObjectPointerType> e = ObjCObjectPointerType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::from(const Reference &r) {
  return ObjCObjectPointerType::from(r.as_type());
}

std::optional<ObjCObjectPointerType> ObjCObjectPointerType::from(const TokenContext &t) {
  return ObjCObjectPointerType::from(t.as_type());
}

Type ObjCObjectPointerType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ObjCInterfaceDecl ObjCObjectPointerType::interface_declaration(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

ObjCInterfaceType ObjCObjectPointerType::interface_type(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return ObjCInterfaceType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

ObjCObjectType ObjCObjectPointerType::object_type(void) const {
  RawEntityId eid = impl->reader.getVal237();
  return ObjCObjectType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

Type ObjCObjectPointerType::super_class_type(void) const {
  RawEntityId eid = impl->reader.getVal267();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

unsigned ObjCObjectPointerType::num_type_arguments(void) const {
  return impl->reader.getVal234().size();
}

std::optional<Type> ObjCObjectPointerType::nth_type_argument(unsigned n) const {
  auto list = impl->reader.getVal234();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TypeFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return Type(std::move(e));
}

gap::generator<Type> ObjCObjectPointerType::type_arguments(void) const & {
  auto list = impl->reader.getVal234();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d234 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d234));
    }
  }
  co_return;
}

gap::generator<Type> ObjCObjectPointerType::type_arguments_as_written(void) const & {
  auto list = impl->reader.getVal266();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d266 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d266));
    }
  }
  co_return;
}

bool ObjCObjectPointerType::is_kind_of_type(void) const {
  return impl->reader.getVal231();
}

bool ObjCObjectPointerType::is_obj_c_id_or_class_type(void) const {
  return impl->reader.getVal232();
}

bool ObjCObjectPointerType::is_specialized(void) const {
  return impl->reader.getVal233();
}

bool ObjCObjectPointerType::is_specialized_as_written(void) const {
  return impl->reader.getVal239();
}

bool ObjCObjectPointerType::is_sugared(void) const {
  return impl->reader.getVal240();
}

bool ObjCObjectPointerType::is_unspecialized(void) const {
  return impl->reader.getVal241();
}

bool ObjCObjectPointerType::is_unspecialized_as_written(void) const {
  return impl->reader.getVal242();
}

unsigned ObjCObjectPointerType::num_qualifiers(void) const {
  return impl->reader.getVal269().size();
}

std::optional<ObjCProtocolDecl> ObjCObjectPointerType::nth_qualifier(unsigned n) const {
  auto list = impl->reader.getVal269();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCObjectPointerType::qualifiers(void) const & {
  auto list = impl->reader.getVal269();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d269 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d269)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

ObjCObjectPointerType ObjCObjectPointerType::strip_obj_c_kind_of_type_and_qualifiers(void) const {
  RawEntityId eid = impl->reader.getVal268();
  return ObjCObjectPointerType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

unsigned ObjCObjectPointerType::num_protocols(void) const {
  return impl->reader.getVal270().size();
}

std::optional<ObjCProtocolDecl> ObjCObjectPointerType::nth_protocol(unsigned n) const {
  auto list = impl->reader.getVal270();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->DeclFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return ObjCProtocolDecl::from(Decl(std::move(e)));
}

gap::generator<ObjCProtocolDecl> ObjCObjectPointerType::protocols(void) const & {
  auto list = impl->reader.getVal270();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d270 = ep->DeclFor(ep, v)) {
      if (auto e = ObjCProtocolDecl::from(Decl(std::move(d270)))) {
        co_yield std::move(*e);
      }
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
