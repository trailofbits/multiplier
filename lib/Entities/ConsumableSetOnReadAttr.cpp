// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConsumableSetOnReadAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConsumableSetOnReadAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConsumableSetOnReadAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConsumableSetOnReadAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kConsumableSetOnReadAttrDerivedKinds[] = {
    ConsumableSetOnReadAttr::static_kind(),
};

}  // namespace

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case ConsumableSetOnReadAttr::static_kind():
      return reinterpret_cast<const ConsumableSetOnReadAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kConsumableSetOnReadAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ConsumableSetOnReadAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kConsumableSetOnReadAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ConsumableSetOnReadAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kConsumableSetOnReadAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ConsumableSetOnReadAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::from(const Reference &r) {
  return ConsumableSetOnReadAttr::from(r.as_attribute());
}

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<ConsumableSetOnReadAttr> ConsumableSetOnReadAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
