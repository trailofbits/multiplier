// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentSizedArrayType.h>

#include <multiplier/Entities/ArrayType.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Fragment.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return DependentSizedArrayType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentSizedArrayTypeDerivedKinds[] = {
    DependentSizedArrayType::static_kind(),
};

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const Type &parent) {
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
      if (std::optional<DependentSizedArrayType> e = DependentSizedArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const Reference &r) {
  return DependentSizedArrayType::from(r.as_type());
}

std::optional<DependentSizedArrayType> DependentSizedArrayType::from(const TokenContext &t) {
  return DependentSizedArrayType::from(t.as_type());
}

Type DependentSizedArrayType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TokenRange DependentSizedArrayType::brackets_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal25(), impl->reader.getVal26());
}

Token DependentSizedArrayType::l_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal59());
}

Token DependentSizedArrayType::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal60());
}

Expr DependentSizedArrayType::size_expression(void) const {
  RawEntityId eid = impl->reader.getVal62();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

bool DependentSizedArrayType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
