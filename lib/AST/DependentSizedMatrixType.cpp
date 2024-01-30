// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/DependentSizedMatrixType.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/MatrixType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kDependentSizedMatrixTypeDerivedKinds[] = {
    DependentSizedMatrixType::static_kind(),
};
}  // namespace

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentSizedMatrixType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentSizedMatrixType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentSizedMatrixType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::by_id(const Index &index, EntityId eid) {
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

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case DependentSizedMatrixType::static_kind():
      return reinterpret_cast<const DependentSizedMatrixType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentSizedMatrixType> DependentSizedMatrixType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDependentSizedMatrixTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentSizedMatrixType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const Reference &r) {
  return DependentSizedMatrixType::from(r.as_type());
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<DependentSizedMatrixType> DependentSizedMatrixType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Token DependentSizedMatrixType::attribute_token(void) const {
  return impl->ep->TokenFor(impl->ep, impl->reader.getVal26());
}

Expr DependentSizedMatrixType::column_expression(void) const {
  RawEntityId eid = impl->reader.getVal27();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

Expr DependentSizedMatrixType::row_expression(void) const {
  RawEntityId eid = impl->reader.getVal60();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
