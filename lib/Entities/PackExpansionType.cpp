// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PackExpansionType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<PackExpansionType> PackExpansionType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PackExpansionType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PackExpansionType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PackExpansionType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<PackExpansionType> PackExpansionType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return PackExpansionType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kPackExpansionTypeDerivedKinds[] = {
    PackExpansionType::static_kind(),
};

std::optional<PackExpansionType> PackExpansionType::from(const Type &parent) {
  switch (parent.kind()) {
    case PackExpansionType::static_kind():
      return reinterpret_cast<const PackExpansionType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PackExpansionType> PackExpansionType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kPackExpansionTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<PackExpansionType> e = PackExpansionType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<PackExpansionType> PackExpansionType::from(const Reference &r) {
  return PackExpansionType::from(r.as_type());
}

std::optional<PackExpansionType> PackExpansionType::from(const TokenContext &t) {
  return PackExpansionType::from(t.as_type());
}

Type PackExpansionType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal21();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type PackExpansionType::pattern(void) const {
  RawEntityId eid = impl->reader.getVal22();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool PackExpansionType::is_sugared(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
