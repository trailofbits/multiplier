// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ReferenceType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/LValueReferenceType.h>
#include <multiplier/AST/RValueReferenceType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kReferenceTypeDerivedKinds[] = {
    LValueReferenceType::static_kind(),
    RValueReferenceType::static_kind(),
};
}  // namespace

gap::generator<ReferenceType> ReferenceType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kReferenceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ReferenceType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ReferenceType> ReferenceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ReferenceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ReferenceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ReferenceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ReferenceType> ReferenceType::by_id(const Index &index, EntityId eid) {
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

std::optional<ReferenceType> ReferenceType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ReferenceType> ReferenceType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case LValueReferenceType::static_kind():
    case RValueReferenceType::static_kind():
      return reinterpret_cast<const ReferenceType &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<ReferenceType> ReferenceType::from(const Reference &r) {
  return ReferenceType::from(r.as_type());
}

std::optional<ReferenceType> ReferenceType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ReferenceType> ReferenceType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ReferenceType::pointee_type(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ReferenceType::pointee_type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal27();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ReferenceType::is_inner_reference(void) const {
  return impl->reader.getVal23();
}

bool ReferenceType::is_spelled_as_l_value(void) const {
  return impl->reader.getVal24();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
