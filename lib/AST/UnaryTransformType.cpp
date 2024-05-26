// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UnaryTransformType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kUnaryTransformTypeDerivedKinds[] = {
    UnaryTransformType::static_kind(),
};
}  // namespace

gap::generator<UnaryTransformType> UnaryTransformType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kUnaryTransformTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<UnaryTransformType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryTransformType> UnaryTransformType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnaryTransformType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnaryTransformType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnaryTransformType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UnaryTransformType> UnaryTransformType::by_id(const Index &index, EntityId eid) {
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

std::optional<UnaryTransformType> UnaryTransformType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<UnaryTransformType> UnaryTransformType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case UnaryTransformType::static_kind():
      return reinterpret_cast<const UnaryTransformType &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<UnaryTransformType> UnaryTransformType::from(const Reference &r) {
  return UnaryTransformType::from(r.as_type());
}

std::optional<UnaryTransformType> UnaryTransformType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<UnaryTransformType> UnaryTransformType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::optional<Type> UnaryTransformType::base_type(void) const {
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

UnaryTransformTypeUTTKind UnaryTransformType::utt_kind(void) const {
  return static_cast<UnaryTransformTypeUTTKind>(impl->reader.getVal27());
}

std::optional<Type> UnaryTransformType::underlying_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal25();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool UnaryTransformType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
