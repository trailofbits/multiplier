// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VectorType.h>

#include <multiplier/Entities/ExtVectorType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VectorType> VectorType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VectorType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VectorType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VectorType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VectorType> VectorType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return VectorType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kVectorTypeDerivedKinds[] = {
    VectorType::static_kind(),
    ExtVectorType::static_kind(),
};

std::optional<VectorType> VectorType::from(const Type &parent) {
  switch (parent.kind()) {
    case VectorType::static_kind():
    case ExtVectorType::static_kind():
      return reinterpret_cast<const VectorType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VectorType> VectorType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<VectorType> e = VectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<VectorType> VectorType::from(const Reference &r) {
  return VectorType::from(r.as_type());
}

std::optional<VectorType> VectorType::from(const TokenContext &t) {
  return VectorType::from(t.as_type());
}

Type VectorType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type VectorType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

VectorTypeVectorKind VectorType::vector_kind(void) const {
  return static_cast<VectorTypeVectorKind>(impl->reader.getVal238());
}

bool VectorType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
