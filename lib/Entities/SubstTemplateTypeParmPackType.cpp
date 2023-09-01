// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SubstTemplateTypeParmPackType.h>

#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/TemplateTypeParmDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SubstTemplateTypeParmPackType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SubstTemplateTypeParmPackType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SubstTemplateTypeParmPackType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return SubstTemplateTypeParmPackType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kSubstTemplateTypeParmPackTypeDerivedKinds[] = {
    SubstTemplateTypeParmPackType::static_kind(),
};

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const Type &parent) {
  switch (parent.kind()) {
    case SubstTemplateTypeParmPackType::static_kind():
      return reinterpret_cast<const SubstTemplateTypeParmPackType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kSubstTemplateTypeParmPackTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<SubstTemplateTypeParmPackType> e = SubstTemplateTypeParmPackType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const Reference &r) {
  return SubstTemplateTypeParmPackType::from(r.as_type());
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const TokenContext &t) {
  return SubstTemplateTypeParmPackType::from(t.as_type());
}

Type SubstTemplateTypeParmPackType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal232();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Decl SubstTemplateTypeParmPackType::associated_declaration(void) const {
  RawEntityId eid = impl->reader.getVal233();
  return Decl(impl->ep->DeclFor(impl->ep, eid));
}

bool SubstTemplateTypeParmPackType::final(void) const {
  return impl->reader.getVal234();
}

TemplateTypeParmDecl SubstTemplateTypeParmPackType::replaced_parameter(void) const {
  RawEntityId eid = impl->reader.getVal239();
  return TemplateTypeParmDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool SubstTemplateTypeParmPackType::is_sugared(void) const {
  return impl->reader.getVal235();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
