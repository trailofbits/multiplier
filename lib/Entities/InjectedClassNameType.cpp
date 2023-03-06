// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InjectedClassNameType.h>

#include <multiplier/Entities/CXXRecordDecl.h>
#include <multiplier/Entities/TemplateSpecializationType.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return InjectedClassNameType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kInjectedClassNameTypeDerivedKinds[] = {
    InjectedClassNameType::static_kind(),
};

std::optional<InjectedClassNameType> InjectedClassNameType::from(const Type &parent) {
  switch (parent.kind()) {
    case InjectedClassNameType::static_kind():
      return reinterpret_cast<const InjectedClassNameType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<InjectedClassNameType> InjectedClassNameType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kInjectedClassNameTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<InjectedClassNameType> e = InjectedClassNameType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InjectedClassNameType> InjectedClassNameType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kInjectedClassNameTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<InjectedClassNameType> e = InjectedClassNameType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InjectedClassNameType> InjectedClassNameType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kInjectedClassNameTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<InjectedClassNameType> e = InjectedClassNameType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type InjectedClassNameType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

CXXRecordDecl InjectedClassNameType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal292();
  return CXXRecordDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

Type InjectedClassNameType::injected_specialization_type(void) const {
  RawEntityId eid = impl->reader.getVal297();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

TemplateSpecializationType InjectedClassNameType::injected_tst(void) const {
  RawEntityId eid = impl->reader.getVal299();
  return TemplateSpecializationType::from(Type(impl->ep->TypeFor(impl->ep, eid))).value();
}

bool InjectedClassNameType::is_sugared(void) const {
  return impl->reader.getVal293();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
