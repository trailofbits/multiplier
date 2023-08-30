// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BTFTagAttributedType.h>

#include <multiplier/Entities/BTFTypeTagAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BTFTagAttributedType> BTFTagAttributedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BTFTagAttributedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BTFTagAttributedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BTFTagAttributedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BTFTagAttributedType> BTFTagAttributedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return BTFTagAttributedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kBTFTagAttributedTypeDerivedKinds[] = {
    BTFTagAttributedType::static_kind(),
};

std::optional<BTFTagAttributedType> BTFTagAttributedType::from(const Type &parent) {
  switch (parent.kind()) {
    case BTFTagAttributedType::static_kind():
      return reinterpret_cast<const BTFTagAttributedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BTFTagAttributedType> BTFTagAttributedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kBTFTagAttributedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<BTFTagAttributedType> e = BTFTagAttributedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<BTFTagAttributedType> BTFTagAttributedType::from(const Reference &r) {
  return BTFTagAttributedType::from(r.as_type());
}

std::optional<BTFTagAttributedType> BTFTagAttributedType::from(const TokenContext &t) {
  return BTFTagAttributedType::from(t.as_type());
}

Type BTFTagAttributedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

BTFTypeTagAttr BTFTagAttributedType::attribute(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return BTFTypeTagAttr::from(Attr(impl->ep->AttrFor(impl->ep, eid))).value();
}

Type BTFTagAttributedType::wrapped_type(void) const {
  RawEntityId eid = impl->reader.getVal235();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool BTFTagAttributedType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
