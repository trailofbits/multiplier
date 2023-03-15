// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/VecTypeHintAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<VecTypeHintAttr> VecTypeHintAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = VecTypeHintAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool VecTypeHintAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : VecTypeHintAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<VecTypeHintAttr> VecTypeHintAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return VecTypeHintAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kVecTypeHintAttrDerivedKinds[] = {
    VecTypeHintAttr::static_kind(),
};

std::optional<VecTypeHintAttr> VecTypeHintAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case VecTypeHintAttr::static_kind():
      return reinterpret_cast<const VecTypeHintAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<VecTypeHintAttr> VecTypeHintAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kVecTypeHintAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<VecTypeHintAttr> e = VecTypeHintAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VecTypeHintAttr> VecTypeHintAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kVecTypeHintAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<VecTypeHintAttr> e = VecTypeHintAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<VecTypeHintAttr> VecTypeHintAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kVecTypeHintAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<VecTypeHintAttr> e = VecTypeHintAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<VecTypeHintAttr> VecTypeHintAttr::from(const Reference &r) {
  return VecTypeHintAttr::from(r.as_attribute());
}

std::optional<VecTypeHintAttr> VecTypeHintAttr::from(const TokenContext &t) {
  return VecTypeHintAttr::from(t.as_attribute());
}

Type VecTypeHintAttr::type_hint(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type VecTypeHintAttr::type_hint_token(void) const {
  RawEntityId eid = impl->reader.getVal16();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
