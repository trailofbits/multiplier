// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/EnumType.h>

#include <multiplier/Entities/TagType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<EnumType> EnumType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = EnumType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool EnumType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : EnumType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<EnumType> EnumType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return EnumType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kEnumTypeDerivedKinds[] = {
    EnumType::static_kind(),
};

std::optional<EnumType> EnumType::from(const Type &parent) {
  switch (parent.kind()) {
    case EnumType::static_kind():
      return reinterpret_cast<const EnumType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<EnumType> EnumType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kEnumTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<EnumType> e = EnumType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<EnumType> EnumType::from(const Reference &r) {
  return EnumType::from(r.as_type());
}

std::optional<EnumType> EnumType::from(const TokenContext &t) {
  return EnumType::from(t.as_type());
}

Type EnumType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool EnumType::is_sugared(void) const {
  return impl->reader.getVal232();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
