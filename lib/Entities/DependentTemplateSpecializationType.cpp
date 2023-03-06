// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DependentTemplateSpecializationType.h>

#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/TypeWithKeyword.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DependentTemplateSpecializationType> DependentTemplateSpecializationType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DependentTemplateSpecializationType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DependentTemplateSpecializationType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DependentTemplateSpecializationType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DependentTemplateSpecializationType> DependentTemplateSpecializationType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return DependentTemplateSpecializationType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kDependentTemplateSpecializationTypeDerivedKinds[] = {
    DependentTemplateSpecializationType::static_kind(),
};

std::optional<DependentTemplateSpecializationType> DependentTemplateSpecializationType::from(const Type &parent) {
  switch (parent.kind()) {
    case DependentTemplateSpecializationType::static_kind():
      return reinterpret_cast<const DependentTemplateSpecializationType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DependentTemplateSpecializationType> DependentTemplateSpecializationType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kDependentTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<DependentTemplateSpecializationType> e = DependentTemplateSpecializationType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentTemplateSpecializationType> DependentTemplateSpecializationType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kDependentTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<DependentTemplateSpecializationType> e = DependentTemplateSpecializationType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DependentTemplateSpecializationType> DependentTemplateSpecializationType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kDependentTemplateSpecializationTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<DependentTemplateSpecializationType> e = DependentTemplateSpecializationType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type DependentTemplateSpecializationType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool DependentTemplateSpecializationType::is_sugared(void) const {
  return impl->reader.getVal293();
}

std::optional<TemplateArgument> DependentTemplateSpecializationType::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal296();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProvider::Ptr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> DependentTemplateSpecializationType::template_arguments(void) const & {
  auto list = impl->reader.getVal296();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d296 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d296));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
