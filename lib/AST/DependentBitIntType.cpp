// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DependentBitIntType.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kDependentBitIntTypeDerivedKinds[] = {
    DependentBitIntType::static_kind(),
};
}  // namespace

gap::generator<DependentBitIntType> DependentBitIntType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentBitIntType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentBitIntType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentBitIntType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentBitIntType> DependentBitIntType::by_id(const Index &index, EntityId eid) {
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

std::optional<DependentBitIntType> DependentBitIntType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DependentBitIntType> DependentBitIntType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DependentBitIntType::static_kind():
      return reinterpret_cast<const DependentBitIntType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentBitIntType> DependentBitIntType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDependentBitIntTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentBitIntType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentBitIntType> DependentBitIntType::from(const Reference &r) {
  return DependentBitIntType::from(r.as_type());
}

std::optional<DependentBitIntType> DependentBitIntType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DependentBitIntType> DependentBitIntType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type DependentBitIntType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr DependentBitIntType::num_bits_expression(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool DependentBitIntType::is_signed(void) const {
  return impl->reader.getVal21();
}

bool DependentBitIntType::is_sugared(void) const {
  return impl->reader.getVal22();
}

bool DependentBitIntType::is_unsigned(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
