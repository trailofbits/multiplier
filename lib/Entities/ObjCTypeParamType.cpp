// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCTypeParamType.h>

#include <multiplier/Entities/ObjCTypeParamDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCTypeParamType> ObjCTypeParamType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCTypeParamType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCTypeParamType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCTypeParamType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCTypeParamType> ObjCTypeParamType::by_id(const Index &index, EntityId eid) {
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

std::optional<ObjCTypeParamType> ObjCTypeParamType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kObjCTypeParamTypeDerivedKinds[] = {
    ObjCTypeParamType::static_kind(),
};

}  // namespace

std::optional<ObjCTypeParamType> ObjCTypeParamType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ObjCTypeParamType::static_kind():
      return reinterpret_cast<const ObjCTypeParamType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCTypeParamType> ObjCTypeParamType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kObjCTypeParamTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ObjCTypeParamType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ObjCTypeParamType> ObjCTypeParamType::from(const Reference &r) {
  return ObjCTypeParamType::from(r.as_type());
}

std::optional<ObjCTypeParamType> ObjCTypeParamType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ObjCTypeParamType> ObjCTypeParamType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ObjCTypeParamType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ObjCTypeParamDecl ObjCTypeParamType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return ObjCTypeParamDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool ObjCTypeParamType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
