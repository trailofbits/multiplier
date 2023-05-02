// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AttributedType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AttributedType> AttributedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AttributedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AttributedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AttributedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AttributedType> AttributedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return AttributedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kAttributedTypeDerivedKinds[] = {
    AttributedType::static_kind(),
};

std::optional<AttributedType> AttributedType::from(const Type &parent) {
  switch (parent.kind()) {
    case AttributedType::static_kind():
      return reinterpret_cast<const AttributedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AttributedType> AttributedType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kAttributedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<AttributedType> e = AttributedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AttributedType> AttributedType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kAttributedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<AttributedType> e = AttributedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AttributedType> AttributedType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kAttributedTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<AttributedType> e = AttributedType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AttributedType> AttributedType::from(const Reference &r) {
  return AttributedType::from(r.as_type());
}

std::optional<AttributedType> AttributedType::from(const TokenContext &t) {
  return AttributedType::from(t.as_type());
}

Type AttributedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

AttrKind AttributedType::attribute_kind(void) const {
  return static_cast<AttrKind>(impl->reader.getVal275());
}

Type AttributedType::equivalent_type(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<NullabilityKind> AttributedType::immediate_nullability(void) const {
  if (!impl->reader.getVal231()) {
    return std::nullopt;
  } else {
    return static_cast<NullabilityKind>(impl->reader.getVal238());
  }
  return std::nullopt;
}

Type AttributedType::modified_type(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool AttributedType::is_calling_conv(void) const {
  return impl->reader.getVal232();
}

bool AttributedType::is_ms_type_spec(void) const {
  return impl->reader.getVal233();
}

bool AttributedType::is_qualifier(void) const {
  return impl->reader.getVal239();
}

bool AttributedType::is_sugared(void) const {
  return impl->reader.getVal240();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
