// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TagType.h>

#include <multiplier/Entities/EnumType.h>
#include <multiplier/Entities/RecordType.h>
#include <multiplier/Entities/TagDecl.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TagType> TagType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TagType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TagType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TagType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TagType> TagType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return TagType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kTagTypeDerivedKinds[] = {
    EnumType::static_kind(),
    RecordType::static_kind(),
};

std::optional<TagType> TagType::from(const Type &parent) {
  switch (parent.kind()) {
    case EnumType::static_kind():
    case RecordType::static_kind():
      return reinterpret_cast<const TagType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TagType> TagType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kTagTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<TagType> e = TagType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TagType> TagType::from(const Reference &r) {
  return TagType::from(r.as_type());
}

std::optional<TagType> TagType::from(const TokenContext &t) {
  return TagType::from(t.as_type());
}

TagDecl TagType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal232();
  return TagDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

bool TagType::is_being_defined(void) const {
  return impl->reader.getVal234();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
