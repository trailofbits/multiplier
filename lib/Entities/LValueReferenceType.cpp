// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/LValueReferenceType.h>

#include <multiplier/Entities/ReferenceType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LValueReferenceType> LValueReferenceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LValueReferenceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LValueReferenceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LValueReferenceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<LValueReferenceType> LValueReferenceType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return LValueReferenceType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kLValueReferenceTypeDerivedKinds[] = {
    LValueReferenceType::static_kind(),
};

std::optional<LValueReferenceType> LValueReferenceType::from(const Type &parent) {
  switch (parent.kind()) {
    case LValueReferenceType::static_kind():
      return reinterpret_cast<const LValueReferenceType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LValueReferenceType> LValueReferenceType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kLValueReferenceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<LValueReferenceType> e = LValueReferenceType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<LValueReferenceType> LValueReferenceType::from(const Reference &r) {
  return LValueReferenceType::from(r.as_type());
}

std::optional<LValueReferenceType> LValueReferenceType::from(const TokenContext &t) {
  return LValueReferenceType::from(t.as_type());
}

Type LValueReferenceType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal237();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool LValueReferenceType::is_sugared(void) const {
  return impl->reader.getVal240();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
