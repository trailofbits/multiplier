// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ConstInitAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ConstInitAttr> ConstInitAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ConstInitAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ConstInitAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ConstInitAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ConstInitAttr> ConstInitAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ConstInitAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kConstInitAttrDerivedKinds[] = {
    ConstInitAttr::static_kind(),
};

std::optional<ConstInitAttr> ConstInitAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ConstInitAttr::static_kind():
      return reinterpret_cast<const ConstInitAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ConstInitAttr> ConstInitAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kConstInitAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ConstInitAttr> e = ConstInitAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConstInitAttr> ConstInitAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kConstInitAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ConstInitAttr> e = ConstInitAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ConstInitAttr> ConstInitAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kConstInitAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ConstInitAttr> e = ConstInitAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ConstInitAttr> ConstInitAttr::from(const Reference &r) {
  return ConstInitAttr::from(r.as_attribute());
}

std::optional<ConstInitAttr> ConstInitAttr::from(const TokenContext &t) {
  return ConstInitAttr::from(t.as_attribute());
}

ConstInitAttrSpelling ConstInitAttr::semantic_spelling(void) const {
  return static_cast<ConstInitAttrSpelling>(impl->reader.getVal10());
}

bool ConstInitAttr::is_constinit(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
