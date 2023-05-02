// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLGroupSharedAddressSpaceAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLGroupSharedAddressSpaceAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLGroupSharedAddressSpaceAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLGroupSharedAddressSpaceAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return HLSLGroupSharedAddressSpaceAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kHLSLGroupSharedAddressSpaceAttrDerivedKinds[] = {
    HLSLGroupSharedAddressSpaceAttr::static_kind(),
};

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLGroupSharedAddressSpaceAttr::static_kind():
      return reinterpret_cast<const HLSLGroupSharedAddressSpaceAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = HLSLGroupSharedAddressSpaceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = HLSLGroupSharedAddressSpaceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = HLSLGroupSharedAddressSpaceAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const Reference &r) {
  return HLSLGroupSharedAddressSpaceAttr::from(r.as_attribute());
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const TokenContext &t) {
  return HLSLGroupSharedAddressSpaceAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
