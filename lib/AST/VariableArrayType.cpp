// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VariableArrayType.h>
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
static const TypeKind kVariableArrayTypeDerivedKinds[] = {
    VariableArrayType::static_kind(),
};
}  // namespace

gap::generator<VariableArrayType> VariableArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VariableArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VariableArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VariableArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VariableArrayType> VariableArrayType::by_id(const Index &index, EntityId eid) {
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

std::optional<VariableArrayType> VariableArrayType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<VariableArrayType> VariableArrayType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case VariableArrayType::static_kind():
      return reinterpret_cast<const VariableArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VariableArrayType> VariableArrayType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kVariableArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<VariableArrayType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<VariableArrayType> VariableArrayType::from(const Reference &r) {
  return VariableArrayType::from(r.as_type());
}

std::optional<VariableArrayType> VariableArrayType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<VariableArrayType> VariableArrayType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TokenRange VariableArrayType::brackets_range(void) const {
  return impl->ep->TokenRangeFor(impl->ep, impl->reader.getVal25(), impl->reader.getVal26());
}

Token VariableArrayType::l_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal60());
}

Token VariableArrayType::r_bracket_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal61());
}

Expr VariableArrayType::size_expression(void) const {
  RawEntityId eid = impl->reader.getVal63();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

bool VariableArrayType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
