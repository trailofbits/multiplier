// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InjectedClassNameType.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/TemplateSpecializationType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kInjectedClassNameTypeDerivedKinds[] = {
    InjectedClassNameType::static_kind(),
};
}  // namespace

gap::generator<InjectedClassNameType> InjectedClassNameType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = InjectedClassNameType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool InjectedClassNameType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : InjectedClassNameType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<InjectedClassNameType> InjectedClassNameType::by_id(const Index &index, EntityId eid) {
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

std::optional<InjectedClassNameType> InjectedClassNameType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<InjectedClassNameType> InjectedClassNameType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case InjectedClassNameType::static_kind():
      return reinterpret_cast<const InjectedClassNameType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<InjectedClassNameType> InjectedClassNameType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kInjectedClassNameTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<InjectedClassNameType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<InjectedClassNameType> InjectedClassNameType::from(const Reference &r) {
  return InjectedClassNameType::from(r.as_type());
}

std::optional<InjectedClassNameType> InjectedClassNameType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<InjectedClassNameType> InjectedClassNameType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type InjectedClassNameType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

CXXRecordDecl InjectedClassNameType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return CXXRecordDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

Type InjectedClassNameType::injected_specialization_type(void) const {
  RawEntityId eid = impl->reader.getVal25();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TemplateSpecializationType InjectedClassNameType::injected_tst(void) const {
  RawEntityId eid = impl->reader.getVal26();
  return TemplateSpecializationType::from_base(impl->ep->TypeFor(impl->ep, eid)).value();
}

bool InjectedClassNameType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
