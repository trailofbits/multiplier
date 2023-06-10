// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DecayedType.h>

#include <multiplier/Entities/AdjustedType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DecayedType> DecayedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DecayedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DecayedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DecayedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DecayedType> DecayedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DecayedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDecayedTypeDerivedKinds[] = {
    DecayedType::static_kind(),
};

std::optional<DecayedType> DecayedType::from(const Type &parent) {
  switch (parent.kind()) {
    case DecayedType::static_kind():
      return reinterpret_cast<const DecayedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DecayedType> DecayedType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kDecayedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DecayedType> e = DecayedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DecayedType> DecayedType::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDecayedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DecayedType> e = DecayedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DecayedType> DecayedType::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDecayedTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DecayedType> e = DecayedType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DecayedType> DecayedType::from(const Reference &r) {
  return DecayedType::from(r.as_type());
}

std::optional<DecayedType> DecayedType::from(const TokenContext &t) {
  return DecayedType::from(t.as_type());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
