// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SwiftObjCMembersAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<SwiftObjCMembersAttr> SwiftObjCMembersAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SwiftObjCMembersAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SwiftObjCMembersAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SwiftObjCMembersAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SwiftObjCMembersAttr> SwiftObjCMembersAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return SwiftObjCMembersAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kSwiftObjCMembersAttrDerivedKinds[] = {
    SwiftObjCMembersAttr::static_kind(),
};

std::optional<SwiftObjCMembersAttr> SwiftObjCMembersAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case SwiftObjCMembersAttr::static_kind():
      return reinterpret_cast<const SwiftObjCMembersAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SwiftObjCMembersAttr> SwiftObjCMembersAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kSwiftObjCMembersAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<SwiftObjCMembersAttr> e = SwiftObjCMembersAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwiftObjCMembersAttr> SwiftObjCMembersAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kSwiftObjCMembersAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<SwiftObjCMembersAttr> e = SwiftObjCMembersAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwiftObjCMembersAttr> SwiftObjCMembersAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kSwiftObjCMembersAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<SwiftObjCMembersAttr> e = SwiftObjCMembersAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SwiftObjCMembersAttr> SwiftObjCMembersAttr::from(const Reference &r) {
  return SwiftObjCMembersAttr::from(r.as_attribute());
}

std::optional<SwiftObjCMembersAttr> SwiftObjCMembersAttr::from(const TokenContext &t) {
  return SwiftObjCMembersAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
