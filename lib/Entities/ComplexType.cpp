// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ComplexType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ComplexType> ComplexType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ComplexType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ComplexType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ComplexType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ComplexType> ComplexType::by_id(const Index &index, EntityId eid) {
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

std::optional<ComplexType> ComplexType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kComplexTypeDerivedKinds[] = {
    ComplexType::static_kind(),
};

}  // namespace

std::optional<ComplexType> ComplexType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ComplexType::static_kind():
      return reinterpret_cast<const ComplexType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ComplexType> ComplexType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kComplexTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ComplexType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ComplexType> ComplexType::from(const Reference &r) {
  return ComplexType::from(r.as_type());
}

std::optional<ComplexType> ComplexType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ComplexType> ComplexType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ComplexType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ComplexType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ComplexType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
