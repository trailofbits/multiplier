// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeprecatedAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<DeprecatedAttr> DeprecatedAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = DeprecatedAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool DeprecatedAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : DeprecatedAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<DeprecatedAttr> DeprecatedAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return DeprecatedAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kDeprecatedAttrDerivedKinds[] = {
    DeprecatedAttr::static_kind(),
};

std::optional<DeprecatedAttr> DeprecatedAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case DeprecatedAttr::static_kind():
      return reinterpret_cast<const DeprecatedAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<DeprecatedAttr> DeprecatedAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kDeprecatedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<DeprecatedAttr> e = DeprecatedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeprecatedAttr> DeprecatedAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kDeprecatedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<DeprecatedAttr> e = DeprecatedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<DeprecatedAttr> DeprecatedAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kDeprecatedAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<DeprecatedAttr> e = DeprecatedAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<DeprecatedAttr> DeprecatedAttr::from(const Reference &r) {
  return DeprecatedAttr::from(r.as_attribute());
}

std::optional<DeprecatedAttr> DeprecatedAttr::from(const TokenContext &t) {
  return DeprecatedAttr::from(t.as_attribute());
}

std::string_view DeprecatedAttr::message(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

std::string_view DeprecatedAttr::replacement(void) const {
  capnp::Text::Reader data = impl->reader.getVal17();
  return std::string_view(data.cStr(), data.size());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
