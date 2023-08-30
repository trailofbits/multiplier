// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/RValueReferenceType.h>

#include <multiplier/Entities/ReferenceType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<RValueReferenceType> RValueReferenceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RValueReferenceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RValueReferenceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RValueReferenceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<RValueReferenceType> RValueReferenceType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return RValueReferenceType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kRValueReferenceTypeDerivedKinds[] = {
    RValueReferenceType::static_kind(),
};

std::optional<RValueReferenceType> RValueReferenceType::from(const Type &parent) {
  switch (parent.kind()) {
    case RValueReferenceType::static_kind():
      return reinterpret_cast<const RValueReferenceType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RValueReferenceType> RValueReferenceType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kRValueReferenceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<RValueReferenceType> e = RValueReferenceType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<RValueReferenceType> RValueReferenceType::from(const Reference &r) {
  return RValueReferenceType::from(r.as_type());
}

std::optional<RValueReferenceType> RValueReferenceType::from(const TokenContext &t) {
  return RValueReferenceType::from(t.as_type());
}

Type RValueReferenceType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool RValueReferenceType::is_sugared(void) const {
  return impl->reader.getVal232();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
