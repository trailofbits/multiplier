// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConstantArrayType.h>

#include <multiplier/Entities/ArrayType.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConstantArrayType> ConstantArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConstantArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConstantArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConstantArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ConstantArrayType> ConstantArrayType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ConstantArrayType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kConstantArrayTypeDerivedKinds[] = {
    ConstantArrayType::static_kind(),
};

std::optional<ConstantArrayType> ConstantArrayType::from(const Type &parent) {
  switch (parent.kind()) {
    case ConstantArrayType::static_kind():
      return reinterpret_cast<const ConstantArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConstantArrayType> ConstantArrayType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kConstantArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ConstantArrayType> e = ConstantArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ConstantArrayType> ConstantArrayType::from(const Reference &r) {
  return ConstantArrayType::from(r.as_type());
}

std::optional<ConstantArrayType> ConstantArrayType::from(const TokenContext &t) {
  return ConstantArrayType::from(t.as_type());
}

Type ConstantArrayType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Expr> ConstantArrayType::size_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal242();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool ConstantArrayType::is_sugared(void) const {
  return impl->reader.getVal237();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
