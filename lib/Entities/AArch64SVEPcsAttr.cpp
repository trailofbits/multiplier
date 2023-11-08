// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AArch64SVEPcsAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AArch64SVEPcsAttr> AArch64SVEPcsAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AArch64SVEPcsAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AArch64SVEPcsAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AArch64SVEPcsAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AArch64SVEPcsAttr> AArch64SVEPcsAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return AArch64SVEPcsAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kAArch64SVEPcsAttrDerivedKinds[] = {
    AArch64SVEPcsAttr::static_kind(),
};

std::optional<AArch64SVEPcsAttr> AArch64SVEPcsAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case AArch64SVEPcsAttr::static_kind():
      return reinterpret_cast<const AArch64SVEPcsAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AArch64SVEPcsAttr> AArch64SVEPcsAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kAArch64SVEPcsAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AArch64SVEPcsAttr> e = AArch64SVEPcsAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AArch64SVEPcsAttr> AArch64SVEPcsAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAArch64SVEPcsAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AArch64SVEPcsAttr> e = AArch64SVEPcsAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AArch64SVEPcsAttr> AArch64SVEPcsAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAArch64SVEPcsAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AArch64SVEPcsAttr> e = AArch64SVEPcsAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AArch64SVEPcsAttr> AArch64SVEPcsAttr::from(const Reference &r) {
  return AArch64SVEPcsAttr::from(r.as_attribute());
}

std::optional<AArch64SVEPcsAttr> AArch64SVEPcsAttr::from(const TokenContext &t) {
  return AArch64SVEPcsAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
