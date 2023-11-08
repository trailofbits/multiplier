// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ARMInterruptAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ARMInterruptAttr> ARMInterruptAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ARMInterruptAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ARMInterruptAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ARMInterruptAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ARMInterruptAttr> ARMInterruptAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ARMInterruptAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kARMInterruptAttrDerivedKinds[] = {
    ARMInterruptAttr::static_kind(),
};

std::optional<ARMInterruptAttr> ARMInterruptAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ARMInterruptAttr::static_kind():
      return reinterpret_cast<const ARMInterruptAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ARMInterruptAttr> ARMInterruptAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kARMInterruptAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ARMInterruptAttr> e = ARMInterruptAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ARMInterruptAttr> ARMInterruptAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kARMInterruptAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ARMInterruptAttr> e = ARMInterruptAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ARMInterruptAttr> ARMInterruptAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kARMInterruptAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ARMInterruptAttr> e = ARMInterruptAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ARMInterruptAttr> ARMInterruptAttr::from(const Reference &r) {
  return ARMInterruptAttr::from(r.as_attribute());
}

std::optional<ARMInterruptAttr> ARMInterruptAttr::from(const TokenContext &t) {
  return ARMInterruptAttr::from(t.as_attribute());
}

ARMInterruptAttrInterruptType ARMInterruptAttr::interrupt(void) const {
  return static_cast<ARMInterruptAttrInterruptType>(impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
