// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OwnerAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OwnerAttr> OwnerAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OwnerAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OwnerAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OwnerAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OwnerAttr> OwnerAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return OwnerAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kOwnerAttrDerivedKinds[] = {
    OwnerAttr::static_kind(),
};

std::optional<OwnerAttr> OwnerAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case OwnerAttr::static_kind():
      return reinterpret_cast<const OwnerAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OwnerAttr> OwnerAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kOwnerAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OwnerAttr> e = OwnerAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OwnerAttr> OwnerAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOwnerAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OwnerAttr> e = OwnerAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OwnerAttr> OwnerAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOwnerAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OwnerAttr> e = OwnerAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OwnerAttr> OwnerAttr::from(const Reference &r) {
  return OwnerAttr::from(r.as_attribute());
}

std::optional<OwnerAttr> OwnerAttr::from(const TokenContext &t) {
  return OwnerAttr::from(t.as_attribute());
}

Type OwnerAttr::deref_type(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type OwnerAttr::deref_type_token(void) const {
  RawEntityId eid = impl->reader.getVal16();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
