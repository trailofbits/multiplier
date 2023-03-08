// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BTFTypeTagAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeAttr.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BTFTypeTagAttr> BTFTypeTagAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BTFTypeTagAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BTFTypeTagAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BTFTypeTagAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BTFTypeTagAttr> BTFTypeTagAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return BTFTypeTagAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kBTFTypeTagAttrDerivedKinds[] = {
    BTFTypeTagAttr::static_kind(),
};

std::optional<BTFTypeTagAttr> BTFTypeTagAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case BTFTypeTagAttr::static_kind():
      return reinterpret_cast<const BTFTypeTagAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BTFTypeTagAttr> BTFTypeTagAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kBTFTypeTagAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<BTFTypeTagAttr> e = BTFTypeTagAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BTFTypeTagAttr> BTFTypeTagAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kBTFTypeTagAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<BTFTypeTagAttr> e = BTFTypeTagAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BTFTypeTagAttr> BTFTypeTagAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kBTFTypeTagAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<BTFTypeTagAttr> e = BTFTypeTagAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BTFTypeTagAttr> BTFTypeTagAttr::from(const Reference &r) {
  return BTFTypeTagAttr::from(r.as_attribute());
}

std::optional<BTFTypeTagAttr> BTFTypeTagAttr::from(const TokenContext &t) {
  return BTFTypeTagAttr::from(t.as_attribute());
}

std::string_view BTFTypeTagAttr::btf_type_tag(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
