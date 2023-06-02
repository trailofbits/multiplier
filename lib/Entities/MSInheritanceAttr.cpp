// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSInheritanceAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<MSInheritanceAttr> MSInheritanceAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = MSInheritanceAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool MSInheritanceAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : MSInheritanceAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<MSInheritanceAttr> MSInheritanceAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return MSInheritanceAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kMSInheritanceAttrDerivedKinds[] = {
    MSInheritanceAttr::static_kind(),
};

std::optional<MSInheritanceAttr> MSInheritanceAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case MSInheritanceAttr::static_kind():
      return reinterpret_cast<const MSInheritanceAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<MSInheritanceAttr> MSInheritanceAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kMSInheritanceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<MSInheritanceAttr> e = MSInheritanceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSInheritanceAttr> MSInheritanceAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kMSInheritanceAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<MSInheritanceAttr> e = MSInheritanceAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<MSInheritanceAttr> MSInheritanceAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kMSInheritanceAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<MSInheritanceAttr> e = MSInheritanceAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<MSInheritanceAttr> MSInheritanceAttr::from(const Reference &r) {
  return MSInheritanceAttr::from(r.as_attribute());
}

std::optional<MSInheritanceAttr> MSInheritanceAttr::from(const TokenContext &t) {
  return MSInheritanceAttr::from(t.as_attribute());
}

bool MSInheritanceAttr::best_case(void) const {
  return impl->reader.getVal12();
}

MSInheritanceModel MSInheritanceAttr::inheritance_model(void) const {
  return static_cast<MSInheritanceModel>(impl->reader.getVal10());
}

MSInheritanceAttrSpelling MSInheritanceAttr::semantic_spelling(void) const {
  return static_cast<MSInheritanceAttrSpelling>(impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
