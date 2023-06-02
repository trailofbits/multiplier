// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArcWeakrefUnavailableAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ArcWeakrefUnavailableAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ArcWeakrefUnavailableAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ArcWeakrefUnavailableAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ArcWeakrefUnavailableAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kArcWeakrefUnavailableAttrDerivedKinds[] = {
    ArcWeakrefUnavailableAttr::static_kind(),
};

std::optional<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ArcWeakrefUnavailableAttr::static_kind():
      return reinterpret_cast<const ArcWeakrefUnavailableAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kArcWeakrefUnavailableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ArcWeakrefUnavailableAttr> e = ArcWeakrefUnavailableAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kArcWeakrefUnavailableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ArcWeakrefUnavailableAttr> e = ArcWeakrefUnavailableAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kArcWeakrefUnavailableAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ArcWeakrefUnavailableAttr> e = ArcWeakrefUnavailableAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::from(const Reference &r) {
  return ArcWeakrefUnavailableAttr::from(r.as_attribute());
}

std::optional<ArcWeakrefUnavailableAttr> ArcWeakrefUnavailableAttr::from(const TokenContext &t) {
  return ArcWeakrefUnavailableAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
