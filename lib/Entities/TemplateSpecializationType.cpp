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

#include "../EntityProvider.h"
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTemplateSpecializationTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TemplateSpecializationType> e = TemplateSpecializationType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
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
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<Type> TemplateSpecializationType::aliased_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal19();
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
  return impl->reader.getVal20();
}

bool TemplateSpecializationType::is_sugared(void) const {
  return impl->reader.getVal21();
}

bool TemplateSpecializationType::is_type_alias(void) const {
  return impl->reader.getVal22();
}

unsigned TemplateSpecializationType::num_template_arguments(void) const {
  return impl->reader.getVal23().size();
}

std::optional<TemplateArgument> TemplateSpecializationType::nth_template_argument(unsigned n) const {
  auto list = impl->reader.getVal23();
  if (n >= list.size()) {
    return std::nullopt;
  }
  const EntityProviderPtr &ep = impl->ep;
  auto v = list[n];
  auto e = ep->TemplateArgumentFor(ep, v);
  if (!e) {
    return std::nullopt;
  }
  return TemplateArgument(std::move(e));
}

gap::generator<TemplateArgument> TemplateSpecializationType::template_arguments(void) const & {
  auto list = impl->reader.getVal23();
  EntityProviderPtr ep = impl->ep;
  for (auto v : list) {
    EntityId id(v);
    if (auto d23 = ep->TemplateArgumentFor(ep, v)) {
      co_yield TemplateArgument(std::move(d23));
    }
  }
  co_return;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
