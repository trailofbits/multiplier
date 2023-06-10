// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnaryTransformType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnaryTransformType> UnaryTransformType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnaryTransformType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnaryTransformType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnaryTransformType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UnaryTransformType> UnaryTransformType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return UnaryTransformType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kUnaryTransformTypeDerivedKinds[] = {
    UnaryTransformType::static_kind(),
};

std::optional<UnaryTransformType> UnaryTransformType::from(const Type &parent) {
  switch (parent.kind()) {
    case UnaryTransformType::static_kind():
      return reinterpret_cast<const UnaryTransformType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnaryTransformType> UnaryTransformType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kUnaryTransformTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<UnaryTransformType> e = UnaryTransformType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryTransformType> UnaryTransformType::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kUnaryTransformTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<UnaryTransformType> e = UnaryTransformType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnaryTransformType> UnaryTransformType::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kUnaryTransformTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<UnaryTransformType> e = UnaryTransformType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnaryTransformType> UnaryTransformType::from(const Reference &r) {
  return UnaryTransformType::from(r.as_type());
}

std::optional<UnaryTransformType> UnaryTransformType::from(const TokenContext &t) {
  return UnaryTransformType::from(t.as_type());
}

Type UnaryTransformType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type UnaryTransformType::base_type(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

UnaryTransformTypeUTTKind UnaryTransformType::utt_kind(void) const {
  return static_cast<UnaryTransformTypeUTTKind>(impl->reader.getVal238());
}

Type UnaryTransformType::underlying_type(void) const {
  RawEntityId eid = impl->reader.getVal236();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool UnaryTransformType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
