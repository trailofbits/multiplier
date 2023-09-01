// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FunctionNoProtoType.h>

#include <multiplier/Entities/FunctionType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<FunctionNoProtoType> FunctionNoProtoType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = FunctionNoProtoType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool FunctionNoProtoType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : FunctionNoProtoType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<FunctionNoProtoType> FunctionNoProtoType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return FunctionNoProtoType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kFunctionNoProtoTypeDerivedKinds[] = {
    FunctionNoProtoType::static_kind(),
};

std::optional<FunctionNoProtoType> FunctionNoProtoType::from(const Type &parent) {
  switch (parent.kind()) {
    case FunctionNoProtoType::static_kind():
      return reinterpret_cast<const FunctionNoProtoType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<FunctionNoProtoType> FunctionNoProtoType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kFunctionNoProtoTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<FunctionNoProtoType> e = FunctionNoProtoType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<FunctionNoProtoType> FunctionNoProtoType::from(const Reference &r) {
  return FunctionNoProtoType::from(r.as_type());
}

std::optional<FunctionNoProtoType> FunctionNoProtoType::from(const TokenContext &t) {
  return FunctionNoProtoType::from(t.as_type());
}

Type FunctionNoProtoType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal239();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool FunctionNoProtoType::is_sugared(void) const {
  return impl->reader.getVal245();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
