// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConstantMatrixType.h>

#include <multiplier/Entities/MatrixType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConstantMatrixType> ConstantMatrixType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConstantMatrixType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConstantMatrixType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConstantMatrixType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ConstantMatrixType> ConstantMatrixType::by_id(const Index &index, EntityId eid) {
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

std::optional<ConstantMatrixType> ConstantMatrixType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const TypeKind kConstantMatrixTypeDerivedKinds[] = {
    ConstantMatrixType::static_kind(),
};

}  // namespace

std::optional<ConstantMatrixType> ConstantMatrixType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case ConstantMatrixType::static_kind():
      return reinterpret_cast<const ConstantMatrixType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConstantMatrixType> ConstantMatrixType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kConstantMatrixTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ConstantMatrixType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ConstantMatrixType> ConstantMatrixType::from(const Reference &r) {
  return ConstantMatrixType::from(r.as_type());
}

std::optional<ConstantMatrixType> ConstantMatrixType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ConstantMatrixType> ConstantMatrixType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
