// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DeducedTemplateSpecializationType.h>
#include <multiplier/AST/DeducedType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kDeducedTemplateSpecializationTypeDerivedKinds[] = {
    DeducedTemplateSpecializationType::static_kind(),
};
}  // namespace

gap::generator<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDeducedTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DeducedTemplateSpecializationType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeducedTemplateSpecializationType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeducedTemplateSpecializationType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeducedTemplateSpecializationType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::by_id(const Index &index, EntityId eid) {
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

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DeducedTemplateSpecializationType::static_kind():
      return reinterpret_cast<const DeducedTemplateSpecializationType &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::from(const Reference &r) {
  return DeducedTemplateSpecializationType::from(r.as_type());
}

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DeducedTemplateSpecializationType> DeducedTemplateSpecializationType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
