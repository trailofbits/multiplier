// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenCLGenericAddressSpaceAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OpenCLGenericAddressSpaceAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OpenCLGenericAddressSpaceAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OpenCLGenericAddressSpaceAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return OpenCLGenericAddressSpaceAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kOpenCLGenericAddressSpaceAttrDerivedKinds[] = {
    OpenCLGenericAddressSpaceAttr::static_kind(),
};

std::optional<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case OpenCLGenericAddressSpaceAttr::static_kind():
      return reinterpret_cast<const OpenCLGenericAddressSpaceAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kOpenCLGenericAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OpenCLGenericAddressSpaceAttr> e = OpenCLGenericAddressSpaceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOpenCLGenericAddressSpaceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OpenCLGenericAddressSpaceAttr> e = OpenCLGenericAddressSpaceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOpenCLGenericAddressSpaceAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OpenCLGenericAddressSpaceAttr> e = OpenCLGenericAddressSpaceAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::from(const Reference &r) {
  return OpenCLGenericAddressSpaceAttr::from(r.as_attribute());
}

std::optional<OpenCLGenericAddressSpaceAttr> OpenCLGenericAddressSpaceAttr::from(const TokenContext &t) {
  return OpenCLGenericAddressSpaceAttr::from(t.as_attribute());
}

OpenCLGenericAddressSpaceAttrSpelling OpenCLGenericAddressSpaceAttr::semantic_spelling(void) const {
  return static_cast<OpenCLGenericAddressSpaceAttrSpelling>(impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
