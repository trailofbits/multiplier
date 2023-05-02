// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InheritableParamAttr.h>

#include <multiplier/Entities/AnnotateAttr.h>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/CFConsumedAttr.h>
#include <multiplier/Entities/CarriesDependencyAttr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/NSConsumedAttr.h>
#include <multiplier/Entities/NonNullAttr.h>
#include <multiplier/Entities/OSConsumedAttr.h>
#include <multiplier/Entities/PassObjectSizeAttr.h>
#include <multiplier/Entities/ReleaseHandleAttr.h>
#include <multiplier/Entities/SwiftAsyncContextAttr.h>
#include <multiplier/Entities/SwiftContextAttr.h>
#include <multiplier/Entities/SwiftErrorResultAttr.h>
#include <multiplier/Entities/SwiftIndirectResultAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UseHandleAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<InheritableParamAttr> InheritableParamAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = InheritableParamAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool InheritableParamAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : InheritableParamAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<InheritableParamAttr> InheritableParamAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return InheritableParamAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kInheritableParamAttrDerivedKinds[] = {
    NSConsumedAttr::static_kind(),
    NonNullAttr::static_kind(),
    OSConsumedAttr::static_kind(),
    PassObjectSizeAttr::static_kind(),
    ReleaseHandleAttr::static_kind(),
    UseHandleAttr::static_kind(),
    AnnotateAttr::static_kind(),
    CFConsumedAttr::static_kind(),
    CarriesDependencyAttr::static_kind(),
    SwiftAsyncContextAttr::static_kind(),
    SwiftContextAttr::static_kind(),
    SwiftErrorResultAttr::static_kind(),
    SwiftIndirectResultAttr::static_kind(),
};

std::optional<InheritableParamAttr> InheritableParamAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case NSConsumedAttr::static_kind():
    case NonNullAttr::static_kind():
    case OSConsumedAttr::static_kind():
    case PassObjectSizeAttr::static_kind():
    case ReleaseHandleAttr::static_kind():
    case UseHandleAttr::static_kind():
    case AnnotateAttr::static_kind():
    case CFConsumedAttr::static_kind():
    case CarriesDependencyAttr::static_kind():
    case SwiftAsyncContextAttr::static_kind():
    case SwiftContextAttr::static_kind():
    case SwiftErrorResultAttr::static_kind():
    case SwiftIndirectResultAttr::static_kind():
      return reinterpret_cast<const InheritableParamAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kInheritableParamAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<InheritableParamAttr> e = InheritableParamAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kInheritableParamAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<InheritableParamAttr> e = InheritableParamAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kInheritableParamAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<InheritableParamAttr> e = InheritableParamAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<InheritableParamAttr> InheritableParamAttr::from(const Reference &r) {
  return InheritableParamAttr::from(r.as_attribute());
}

std::optional<InheritableParamAttr> InheritableParamAttr::from(const TokenContext &t) {
  return InheritableParamAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
