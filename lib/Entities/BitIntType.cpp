// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BitIntType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BitIntType> BitIntType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BitIntType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BitIntType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BitIntType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BitIntType> BitIntType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return BitIntType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kBitIntTypeDerivedKinds[] = {
    BitIntType::static_kind(),
};

std::optional<BitIntType> BitIntType::from(const Type &parent) {
  switch (parent.kind()) {
    case BitIntType::static_kind():
      return reinterpret_cast<const BitIntType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BitIntType> BitIntType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kBitIntTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<BitIntType> e = BitIntType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BitIntType> BitIntType::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kBitIntTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<BitIntType> e = BitIntType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BitIntType> BitIntType::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kBitIntTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<BitIntType> e = BitIntType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BitIntType> BitIntType::from(const Reference &r) {
  return BitIntType::from(r.as_type());
}

std::optional<BitIntType> BitIntType::from(const TokenContext &t) {
  return BitIntType::from(t.as_type());
}

Type BitIntType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool BitIntType::is_signed(void) const {
  return impl->reader.getVal231();
}

bool BitIntType::is_sugared(void) const {
  return impl->reader.getVal232();
}

bool BitIntType::is_unsigned(void) const {
  return impl->reader.getVal233();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
