// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ObjCInterfaceType.h>

#include <multiplier/AST/ObjCInterfaceDecl.h>
#include <multiplier/AST/ObjCObjectType.h>
#include <multiplier/AST/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCInterfaceType> ObjCInterfaceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCInterfaceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCInterfaceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCInterfaceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCInterfaceType> ObjCInterfaceType::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCInterfaceType> ObjCInterfaceType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kObjCInterfaceTypeDerivedKinds[] = {
    ObjCInterfaceType::static_kind(),
};

}  // namespace

std::optional<ObjCInterfaceType> ObjCInterfaceType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ObjCInterfaceType::static_kind():
      return reinterpret_cast<const ObjCInterfaceType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCInterfaceType> ObjCInterfaceType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kObjCInterfaceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCInterfaceType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ObjCInterfaceType> ObjCInterfaceType::from(const Reference &r) {
  return ObjCInterfaceType::from(r.as_type());
}

std::optional<ObjCInterfaceType> ObjCInterfaceType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ObjCInterfaceType> ObjCInterfaceType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

ObjCInterfaceDecl ObjCInterfaceType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal60();
  return ObjCInterfaceDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
