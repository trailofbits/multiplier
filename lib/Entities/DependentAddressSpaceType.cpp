// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentAddressSpaceType.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentAddressSpaceType> DependentAddressSpaceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentAddressSpaceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentAddressSpaceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentAddressSpaceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::by_id(const Index &index, EntityId eid) {
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

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kDependentAddressSpaceTypeDerivedKinds[] = {
    DependentAddressSpaceType::static_kind(),
};

}  // namespace

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DependentAddressSpaceType::static_kind():
      return reinterpret_cast<const DependentAddressSpaceType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentAddressSpaceType> DependentAddressSpaceType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDependentAddressSpaceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentAddressSpaceType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::from(const Reference &r) {
  return DependentAddressSpaceType::from(r.as_type());
}

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DependentAddressSpaceType> DependentAddressSpaceType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type DependentAddressSpaceType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr DependentAddressSpaceType::address_space_expression(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Token DependentAddressSpaceType::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal25());
}

Type DependentAddressSpaceType::pointee_type(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool DependentAddressSpaceType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
