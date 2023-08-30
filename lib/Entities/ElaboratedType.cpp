// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ElaboratedType.h>

#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeWithKeyword.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ElaboratedType> ElaboratedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ElaboratedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ElaboratedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ElaboratedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ElaboratedType> ElaboratedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ElaboratedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kElaboratedTypeDerivedKinds[] = {
    ElaboratedType::static_kind(),
};

std::optional<ElaboratedType> ElaboratedType::from(const Type &parent) {
  switch (parent.kind()) {
    case ElaboratedType::static_kind():
      return reinterpret_cast<const ElaboratedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ElaboratedType> ElaboratedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kElaboratedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ElaboratedType> e = ElaboratedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ElaboratedType> ElaboratedType::from(const Reference &r) {
  return ElaboratedType::from(r.as_type());
}

std::optional<ElaboratedType> ElaboratedType::from(const TokenContext &t) {
  return ElaboratedType::from(t.as_type());
}

Type ElaboratedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ElaboratedType::named_type(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<TagDecl> ElaboratedType::owned_tag_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal235();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TagDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool ElaboratedType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
