// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/PointerAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<PointerAttr> PointerAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = PointerAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool PointerAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : PointerAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<PointerAttr> PointerAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return PointerAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kPointerAttrDerivedKinds[] = {
    PointerAttr::static_kind(),
};

std::optional<PointerAttr> PointerAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case PointerAttr::static_kind():
      return reinterpret_cast<const PointerAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<PointerAttr> PointerAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kPointerAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<PointerAttr> e = PointerAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PointerAttr> PointerAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kPointerAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<PointerAttr> e = PointerAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<PointerAttr> PointerAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kPointerAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<PointerAttr> e = PointerAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<PointerAttr> PointerAttr::from(const Reference &r) {
  return PointerAttr::from(r.as_attribute());
}

std::optional<PointerAttr> PointerAttr::from(const TokenContext &t) {
  return PointerAttr::from(t.as_attribute());
}

Type PointerAttr::deref_type(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type PointerAttr::deref_type_token(void) const {
  RawEntityId eid = impl->reader.getVal16();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
