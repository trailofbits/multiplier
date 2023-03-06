// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/IncompleteArrayType.h>

#include <multiplier/Entities/ArrayType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<IncompleteArrayType> IncompleteArrayType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = IncompleteArrayType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool IncompleteArrayType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : IncompleteArrayType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<IncompleteArrayType> IncompleteArrayType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return IncompleteArrayType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kIncompleteArrayTypeDerivedKinds[] = {
    IncompleteArrayType::static_kind(),
};

std::optional<IncompleteArrayType> IncompleteArrayType::from(const Type &parent) {
  switch (parent.kind()) {
    case IncompleteArrayType::static_kind():
      return reinterpret_cast<const IncompleteArrayType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<IncompleteArrayType> IncompleteArrayType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kIncompleteArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<IncompleteArrayType> e = IncompleteArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncompleteArrayType> IncompleteArrayType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kIncompleteArrayTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<IncompleteArrayType> e = IncompleteArrayType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<IncompleteArrayType> IncompleteArrayType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kIncompleteArrayTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<IncompleteArrayType> e = IncompleteArrayType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type IncompleteArrayType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool IncompleteArrayType::is_sugared(void) const {
  return impl->reader.getVal293();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
