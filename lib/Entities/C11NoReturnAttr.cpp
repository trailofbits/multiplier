// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/C11NoReturnAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<C11NoReturnAttr> C11NoReturnAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = C11NoReturnAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool C11NoReturnAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : C11NoReturnAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<C11NoReturnAttr> C11NoReturnAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return C11NoReturnAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kC11NoReturnAttrDerivedKinds[] = {
    C11NoReturnAttr::static_kind(),
};

std::optional<C11NoReturnAttr> C11NoReturnAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case C11NoReturnAttr::static_kind():
      return reinterpret_cast<const C11NoReturnAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<C11NoReturnAttr> C11NoReturnAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kC11NoReturnAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<C11NoReturnAttr> e = C11NoReturnAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<C11NoReturnAttr> C11NoReturnAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kC11NoReturnAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<C11NoReturnAttr> e = C11NoReturnAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<C11NoReturnAttr> C11NoReturnAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kC11NoReturnAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<C11NoReturnAttr> e = C11NoReturnAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<C11NoReturnAttr> C11NoReturnAttr::from(const Reference &r) {
  return C11NoReturnAttr::from(r.as_attribute());
}

std::optional<C11NoReturnAttr> C11NoReturnAttr::from(const TokenContext &t) {
  return C11NoReturnAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
