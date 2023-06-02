// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnresolvedUsingType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>
#include <multiplier/Entities/UnresolvedUsingTypenameDecl.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<UnresolvedUsingType> UnresolvedUsingType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = UnresolvedUsingType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool UnresolvedUsingType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : UnresolvedUsingType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<UnresolvedUsingType> UnresolvedUsingType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return UnresolvedUsingType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kUnresolvedUsingTypeDerivedKinds[] = {
    UnresolvedUsingType::static_kind(),
};

std::optional<UnresolvedUsingType> UnresolvedUsingType::from(const Type &parent) {
  switch (parent.kind()) {
    case UnresolvedUsingType::static_kind():
      return reinterpret_cast<const UnresolvedUsingType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<UnresolvedUsingType> UnresolvedUsingType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kUnresolvedUsingTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<UnresolvedUsingType> e = UnresolvedUsingType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingType> UnresolvedUsingType::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kUnresolvedUsingTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<UnresolvedUsingType> e = UnresolvedUsingType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<UnresolvedUsingType> UnresolvedUsingType::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kUnresolvedUsingTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<UnresolvedUsingType> e = UnresolvedUsingType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<UnresolvedUsingType> UnresolvedUsingType::from(const Reference &r) {
  return UnresolvedUsingType::from(r.as_type());
}

std::optional<UnresolvedUsingType> UnresolvedUsingType::from(const TokenContext &t) {
  return UnresolvedUsingType::from(t.as_type());
}

Type UnresolvedUsingType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal229();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

UnresolvedUsingTypenameDecl UnresolvedUsingType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal230();
  return UnresolvedUsingTypenameDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool UnresolvedUsingType::is_sugared(void) const {
  return impl->reader.getVal231();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
