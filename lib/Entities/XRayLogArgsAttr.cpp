// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/XRayLogArgsAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<XRayLogArgsAttr> XRayLogArgsAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = XRayLogArgsAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool XRayLogArgsAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : XRayLogArgsAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<XRayLogArgsAttr> XRayLogArgsAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return XRayLogArgsAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kXRayLogArgsAttrDerivedKinds[] = {
    XRayLogArgsAttr::static_kind(),
};

std::optional<XRayLogArgsAttr> XRayLogArgsAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case XRayLogArgsAttr::static_kind():
      return reinterpret_cast<const XRayLogArgsAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<XRayLogArgsAttr> XRayLogArgsAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kXRayLogArgsAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<XRayLogArgsAttr> e = XRayLogArgsAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<XRayLogArgsAttr> XRayLogArgsAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kXRayLogArgsAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<XRayLogArgsAttr> e = XRayLogArgsAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<XRayLogArgsAttr> XRayLogArgsAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kXRayLogArgsAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<XRayLogArgsAttr> e = XRayLogArgsAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<XRayLogArgsAttr> XRayLogArgsAttr::from(const Reference &r) {
  return XRayLogArgsAttr::from(r.as_attribute());
}

std::optional<XRayLogArgsAttr> XRayLogArgsAttr::from(const TokenContext &t) {
  return XRayLogArgsAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
