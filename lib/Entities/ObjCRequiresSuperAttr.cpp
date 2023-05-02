// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ObjCRequiresSuperAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ObjCRequiresSuperAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ObjCRequiresSuperAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ObjCRequiresSuperAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ObjCRequiresSuperAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kObjCRequiresSuperAttrDerivedKinds[] = {
    ObjCRequiresSuperAttr::static_kind(),
};

std::optional<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ObjCRequiresSuperAttr::static_kind():
      return reinterpret_cast<const ObjCRequiresSuperAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kObjCRequiresSuperAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ObjCRequiresSuperAttr> e = ObjCRequiresSuperAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kObjCRequiresSuperAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ObjCRequiresSuperAttr> e = ObjCRequiresSuperAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kObjCRequiresSuperAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ObjCRequiresSuperAttr> e = ObjCRequiresSuperAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::from(const Reference &r) {
  return ObjCRequiresSuperAttr::from(r.as_attribute());
}

std::optional<ObjCRequiresSuperAttr> ObjCRequiresSuperAttr::from(const TokenContext &t) {
  return ObjCRequiresSuperAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
