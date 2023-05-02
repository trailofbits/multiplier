// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLShaderAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<HLSLShaderAttr> HLSLShaderAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLShaderAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLShaderAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLShaderAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<HLSLShaderAttr> HLSLShaderAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return HLSLShaderAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kHLSLShaderAttrDerivedKinds[] = {
    HLSLShaderAttr::static_kind(),
};

std::optional<HLSLShaderAttr> HLSLShaderAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLShaderAttr::static_kind():
      return reinterpret_cast<const HLSLShaderAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<HLSLShaderAttr> HLSLShaderAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLShaderAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLShaderAttr> e = HLSLShaderAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLShaderAttr> HLSLShaderAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLShaderAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLShaderAttr> e = HLSLShaderAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLShaderAttr> HLSLShaderAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLShaderAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLShaderAttr> e = HLSLShaderAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<HLSLShaderAttr> HLSLShaderAttr::from(const Reference &r) {
  return HLSLShaderAttr::from(r.as_attribute());
}

std::optional<HLSLShaderAttr> HLSLShaderAttr::from(const TokenContext &t) {
  return HLSLShaderAttr::from(t.as_attribute());
}

HLSLShaderAttrShaderType HLSLShaderAttr::type(void) const {
  return static_cast<HLSLShaderAttrShaderType>(impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
