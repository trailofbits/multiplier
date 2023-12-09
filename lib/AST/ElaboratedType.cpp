// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ElaboratedType.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeWithKeyword.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kElaboratedTypeDerivedKinds[] = {
    ElaboratedType::static_kind(),
};
}  // namespace

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
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<ElaboratedType> ElaboratedType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<ElaboratedType> ElaboratedType::from_base(const Type &parent) {
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
      if (std::optional<ElaboratedType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<ElaboratedType> ElaboratedType::from(const Reference &r) {
  return ElaboratedType::from(r.as_type());
}

std::optional<ElaboratedType> ElaboratedType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<ElaboratedType> ElaboratedType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type ElaboratedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type ElaboratedType::named_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<TagDecl> ElaboratedType::owned_tag_declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal25();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TagDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool ElaboratedType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
