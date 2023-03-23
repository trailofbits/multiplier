// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateSpecializationType.h>

#include <multiplier/Entities/TemplateArgument.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TemplateSpecializationType> TemplateSpecializationType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateSpecializationType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateSpecializationType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateSpecializationType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateSpecializationType> TemplateSpecializationType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return TemplateSpecializationType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kTemplateSpecializationTypeDerivedKinds[] = {
    TemplateSpecializationType::static_kind(),
};

std::optional<TemplateSpecializationType> TemplateSpecializationType::from(const Type &parent) {
  switch (parent.kind()) {
    case TemplateSpecializationType::static_kind():
      return reinterpret_cast<const TemplateSpecializationType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateSpecializationType> TemplateSpecializationType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TemplateSpecializationType> e = TemplateSpecializationType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateSpecializationType> TemplateSpecializationType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<TemplateSpecializationType> e = TemplateSpecializationType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateSpecializationType> TemplateSpecializationType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kTemplateSpecializationTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<TemplateSpecializationType> e = TemplateSpecializationType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TemplateSpecializationType> TemplateSpecializationType::from(const Reference &r) {
  return TemplateSpecializationType::from(r.as_type());
}

std::optional<TemplateSpecializationType> TemplateSpecializationType::from(const TokenContext &t) {
  return TemplateSpecializationType::from(t.as_type());
}

Type TemplateSpecializationType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Type> TemplateSpecializationType::aliased_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal230();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool TemplateSpecializationType::is_current_instantiation(void) const {
  return impl->reader.getVal231();
}

bool TemplateSpecializationType::is_sugared(void) const {
  return impl->reader.getVal232();
}

bool TemplateSpecializationType::is_type_alias(void) const {
  return impl->reader.getVal233();
}

unsigned TemplateSpecializationType::num_template_arguments(void) const {
  return impl->reader.getVal234().size();
}

std::optional<TemplateArgument> TemplateSpecializationType::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal234();
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

gap::generator<TemplateArgument> TemplateSpecializationType::template_arguments(void) const & {
  auto list = impl->reader.getVal234();
  EntityProvider::Ptr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d234 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d234));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
