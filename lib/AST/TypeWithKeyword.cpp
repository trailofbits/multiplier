// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeWithKeyword.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/DependentNameType.h>
#include <multiplier/AST/DependentTemplateSpecializationType.h>
#include <multiplier/AST/ElaboratedType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeWithKeyword> TypeWithKeyword::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeWithKeyword::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeWithKeyword::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeWithKeyword::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TypeWithKeyword> TypeWithKeyword::by_id(const Index &index, EntityId eid) {
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

std::optional<TypeWithKeyword> TypeWithKeyword::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kTypeWithKeywordDerivedKinds[] = {
    DependentNameType::static_kind(),
    DependentTemplateSpecializationType::static_kind(),
    ElaboratedType::static_kind(),
};

}  // namespace

std::optional<TypeWithKeyword> TypeWithKeyword::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DependentNameType::static_kind():
    case DependentTemplateSpecializationType::static_kind():
    case ElaboratedType::static_kind():
      return reinterpret_cast<const TypeWithKeyword &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeWithKeyword> TypeWithKeyword::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTypeWithKeywordDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TypeWithKeyword> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TypeWithKeyword> TypeWithKeyword::from(const Reference &r) {
  return TypeWithKeyword::from(r.as_type());
}

std::optional<TypeWithKeyword> TypeWithKeyword::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<TypeWithKeyword> TypeWithKeyword::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

ElaboratedTypeKeyword TypeWithKeyword::keyword(void) const {
  return static_cast<ElaboratedTypeKeyword>(impl->reader.getVal27());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
