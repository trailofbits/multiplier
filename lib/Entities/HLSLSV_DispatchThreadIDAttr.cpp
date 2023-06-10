// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLSV_DispatchThreadIDAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/HLSLAnnotationAttr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLSV_DispatchThreadIDAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLSV_DispatchThreadIDAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLSV_DispatchThreadIDAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return HLSLSV_DispatchThreadIDAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kHLSLSV_DispatchThreadIDAttrDerivedKinds[] = {
    HLSLSV_DispatchThreadIDAttr::static_kind(),
};

std::optional<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLSV_DispatchThreadIDAttr::static_kind():
      return reinterpret_cast<const HLSLSV_DispatchThreadIDAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLSV_DispatchThreadIDAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLSV_DispatchThreadIDAttr> e = HLSLSV_DispatchThreadIDAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLSV_DispatchThreadIDAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLSV_DispatchThreadIDAttr> e = HLSLSV_DispatchThreadIDAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLSV_DispatchThreadIDAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLSV_DispatchThreadIDAttr> e = HLSLSV_DispatchThreadIDAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::from(const Reference &r) {
  return HLSLSV_DispatchThreadIDAttr::from(r.as_attribute());
}

std::optional<HLSLSV_DispatchThreadIDAttr> HLSLSV_DispatchThreadIDAttr::from(const TokenContext &t) {
  return HLSLSV_DispatchThreadIDAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
