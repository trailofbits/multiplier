// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SwiftNewTypeAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const AttrKind kSwiftNewTypeAttrDerivedKinds[] = {
    SwiftNewTypeAttr::static_kind(),
};
}  // namespace

gap::generator<SwiftNewTypeAttr> SwiftNewTypeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = SwiftNewTypeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool SwiftNewTypeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : SwiftNewTypeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case SwiftNewTypeAttr::static_kind():
      return reinterpret_cast<const SwiftNewTypeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<SwiftNewTypeAttr> SwiftNewTypeAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kSwiftNewTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<SwiftNewTypeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwiftNewTypeAttr> SwiftNewTypeAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kSwiftNewTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<SwiftNewTypeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<SwiftNewTypeAttr> SwiftNewTypeAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kSwiftNewTypeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<SwiftNewTypeAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::from(const Reference &r) {
  return SwiftNewTypeAttr::from(r.as_attribute());
}

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<SwiftNewTypeAttr> SwiftNewTypeAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

SwiftNewTypeAttrNewtypeKind SwiftNewTypeAttr::newtype_kind(void) const {
  return static_cast<SwiftNewTypeAttrNewtypeKind>(impl->reader.getVal10());
}

SwiftNewTypeAttrSpelling SwiftNewTypeAttr::semantic_spelling(void) const {
  return static_cast<SwiftNewTypeAttrSpelling>(impl->reader.getVal14());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
