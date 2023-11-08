// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSAllocatorAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MSAllocatorAttr> MSAllocatorAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSAllocatorAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSAllocatorAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSAllocatorAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<MSAllocatorAttr> MSAllocatorAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return MSAllocatorAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kMSAllocatorAttrDerivedKinds[] = {
    MSAllocatorAttr::static_kind(),
};

std::optional<MSAllocatorAttr> MSAllocatorAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case MSAllocatorAttr::static_kind():
      return reinterpret_cast<const MSAllocatorAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSAllocatorAttr> MSAllocatorAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kMSAllocatorAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<MSAllocatorAttr> e = MSAllocatorAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSAllocatorAttr> MSAllocatorAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kMSAllocatorAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<MSAllocatorAttr> e = MSAllocatorAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSAllocatorAttr> MSAllocatorAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kMSAllocatorAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<MSAllocatorAttr> e = MSAllocatorAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSAllocatorAttr> MSAllocatorAttr::from(const Reference &r) {
  return MSAllocatorAttr::from(r.as_attribute());
}

std::optional<MSAllocatorAttr> MSAllocatorAttr::from(const TokenContext &t) {
  return MSAllocatorAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
