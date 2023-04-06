// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ReferenceType.h>

#include <multiplier/Entities/LValueReferenceType.h>
#include <multiplier/Entities/RValueReferenceType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ReferenceType> ReferenceType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ReferenceType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ReferenceType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ReferenceType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ReferenceType> ReferenceType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return ReferenceType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kReferenceTypeDerivedKinds[] = {
    LValueReferenceType::static_kind(),
    RValueReferenceType::static_kind(),
};

std::optional<ReferenceType> ReferenceType::from(const Type &parent) {
  switch (parent.kind()) {
    case LValueReferenceType::static_kind():
    case RValueReferenceType::static_kind():
      return reinterpret_cast<const ReferenceType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ReferenceType> ReferenceType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kReferenceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<ReferenceType> e = ReferenceType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ReferenceType> ReferenceType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kReferenceTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<ReferenceType> e = ReferenceType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ReferenceType> ReferenceType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kReferenceTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<ReferenceType> e = ReferenceType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ReferenceType> ReferenceType::from(const Reference &r) {
  return ReferenceType::from(r.as_type());
}

std::optional<ReferenceType> ReferenceType::from(const TokenContext &t) {
  return ReferenceType::from(t.as_type());
}

Type ReferenceType::pointee_type_as_written(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool ReferenceType::is_inner_reference(void) const {
  return impl->reader.getVal231();
}

bool ReferenceType::is_spelled_as_l_value(void) const {
  return impl->reader.getVal232();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
