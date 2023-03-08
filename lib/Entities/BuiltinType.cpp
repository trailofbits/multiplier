// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BuiltinType.h>

#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Type.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BuiltinType> BuiltinType::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BuiltinType::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BuiltinType::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BuiltinType::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BuiltinType> BuiltinType::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<TypeId>(vid)) {
    return BuiltinType::from(index.type(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const TypeKind kBuiltinTypeDerivedKinds[] = {
    BuiltinType::static_kind(),
};

std::optional<BuiltinType> BuiltinType::from(const Type &parent) {
  switch (parent.kind()) {
    case BuiltinType::static_kind():
      return reinterpret_cast<const BuiltinType &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BuiltinType> BuiltinType::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (TypeKind k : kBuiltinTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k)) {
      if (std::optional<BuiltinType> e = BuiltinType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BuiltinType> BuiltinType::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (TypeKind k : kBuiltinTypeDerivedKinds) {
    for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
      if (std::optional<BuiltinType> e = BuiltinType::from(Type(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BuiltinType> BuiltinType::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (TypeKind k : kBuiltinTypeDerivedKinds) {
      for (TypeImplPtr eptr : ep->TypesFor(ep, k, frag_id)) {
        if (std::optional<BuiltinType> e = BuiltinType::from(Type(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

Type BuiltinType::desugar(void) const {
  RawEntityId eid = impl->reader.getVal228();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

BuiltinTypeKind BuiltinType::builtin_kind(void) const {
  return static_cast<BuiltinTypeKind>(impl->reader.getVal235());
}

bool BuiltinType::is_floating_point(void) const {
  return impl->reader.getVal230();
}

bool BuiltinType::is_integer(void) const {
  return impl->reader.getVal231();
}

bool BuiltinType::is_sve_bool(void) const {
  return impl->reader.getVal232();
}

bool BuiltinType::is_signed_integer(void) const {
  return impl->reader.getVal236();
}

bool BuiltinType::is_sugared(void) const {
  return impl->reader.getVal237();
}

bool BuiltinType::is_unsigned_integer(void) const {
  return impl->reader.getVal238();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx