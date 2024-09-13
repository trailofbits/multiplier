// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InheritableParamAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/AnnotateAttr.h>
#include <multiplier/AST/CFConsumedAttr.h>
#include <multiplier/AST/CarriesDependencyAttr.h>
#include <multiplier/AST/NSConsumedAttr.h>
#include <multiplier/AST/NonNullAttr.h>
#include <multiplier/AST/OSConsumedAttr.h>
#include <multiplier/AST/PassObjectSizeAttr.h>
#include <multiplier/AST/ReleaseHandleAttr.h>
#include <multiplier/AST/SwiftAsyncContextAttr.h>
#include <multiplier/AST/SwiftContextAttr.h>
#include <multiplier/AST/SwiftErrorResultAttr.h>
#include <multiplier/AST/SwiftIndirectResultAttr.h>
#include <multiplier/AST/UseHandleAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
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
}  // namespace

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kInheritableParamAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<InheritableParamAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kInheritableParamAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<InheritableParamAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<InheritableParamAttr> InheritableParamAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kInheritableParamAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<InheritableParamAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

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
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<InheritableParamAttr> InheritableParamAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<InheritableParamAttr> InheritableParamAttr::from_base(const Attr &parent) {
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

std::optional<InheritableParamAttr> InheritableParamAttr::from(const Reference &r) {
  return InheritableParamAttr::from(r.as_attribute());
}

std::optional<InheritableParamAttr> InheritableParamAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<InheritableParamAttr> InheritableParamAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
