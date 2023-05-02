// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AnnotateTypeAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AnnotateTypeAttr> AnnotateTypeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AnnotateTypeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AnnotateTypeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AnnotateTypeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AnnotateTypeAttr> AnnotateTypeAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return AnnotateTypeAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kAnnotateTypeAttrDerivedKinds[] = {
    AnnotateTypeAttr::static_kind(),
};

std::optional<AnnotateTypeAttr> AnnotateTypeAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case AnnotateTypeAttr::static_kind():
      return reinterpret_cast<const AnnotateTypeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AnnotateTypeAttr> AnnotateTypeAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kAnnotateTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AnnotateTypeAttr> e = AnnotateTypeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AnnotateTypeAttr> AnnotateTypeAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAnnotateTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AnnotateTypeAttr> e = AnnotateTypeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AnnotateTypeAttr> AnnotateTypeAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAnnotateTypeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AnnotateTypeAttr> e = AnnotateTypeAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AnnotateTypeAttr> AnnotateTypeAttr::from(const Reference &r) {
  return AnnotateTypeAttr::from(r.as_attribute());
}

std::optional<AnnotateTypeAttr> AnnotateTypeAttr::from(const TokenContext &t) {
  return AnnotateTypeAttr::from(t.as_attribute());
}

std::string_view AnnotateTypeAttr::annotation(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
