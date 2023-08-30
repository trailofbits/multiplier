// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeOfType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeOfType> TypeOfType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeOfType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeOfType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeOfType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TypeOfType> TypeOfType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return TypeOfType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kTypeOfTypeDerivedKinds[] = {
    TypeOfType::static_kind(),
};

std::optional<TypeOfType> TypeOfType::from(const Type &parent) {
  switch (parent.kind()) {
    case TypeOfType::static_kind():
      return reinterpret_cast<const TypeOfType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeOfType> TypeOfType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTypeOfTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TypeOfType> e = TypeOfType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TypeOfType> TypeOfType::from(const Reference &r) {
  return TypeOfType::from(r.as_type());
}

std::optional<TypeOfType> TypeOfType::from(const TokenContext &t) {
  return TypeOfType::from(t.as_type());
}

Type TypeOfType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TypeOfKind TypeOfType::type_kind(void) const {
  return static_cast<TypeOfKind>(impl->reader.getVal237());
}

Type TypeOfType::unmodified_type(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool TypeOfType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
