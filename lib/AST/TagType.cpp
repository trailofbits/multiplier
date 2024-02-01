// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TagType.h>
#include <multiplier/AST/TagDecl.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>
#include <multiplier/AST/EnumType.h>
#include <multiplier/AST/RecordType.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kTagTypeDerivedKinds[] = {
    EnumType::static_kind(),
    RecordType::static_kind(),
};
}  // namespace

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
    if (auto base = index.type(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<TagType> TagType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<TagType> TagType::from_base(const Type &parent) {
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
      if (std::optional<TagType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<TagType> TagType::from(const Reference &r) {
  return TagType::from(r.as_type());
}

std::optional<TagType> TagType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<TagType> TagType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

TagDecl TagType::declaration(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return TagDecl::from_base(impl->ep->DeclFor(impl->ep, eid)).value();
}

bool TagType::is_being_defined(void) const {
  return impl->reader.getVal21();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
