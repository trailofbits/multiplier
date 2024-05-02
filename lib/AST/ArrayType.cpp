// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ArrayType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/ConstantArrayType.h>
#include <multiplier/AST/DependentSizedArrayType.h>
#include <multiplier/AST/IncompleteArrayType.h>
#include <multiplier/AST/VariableArrayType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kArrayTypeDerivedKinds[] = {
    ConstantArrayType::static_kind(),
    DependentSizedArrayType::static_kind(),
    IncompleteArrayType::static_kind(),
    VariableArrayType::static_kind(),
};
}  // namespace

gap::generator<ArrayType> ArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ArrayType> ArrayType::by_id(const Index &index, EntityId eid) {
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

std::optional<ArrayType> ArrayType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ArrayType> ArrayType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ConstantArrayType::static_kind():
    case DependentSizedArrayType::static_kind():
    case IncompleteArrayType::static_kind():
    case VariableArrayType::static_kind():
      return reinterpret_cast<const ArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ArrayType> ArrayType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ArrayType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ArrayType> ArrayType::from(const Reference &r) {
  return ArrayType::from(r.as_type());
}

std::optional<ArrayType> ArrayType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ArrayType> ArrayType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ArrayType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

ArraySizeModifier ArrayType::size_modifier(void) const {
  return static_cast<ArraySizeModifier>(impl->reader.getVal28());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
