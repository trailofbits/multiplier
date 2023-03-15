// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SubstTemplateTypeParmType.h>

#include <multiplier/Entities/TemplateTypeParmType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SubstTemplateTypeParmType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SubstTemplateTypeParmType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SubstTemplateTypeParmType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return SubstTemplateTypeParmType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kSubstTemplateTypeParmTypeDerivedKinds[] = {
    SubstTemplateTypeParmType::static_kind(),
};

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const Type &parent) {
  switch (parent.kind()) {
    case SubstTemplateTypeParmType::static_kind():
      return reinterpret_cast<const SubstTemplateTypeParmType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kSubstTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<SubstTemplateTypeParmType> e = SubstTemplateTypeParmType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kSubstTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<SubstTemplateTypeParmType> e = SubstTemplateTypeParmType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SubstTemplateTypeParmType> SubstTemplateTypeParmType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kSubstTemplateTypeParmTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<SubstTemplateTypeParmType> e = SubstTemplateTypeParmType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const Reference &r) {
  return SubstTemplateTypeParmType::from(r.as_type());
}

std::optional<SubstTemplateTypeParmType> SubstTemplateTypeParmType::from(const TokenContext &t) {
  return SubstTemplateTypeParmType::from(t.as_type());
}

Type SubstTemplateTypeParmType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TemplateTypeParmType SubstTemplateTypeParmType::replaced_parameter(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return TemplateTypeParmType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

Type SubstTemplateTypeParmType::replacement_type(void) const {
  RawEntityId eid = impl->reader.getVal234();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool SubstTemplateTypeParmType::is_sugared(void) const {
  return impl->reader.getVal230();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
