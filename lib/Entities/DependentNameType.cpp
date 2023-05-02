// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentNameType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeWithKeyword.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentNameType> DependentNameType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentNameType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentNameType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentNameType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentNameType> DependentNameType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DependentNameType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentNameTypeDerivedKinds[] = {
    DependentNameType::static_kind(),
};

std::optional<DependentNameType> DependentNameType::from(const Type &parent) {
  switch (parent.kind()) {
    case DependentNameType::static_kind():
      return reinterpret_cast<const DependentNameType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentNameType> DependentNameType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kDependentNameTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentNameType> e = DependentNameType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentNameType> DependentNameType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDependentNameTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DependentNameType> e = DependentNameType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentNameType> DependentNameType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDependentNameTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DependentNameType> e = DependentNameType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DependentNameType> DependentNameType::from(const Reference &r) {
  return DependentNameType::from(r.as_type());
}

std::optional<DependentNameType> DependentNameType::from(const TokenContext &t) {
  return DependentNameType::from(t.as_type());
}

Type DependentNameType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool DependentNameType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
