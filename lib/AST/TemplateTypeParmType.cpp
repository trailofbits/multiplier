// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateTypeParmType.h>
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
static const TypeKind kTemplateTypeParmTypeDerivedKinds[] = {
    TemplateTypeParmType::static_kind(),
};
}  // namespace

gap::generator<TemplateTypeParmType> TemplateTypeParmType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TemplateTypeParmType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TemplateTypeParmType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TemplateTypeParmType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TemplateTypeParmType> TemplateTypeParmType::by_id(const Index &index, EntityId eid) {
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

std::optional<TemplateTypeParmType> TemplateTypeParmType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TemplateTypeParmType> TemplateTypeParmType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case TemplateTypeParmType::static_kind():
      return reinterpret_cast<const TemplateTypeParmType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateTypeParmType> TemplateTypeParmType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TemplateTypeParmType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TemplateTypeParmType> TemplateTypeParmType::from(const Reference &r) {
  return TemplateTypeParmType::from(r.as_type());
}

std::optional<TemplateTypeParmType> TemplateTypeParmType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<TemplateTypeParmType> TemplateTypeParmType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type TemplateTypeParmType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmType::declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal20();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TemplateTypeParmDecl::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

bool TemplateTypeParmType::is_parameter_pack(void) const {
  return impl->reader.getVal21();
}

bool TemplateTypeParmType::is_sugared(void) const {
  return impl->reader.getVal22();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
