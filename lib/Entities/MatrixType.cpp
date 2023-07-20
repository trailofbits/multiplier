// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MatrixType.h>

#include <multiplier/Entities/ConstantMatrixType.h>
#include <multiplier/Entities/DependentSizedMatrixType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MatrixType> MatrixType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MatrixType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MatrixType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MatrixType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<MatrixType> MatrixType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return MatrixType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kMatrixTypeDerivedKinds[] = {
    ConstantMatrixType::static_kind(),
    DependentSizedMatrixType::static_kind(),
};

std::optional<MatrixType> MatrixType::from(const Type &parent) {
  switch (parent.kind()) {
    case ConstantMatrixType::static_kind():
    case DependentSizedMatrixType::static_kind():
      return reinterpret_cast<const MatrixType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MatrixType> MatrixType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kMatrixTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<MatrixType> e = MatrixType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<MatrixType> MatrixType::from(const Reference &r) {
  return MatrixType::from(r.as_type());
}

std::optional<MatrixType> MatrixType::from(const TokenContext &t) {
  return MatrixType::from(t.as_type());
}

Type MatrixType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type MatrixType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool MatrixType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
