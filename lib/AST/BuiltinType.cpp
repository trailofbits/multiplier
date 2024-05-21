// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BuiltinType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kBuiltinTypeDerivedKinds[] = {
    BuiltinType::static_kind(),
};
}  // namespace

gap::generator<BuiltinType> BuiltinType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BuiltinType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BuiltinType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BuiltinType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BuiltinType> BuiltinType::by_id(const Index &index, EntityId eid) {
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

std::optional<BuiltinType> BuiltinType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<BuiltinType> BuiltinType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case BuiltinType::static_kind():
      return reinterpret_cast<const BuiltinType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BuiltinType> BuiltinType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kBuiltinTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<BuiltinType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<BuiltinType> BuiltinType::from(const Reference &r) {
  return BuiltinType::from(r.as_type());
}

std::optional<BuiltinType> BuiltinType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<BuiltinType> BuiltinType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

BuiltinTypeKind BuiltinType::builtin_kind(void) const {
  return static_cast<BuiltinTypeKind>(impl->reader.getVal68());
}

bool BuiltinType::is_floating_point(void) const {
  return impl->reader.getVal20();
}

bool BuiltinType::is_integer(void) const {
  return impl->reader.getVal21();
}

bool BuiltinType::is_sve_bool(void) const {
  return impl->reader.getVal22();
}

bool BuiltinType::is_sve_count(void) const {
  return impl->reader.getVal28();
}

bool BuiltinType::is_signed_integer(void) const {
  return impl->reader.getVal29();
}

bool BuiltinType::is_sugared(void) const {
  return impl->reader.getVal30();
}

bool BuiltinType::is_unsigned_integer(void) const {
  return impl->reader.getVal31();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
