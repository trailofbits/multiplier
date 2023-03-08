// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeducedType.h>

#include <multiplier/Entities/AutoType.h>
#include <multiplier/Entities/DeducedTemplateSpecializationType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DeducedType> DeducedType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeducedType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeducedType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeducedType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DeducedType> DeducedType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DeducedType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDeducedTypeDerivedKinds[] = {
    AutoType::static_kind(),
    DeducedTemplateSpecializationType::static_kind(),
};

std::optional<DeducedType> DeducedType::from(const Type &parent) {
  switch (parent.kind()) {
    case AutoType::static_kind():
    case DeducedTemplateSpecializationType::static_kind():
      return reinterpret_cast<const DeducedType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DeducedType> DeducedType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kDeducedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DeducedType> e = DeducedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeducedType> DeducedType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDeducedTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DeducedType> e = DeducedType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeducedType> DeducedType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDeducedTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DeducedType> e = DeducedType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DeducedType> DeducedType::from(const Reference &r) {
  return DeducedType::from(r.as_type());
}

std::optional<DeducedType> DeducedType::from(const TokenContext &t) {
  return DeducedType::from(t.as_type());
}

Type DeducedType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Type> DeducedType::resolved_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal229();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool DeducedType::is_deduced(void) const {
  return impl->reader.getVal230();
}

bool DeducedType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
