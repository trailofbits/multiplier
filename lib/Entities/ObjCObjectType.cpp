// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCObjectType.h>

#include <multiplier/Entities/ObjCInterfaceDecl.h>
#include <multiplier/Entities/ObjCInterfaceType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCObjectType> ObjCObjectType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCObjectType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCObjectType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCObjectType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCObjectType> ObjCObjectType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ObjCObjectType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kObjCObjectTypeDerivedKinds[] = {
    ObjCObjectType::static_kind(),
    ObjCInterfaceType::static_kind(),
};

std::optional<ObjCObjectType> ObjCObjectType::from(const Type &parent) {
  switch (parent.kind()) {
    case ObjCObjectType::static_kind():
    case ObjCInterfaceType::static_kind():
      return reinterpret_cast<const ObjCObjectType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCObjectType> ObjCObjectType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kObjCObjectTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCObjectType> e = ObjCObjectType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ObjCObjectType> ObjCObjectType::from(const Reference &r) {
  return ObjCObjectType::from(r.as_type());
}

std::optional<ObjCObjectType> ObjCObjectType::from(const TokenContext &t) {
  return ObjCObjectType::from(t.as_type());
}

Type ObjCObjectType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ObjCObjectType::base_type(void) const {
  RawEntityId eid = impl->reader.getVal237();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ObjCInterfaceDecl ObjCObjectType::interface(void) const {
  RawEntityId eid = impl->reader.getVal243();
  return ObjCInterfaceDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

std::optional<Type> ObjCObjectType::super_class_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal244();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

unsigned ObjCObjectType::num_type_arguments(void) const {
  return impl->reader.getVal241().size();
}

std::optional<Type> ObjCObjectType::nth_type_argument(unsigned n) const {
  auto list = impl->reader.getVal241();
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

gap::generator<Type> ObjCObjectType::type_arguments(void) const & {
  auto list = impl->reader.getVal241();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d241 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d241));
    }
  }
  co_return;
}

gap::generator<Type> ObjCObjectType::type_arguments_as_written(void) const & {
  auto list = impl->reader.getVal276();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d276 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d276));
    }
  }
  co_return;
}

bool ObjCObjectType::is_kind_of_type(void) const {
  return impl->reader.getVal238();
}

bool ObjCObjectType::is_kind_of_type_as_written(void) const {
  return impl->reader.getVal239();
}

bool ObjCObjectType::is_obj_c_class(void) const {
  return impl->reader.getVal240();
}

bool ObjCObjectType::is_obj_c_id(void) const {
  return impl->reader.getVal246();
}

bool ObjCObjectType::is_obj_c_qualified_class(void) const {
  return impl->reader.getVal247();
}

bool ObjCObjectType::is_obj_c_qualified_id(void) const {
  return impl->reader.getVal248();
}

bool ObjCObjectType::is_obj_c_unqualified_class(void) const {
  return impl->reader.getVal249();
}

bool ObjCObjectType::is_obj_c_unqualified_id(void) const {
  return impl->reader.getVal250();
}

bool ObjCObjectType::is_obj_c_unqualified_id_or_class(void) const {
  return impl->reader.getVal251();
}

bool ObjCObjectType::is_specialized(void) const {
  return impl->reader.getVal252();
}

bool ObjCObjectType::is_specialized_as_written(void) const {
  return impl->reader.getVal253();
}

bool ObjCObjectType::is_sugared(void) const {
  return impl->reader.getVal254();
}

bool ObjCObjectType::is_unspecialized(void) const {
  return impl->reader.getVal255();
}

bool ObjCObjectType::is_unspecialized_as_written(void) const {
  return impl->reader.getVal256();
}

Type ObjCObjectType::strip_obj_c_kind_of_type_and_qualifiers(void) const {
  RawEntityId eid = impl->reader.getVal277();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
