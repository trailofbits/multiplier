// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AdjustedType.h>

#include <multiplier/Entities/DecayedType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AdjustedType> AdjustedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AdjustedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AdjustedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AdjustedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AdjustedType> AdjustedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return AdjustedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kAdjustedTypeDerivedKinds[] = {
    AdjustedType::static_kind(),
    DecayedType::static_kind(),
};

std::optional<AdjustedType> AdjustedType::from(const Type &parent) {
  switch (parent.kind()) {
    case AdjustedType::static_kind():
    case DecayedType::static_kind():
      return reinterpret_cast<const AdjustedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AdjustedType> AdjustedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kAdjustedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<AdjustedType> e = AdjustedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<AdjustedType> AdjustedType::from(const Reference &r) {
  return AdjustedType::from(r.as_type());
}

std::optional<AdjustedType> AdjustedType::from(const TokenContext &t) {
  return AdjustedType::from(t.as_type());
}

Type AdjustedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type AdjustedType::resolved_type(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type AdjustedType::original_type(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool AdjustedType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
