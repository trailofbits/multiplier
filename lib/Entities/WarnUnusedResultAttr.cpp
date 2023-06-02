// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/WarnUnusedResultAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<WarnUnusedResultAttr> WarnUnusedResultAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = WarnUnusedResultAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool WarnUnusedResultAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : WarnUnusedResultAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return WarnUnusedResultAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kWarnUnusedResultAttrDerivedKinds[] = {
    WarnUnusedResultAttr::static_kind(),
};

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case WarnUnusedResultAttr::static_kind():
      return reinterpret_cast<const WarnUnusedResultAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<WarnUnusedResultAttr> WarnUnusedResultAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kWarnUnusedResultAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<WarnUnusedResultAttr> e = WarnUnusedResultAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<WarnUnusedResultAttr> WarnUnusedResultAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kWarnUnusedResultAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<WarnUnusedResultAttr> e = WarnUnusedResultAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<WarnUnusedResultAttr> WarnUnusedResultAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kWarnUnusedResultAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<WarnUnusedResultAttr> e = WarnUnusedResultAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::from(const Reference &r) {
  return WarnUnusedResultAttr::from(r.as_attribute());
}

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::from(const TokenContext &t) {
  return WarnUnusedResultAttr::from(t.as_attribute());
}

bool WarnUnusedResultAttr::is_cxx11_no_discard(void) const {
  return impl->reader.getVal12();
}

std::string_view WarnUnusedResultAttr::message(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

WarnUnusedResultAttrSpelling WarnUnusedResultAttr::semantic_spelling(void) const {
  return static_cast<WarnUnusedResultAttrSpelling>(impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
