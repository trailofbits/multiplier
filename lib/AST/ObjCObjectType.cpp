// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCObjectType.h>
#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ObjCInterfaceType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kObjCObjectTypeDerivedKinds[] = {
    ObjCObjectType::static_kind(),
    ObjCInterfaceType::static_kind(),
};
}  // namespace

gap::generator<ObjCObjectType> ObjCObjectType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kObjCObjectTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCObjectType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ObjCObjectType> ObjCObjectType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ObjCObjectType> ObjCObjectType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ObjCObjectType::static_kind():
    case ObjCInterfaceType::static_kind():
      return reinterpret_cast<const ObjCObjectType &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ObjCObjectType> ObjCObjectType::from(const Reference &r) {
  return ObjCObjectType::from(r.as_type());
}

std::optional<ObjCObjectType> ObjCObjectType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ObjCObjectType> ObjCObjectType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ObjCObjectType::base_type(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ObjCInterfaceDecl ObjCObjectType::interface(void) const {
  RawEntityId eid = impl->reader.getVal27();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

std::optional<Type> ObjCObjectType::super_class_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal28();
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
  return impl->reader.getVal26().size();
}

std::optional<Type> ObjCObjectType::nth_type_argument(unsigned n) const {
  auto list = impl->reader.getVal26();
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
  auto list = impl->reader.getVal26();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d26 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d26));
    }
  }
  co_return;
}

gap::generator<Type> ObjCObjectType::type_arguments_as_written(void) const & {
  auto list = impl->reader.getVal61();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d61 = ep->TypeFor(ep, v)) {
      co_yield Type(std::move(d61));
    }
  }
  co_return;
}

bool ObjCObjectType::is_kind_of_type(void) const {
  return impl->reader.getVal23();
}

bool ObjCObjectType::is_kind_of_type_as_written(void) const {
  return impl->reader.getVal24();
}

bool ObjCObjectType::is_obj_c_class(void) const {
  return impl->reader.getVal25();
}

bool ObjCObjectType::is_obj_c_id(void) const {
  return impl->reader.getVal30();
}

bool ObjCObjectType::is_obj_c_qualified_class(void) const {
  return impl->reader.getVal31();
}

bool ObjCObjectType::is_obj_c_qualified_id(void) const {
  return impl->reader.getVal32();
}

bool ObjCObjectType::is_obj_c_unqualified_class(void) const {
  return impl->reader.getVal33();
}

bool ObjCObjectType::is_obj_c_unqualified_id(void) const {
  return impl->reader.getVal34();
}

bool ObjCObjectType::is_obj_c_unqualified_id_or_class(void) const {
  return impl->reader.getVal35();
}

bool ObjCObjectType::is_specialized(void) const {
  return impl->reader.getVal36();
}

bool ObjCObjectType::is_specialized_as_written(void) const {
  return impl->reader.getVal37();
}

bool ObjCObjectType::is_sugared(void) const {
  return impl->reader.getVal38();
}

bool ObjCObjectType::is_unspecialized(void) const {
  return impl->reader.getVal39();
}

bool ObjCObjectType::is_unspecialized_as_written(void) const {
  return impl->reader.getVal40();
}

Type ObjCObjectType::strip_obj_c_kind_of_type_and_qualifiers(void) const {
  RawEntityId eid = impl->reader.getVal62();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
