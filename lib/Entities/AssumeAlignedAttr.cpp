// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AssumeAlignedAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AssumeAlignedAttr> AssumeAlignedAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AssumeAlignedAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AssumeAlignedAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AssumeAlignedAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AssumeAlignedAttr> AssumeAlignedAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return AssumeAlignedAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kAssumeAlignedAttrDerivedKinds[] = {
    AssumeAlignedAttr::static_kind(),
};

std::optional<AssumeAlignedAttr> AssumeAlignedAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case AssumeAlignedAttr::static_kind():
      return reinterpret_cast<const AssumeAlignedAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AssumeAlignedAttr> AssumeAlignedAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kAssumeAlignedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AssumeAlignedAttr> e = AssumeAlignedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AssumeAlignedAttr> AssumeAlignedAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAssumeAlignedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AssumeAlignedAttr> e = AssumeAlignedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AssumeAlignedAttr> AssumeAlignedAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAssumeAlignedAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AssumeAlignedAttr> e = AssumeAlignedAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AssumeAlignedAttr> AssumeAlignedAttr::from(const Reference &r) {
  return AssumeAlignedAttr::from(r.as_attribute());
}

std::optional<AssumeAlignedAttr> AssumeAlignedAttr::from(const TokenContext &t) {
  return AssumeAlignedAttr::from(t.as_attribute());
}

Expr AssumeAlignedAttr::alignment(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

std::optional<Expr> AssumeAlignedAttr::offset(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal16();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
