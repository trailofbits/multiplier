// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AttributedType.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kAttributedTypeDerivedKinds[] = {
    AttributedType::static_kind(),
};
}  // namespace

gap::generator<AttributedType> AttributedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AttributedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AttributedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AttributedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AttributedType> AttributedType::by_id(const Index &index, EntityId eid) {
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

std::optional<AttributedType> AttributedType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<AttributedType> AttributedType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case AttributedType::static_kind():
      return reinterpret_cast<const AttributedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AttributedType> AttributedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kAttributedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<AttributedType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<AttributedType> AttributedType::from(const Reference &r) {
  return AttributedType::from(r.as_type());
}

std::optional<AttributedType> AttributedType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<AttributedType> AttributedType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type AttributedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Attr> AttributedType::attribute(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal20();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->AttrFor(impl->ep, eid)) {
      return Attr(std::move(eptr));
    }
  }
  return std::nullopt;
}

AttrKind AttributedType::attribute_kind(void) const {
  return static_cast<AttrKind>(impl->reader.getVal68());
}

Type AttributedType::equivalent_type(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<NullabilityKind> AttributedType::immediate_nullability(void) const {
  if (!impl->reader.getVal21()) {
    return std::nullopt;
  } else {
    return static_cast<NullabilityKind>(impl->reader.getVal28());
  }
  return std::nullopt;
}

Type AttributedType::modified_type(void) const {
  RawEntityId eid = impl->reader.getVal27();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool AttributedType::has_attribute(void) const {
  return impl->reader.getVal22();
}

bool AttributedType::is_calling_conv(void) const {
  return impl->reader.getVal23();
}

bool AttributedType::is_ms_type_spec(void) const {
  return impl->reader.getVal29();
}

bool AttributedType::is_qualifier(void) const {
  return impl->reader.getVal30();
}

bool AttributedType::is_sugared(void) const {
  return impl->reader.getVal31();
}

bool AttributedType::is_web_assembly_funcref_spec(void) const {
  return impl->reader.getVal32();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
