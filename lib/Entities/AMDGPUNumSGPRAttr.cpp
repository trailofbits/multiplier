// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AMDGPUNumSGPRAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AMDGPUNumSGPRAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AMDGPUNumSGPRAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AMDGPUNumSGPRAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kAMDGPUNumSGPRAttrDerivedKinds[] = {
    AMDGPUNumSGPRAttr::static_kind(),
};

}  // namespace

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case AMDGPUNumSGPRAttr::static_kind():
      return reinterpret_cast<const AMDGPUNumSGPRAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kAMDGPUNumSGPRAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AMDGPUNumSGPRAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAMDGPUNumSGPRAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AMDGPUNumSGPRAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAMDGPUNumSGPRAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AMDGPUNumSGPRAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::from(const Reference &r) {
  return AMDGPUNumSGPRAttr::from(r.as_attribute());
}

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<AMDGPUNumSGPRAttr> AMDGPUNumSGPRAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
