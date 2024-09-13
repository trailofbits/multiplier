// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/HLSLGroupSharedAddressSpaceAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const AttrKind kHLSLGroupSharedAddressSpaceAttrDerivedKinds[] = {
    HLSLGroupSharedAddressSpaceAttr::static_kind(),
};
}  // namespace

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLGroupSharedAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLGroupSharedAddressSpaceAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLGroupSharedAddressSpaceAttr::static_kind():
      return reinterpret_cast<const HLSLGroupSharedAddressSpaceAttr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const Reference &r) {
  return HLSLGroupSharedAddressSpaceAttr::from(r.as_attribute());
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<HLSLGroupSharedAddressSpaceAttr> HLSLGroupSharedAddressSpaceAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
