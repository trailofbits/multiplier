// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DependentSizedArrayType.h>
#include <multiplier/AST/ArrayType.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kDependentSizedArrayTypeDerivedKinds[] = {
    DependentSizedArrayType::static_kind(),
};
}  // namespace

gap::generator<DependentSizedArrayType> DependentSizedArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentSizedArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentSizedArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentSizedArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::by_id(const Index &index, EntityId eid) {
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

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DependentSizedArrayType::static_kind():
      return reinterpret_cast<const DependentSizedArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentSizedArrayType> DependentSizedArrayType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDependentSizedArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentSizedArrayType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const Reference &r) {
  return DependentSizedArrayType::from(r.as_type());
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type DependentSizedArrayType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TokenRange DependentSizedArrayType::brackets_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal26(), impl->reader.getVal27());
}

Token DependentSizedArrayType::l_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal60());
}

Token DependentSizedArrayType::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal61());
}

std::optional<Expr> DependentSizedArrayType::size_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal63();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool DependentSizedArrayType::is_sugared(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
