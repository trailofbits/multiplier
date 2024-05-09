// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeducedType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/AutoType.h>
#include <multiplier/AST/DeducedTemplateSpecializationType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kDeducedTypeDerivedKinds[] = {
    AutoType::static_kind(),
    DeducedTemplateSpecializationType::static_kind(),
};
}  // namespace

gap::generator<DeducedType> DeducedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeducedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeducedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeducedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DeducedType> DeducedType::by_id(const Index &index, EntityId eid) {
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

std::optional<DeducedType> DeducedType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DeducedType> DeducedType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case AutoType::static_kind():
    case DeducedTemplateSpecializationType::static_kind():
      return reinterpret_cast<const DeducedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DeducedType> DeducedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDeducedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DeducedType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DeducedType> DeducedType::from(const Reference &r) {
  return DeducedType::from(r.as_type());
}

std::optional<DeducedType> DeducedType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DeducedType> DeducedType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Type> DeducedType::resolved_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal19();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool DeducedType::is_deduced(void) const {
  return impl->reader.getVal20();
}

bool DeducedType::is_sugared(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
