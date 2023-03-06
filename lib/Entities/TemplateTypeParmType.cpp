// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateTypeParmType.h>

#include <multiplier/Entities/TemplateTypeParmDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return TemplateTypeParmType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kTemplateTypeParmTypeDerivedKinds[] = {
    TemplateTypeParmType::static_kind(),
};

std::optional<TemplateTypeParmType> TemplateTypeParmType::from(const Type &parent) {
  switch (parent.kind()) {
    case TemplateTypeParmType::static_kind():
      return reinterpret_cast<const TemplateTypeParmType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TemplateTypeParmType> TemplateTypeParmType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TemplateTypeParmType> e = TemplateTypeParmType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateTypeParmType> TemplateTypeParmType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kTemplateTypeParmTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<TemplateTypeParmType> e = TemplateTypeParmType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TemplateTypeParmType> TemplateTypeParmType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kTemplateTypeParmTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<TemplateTypeParmType> e = TemplateTypeParmType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type TemplateTypeParmType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal291();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmType::declaration(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal292();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->DeclFor(impl->ep, eid)) {
      return TemplateTypeParmDecl::from(Decl(std::move(eptr)));
    }
  }
  return std::nullopt;
}

bool TemplateTypeParmType::is_parameter_pack(void) const {
  return impl->reader.getVal293();
}

bool TemplateTypeParmType::is_sugared(void) const {
  return impl->reader.getVal294();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
