// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AvailabilityAttr.h>

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AvailabilityAttr> AvailabilityAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AvailabilityAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AvailabilityAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AvailabilityAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AvailabilityAttr> AvailabilityAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<AvailabilityAttr> AvailabilityAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kAvailabilityAttrDerivedKinds[] = {
    AvailabilityAttr::static_kind(),
};

}  // namespace

std::optional<AvailabilityAttr> AvailabilityAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case AvailabilityAttr::static_kind():
      return reinterpret_cast<const AvailabilityAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AvailabilityAttr> AvailabilityAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kAvailabilityAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AvailabilityAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AvailabilityAttr> AvailabilityAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAvailabilityAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AvailabilityAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AvailabilityAttr> AvailabilityAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAvailabilityAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AvailabilityAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AvailabilityAttr> AvailabilityAttr::from(const Reference &r) {
  return AvailabilityAttr::from(r.as_attribute());
}

std::optional<AvailabilityAttr> AvailabilityAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<AvailabilityAttr> AvailabilityAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::string_view AvailabilityAttr::message(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

std::string_view AvailabilityAttr::replacement(void) const {
  capnp::Text::Reader data = impl->reader.getVal17();
  return std::string_view(data.cStr(), data.size());
}

bool AvailabilityAttr::strict(void) const {
  return impl->reader.getVal12();
}

bool AvailabilityAttr::unavailable(void) const {
  return impl->reader.getVal13();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
