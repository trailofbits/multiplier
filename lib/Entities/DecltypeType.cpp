// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DecltypeType.h>

#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DecltypeType> DecltypeType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DecltypeType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DecltypeType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DecltypeType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DecltypeType> DecltypeType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DecltypeType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDecltypeTypeDerivedKinds[] = {
    DecltypeType::static_kind(),
};

std::optional<DecltypeType> DecltypeType::from(const Type &parent) {
  switch (parent.kind()) {
    case DecltypeType::static_kind():
      return reinterpret_cast<const DecltypeType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DecltypeType> DecltypeType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDecltypeTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DecltypeType> e = DecltypeType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<DecltypeType> DecltypeType::from(const Reference &r) {
  return DecltypeType::from(r.as_type());
}

std::optional<DecltypeType> DecltypeType::from(const TokenContext &t) {
  return DecltypeType::from(t.as_type());
}

Type DecltypeType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Expr DecltypeType::underlying_expression(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

Type DecltypeType::underlying_type(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool DecltypeType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
