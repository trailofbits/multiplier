// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PointerType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kPointerTypeDerivedKinds[] = {
    PointerType::static_kind(),
};
}  // namespace

gap::generator<PointerType> PointerType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PointerType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PointerType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PointerType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<PointerType> PointerType::by_id(const Index &index, EntityId eid) {
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

std::optional<PointerType> PointerType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<PointerType> PointerType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case PointerType::static_kind():
      return reinterpret_cast<const PointerType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PointerType> PointerType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<PointerType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<PointerType> PointerType::from(const Reference &r) {
  return PointerType::from(r.as_type());
}

std::optional<PointerType> PointerType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<PointerType> PointerType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type PointerType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type PointerType::pointee_type(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool PointerType::is_sugared(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
