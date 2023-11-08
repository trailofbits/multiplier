// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NSErrorDomainAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/VarDecl.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<NSErrorDomainAttr> NSErrorDomainAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = NSErrorDomainAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool NSErrorDomainAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : NSErrorDomainAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<NSErrorDomainAttr> NSErrorDomainAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return NSErrorDomainAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kNSErrorDomainAttrDerivedKinds[] = {
    NSErrorDomainAttr::static_kind(),
};

std::optional<NSErrorDomainAttr> NSErrorDomainAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case NSErrorDomainAttr::static_kind():
      return reinterpret_cast<const NSErrorDomainAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<NSErrorDomainAttr> NSErrorDomainAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kNSErrorDomainAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<NSErrorDomainAttr> e = NSErrorDomainAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NSErrorDomainAttr> NSErrorDomainAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kNSErrorDomainAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<NSErrorDomainAttr> e = NSErrorDomainAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<NSErrorDomainAttr> NSErrorDomainAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kNSErrorDomainAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<NSErrorDomainAttr> e = NSErrorDomainAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<NSErrorDomainAttr> NSErrorDomainAttr::from(const Reference &r) {
  return NSErrorDomainAttr::from(r.as_attribute());
}

std::optional<NSErrorDomainAttr> NSErrorDomainAttr::from(const TokenContext &t) {
  return NSErrorDomainAttr::from(t.as_attribute());
}

VarDecl NSErrorDomainAttr::error_domain(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return VarDecl::from(Decl(impl->ep->DeclFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
