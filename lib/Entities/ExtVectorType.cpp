// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExtVectorType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/VectorType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ExtVectorType> ExtVectorType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExtVectorType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExtVectorType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExtVectorType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ExtVectorType> ExtVectorType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ExtVectorType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kExtVectorTypeDerivedKinds[] = {
    ExtVectorType::static_kind(),
};

std::optional<ExtVectorType> ExtVectorType::from(const Type &parent) {
  switch (parent.kind()) {
    case ExtVectorType::static_kind():
      return reinterpret_cast<const ExtVectorType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExtVectorType> ExtVectorType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kExtVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ExtVectorType> e = ExtVectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ExtVectorType> ExtVectorType::from(const Reference &r) {
  return ExtVectorType::from(r.as_type());
}

std::optional<ExtVectorType> ExtVectorType::from(const TokenContext &t) {
  return ExtVectorType::from(t.as_type());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
