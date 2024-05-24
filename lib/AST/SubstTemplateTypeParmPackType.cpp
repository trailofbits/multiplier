// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SubstTemplateTypeParmPackType.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/TemplateTypeParmDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kSubstTemplateTypeParmPackTypeDerivedKinds[] = {
    SubstTemplateTypeParmPackType::static_kind(),
};
}  // namespace

gap::generator<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kSubstTemplateTypeParmPackTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<SubstTemplateTypeParmPackType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case SubstTemplateTypeParmPackType::static_kind():
      return reinterpret_cast<const SubstTemplateTypeParmPackType &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const Reference &r) {
  return SubstTemplateTypeParmPackType::from(r.as_type());
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<SubstTemplateTypeParmPackType> SubstTemplateTypeParmPackType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Decl SubstTemplateTypeParmPackType::associated_declaration(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Decl(impl->ep->DeclFor(impl->ep, eid));
}

bool SubstTemplateTypeParmPackType::final(void) const {
  return impl->reader.getVal20();
}

TemplateTypeParmDecl SubstTemplateTypeParmPackType::replaced_parameter(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return TemplateTypeParmDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool SubstTemplateTypeParmPackType::is_sugared(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
