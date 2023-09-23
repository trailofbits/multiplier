// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentVectorType.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentVectorType> DependentVectorType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentVectorType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentVectorType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentVectorType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentVectorType> DependentVectorType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DependentVectorType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentVectorTypeDerivedKinds[] = {
    DependentVectorType::static_kind(),
};

std::optional<DependentVectorType> DependentVectorType::from(const Type &parent) {
  switch (parent.kind()) {
    case DependentVectorType::static_kind():
      return reinterpret_cast<const DependentVectorType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentVectorType> DependentVectorType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDependentVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentVectorType> e = DependentVectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentVectorType> DependentVectorType::from(const Reference &r) {
  return DependentVectorType::from(r.as_type());
}

std::optional<DependentVectorType> DependentVectorType::from(const TokenContext &t) {
  return DependentVectorType::from(t.as_type());
}

Type DependentVectorType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Token DependentVectorType::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal237());
}

Type DependentVectorType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal243();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr DependentVectorType::size_expression(void) const {
  RawEntityId eid = impl->reader.getVal244();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

VectorTypeVectorKind DependentVectorType::vector_kind(void) const {
  return static_cast<VectorTypeVectorKind>(impl->reader.getVal245());
}

bool DependentVectorType::is_sugared(void) const {
  return impl->reader.getVal238();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
