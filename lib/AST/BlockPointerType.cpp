// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BlockPointerType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kBlockPointerTypeDerivedKinds[] = {
    BlockPointerType::static_kind(),
};
}  // namespace

gap::generator<BlockPointerType> BlockPointerType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BlockPointerType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BlockPointerType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BlockPointerType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BlockPointerType> BlockPointerType::by_id(const Index &index, EntityId eid) {
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

std::optional<BlockPointerType> BlockPointerType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<BlockPointerType> BlockPointerType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case BlockPointerType::static_kind():
      return reinterpret_cast<const BlockPointerType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlockPointerType> BlockPointerType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kBlockPointerTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<BlockPointerType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<BlockPointerType> BlockPointerType::from(const Reference &r) {
  return BlockPointerType::from(r.as_type());
}

std::optional<BlockPointerType> BlockPointerType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<BlockPointerType> BlockPointerType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type BlockPointerType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal18();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type BlockPointerType::pointee_type(void) const {
  RawEntityId eid = impl->reader.getVal19();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool BlockPointerType::is_sugared(void) const {
  return impl->reader.getVal20();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
