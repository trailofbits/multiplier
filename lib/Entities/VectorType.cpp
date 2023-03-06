// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VectorType.h>

#include <multiplier/Entities/ExtVectorType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VectorType> VectorType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VectorType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VectorType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VectorType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VectorType> VectorType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return VectorType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kVectorTypeDerivedKinds[] = {
    VectorType::static_kind(),
    ExtVectorType::static_kind(),
};

std::optional<VectorType> VectorType::from(const Type &parent) {
  switch (parent.kind()) {
    case VectorType::static_kind():
    case ExtVectorType::static_kind():
      return reinterpret_cast<const VectorType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VectorType> VectorType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<VectorType> e = VectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VectorType> VectorType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kVectorTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<VectorType> e = VectorType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VectorType> VectorType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kVectorTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<VectorType> e = VectorType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type VectorType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type VectorType::element_type(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

VectorTypeVectorKind VectorType::vector_kind(void) const {
  return static_cast<VectorTypeVectorKind>(impl->reader.getVal316());
}

bool VectorType::is_sugared(void) const {
  return impl->reader.getVal293();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
