// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeOfExprType.h>
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
static const TypeKind kTypeOfExprTypeDerivedKinds[] = {
    TypeOfExprType::static_kind(),
};
}  // namespace

gap::generator<TypeOfExprType> TypeOfExprType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeOfExprType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeOfExprType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeOfExprType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TypeOfExprType> TypeOfExprType::by_id(const Index &index, EntityId eid) {
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

std::optional<TypeOfExprType> TypeOfExprType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TypeOfExprType> TypeOfExprType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case TypeOfExprType::static_kind():
      return reinterpret_cast<const TypeOfExprType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeOfExprType> TypeOfExprType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTypeOfExprTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TypeOfExprType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TypeOfExprType> TypeOfExprType::from(const Reference &r) {
  return TypeOfExprType::from(r.as_type());
}

std::optional<TypeOfExprType> TypeOfExprType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<TypeOfExprType> TypeOfExprType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TypeOfKind TypeOfExprType::type_kind(void) const {
  return static_cast<TypeOfKind>(impl->reader.getVal27());
}

Expr TypeOfExprType::underlying_expression(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool TypeOfExprType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
