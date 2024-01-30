// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RecordType.h>
#include <multiplier/AST/TagType.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/Type.h>

#include "../EntityProvider.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const TypeKind kRecordTypeDerivedKinds[] = {
    RecordType::static_kind(),
};
}  // namespace

gap::generator<RecordType> RecordType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = RecordType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool RecordType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : RecordType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<RecordType> RecordType::by_id(const Index &index, EntityId eid) {
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

std::optional<RecordType> RecordType::from(const std::optional<Type> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<RecordType> RecordType::from_base(const Type &parent) {
  switch (parent.kind()) {
    case RecordType::static_kind():
      return reinterpret_cast<const RecordType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<RecordType> RecordType::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (TypeKind k : kRecordTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<RecordType> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

std::optional<RecordType> RecordType::from(const Reference &r) {
  return RecordType::from(r.as_type());
}

std::optional<RecordType> RecordType::from(const VariantEntity &e) {
  if (!std::holds_alternative<Type>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Type>(e));
}

std::optional<RecordType> RecordType::from(const TokenContext &t) {
  if (auto base = t.as_type()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

Type RecordType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal20();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool RecordType::has_const_fields(void) const {
  return impl->reader.getVal22();
}

bool RecordType::is_sugared(void) const {
  return impl->reader.getVal23();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
