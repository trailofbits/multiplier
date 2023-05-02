// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCBridgeAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCBridgeAttr> ObjCBridgeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCBridgeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCBridgeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCBridgeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCBridgeAttr> ObjCBridgeAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ObjCBridgeAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kObjCBridgeAttrDerivedKinds[] = {
    ObjCBridgeAttr::static_kind(),
};

std::optional<ObjCBridgeAttr> ObjCBridgeAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ObjCBridgeAttr::static_kind():
      return reinterpret_cast<const ObjCBridgeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCBridgeAttr> ObjCBridgeAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kObjCBridgeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ObjCBridgeAttr> e = ObjCBridgeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgeAttr> ObjCBridgeAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kObjCBridgeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ObjCBridgeAttr> e = ObjCBridgeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCBridgeAttr> ObjCBridgeAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kObjCBridgeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ObjCBridgeAttr> e = ObjCBridgeAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCBridgeAttr> ObjCBridgeAttr::from(const Reference &r) {
  return ObjCBridgeAttr::from(r.as_attribute());
}

std::optional<ObjCBridgeAttr> ObjCBridgeAttr::from(const TokenContext &t) {
  return ObjCBridgeAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
