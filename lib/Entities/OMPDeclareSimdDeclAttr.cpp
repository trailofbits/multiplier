// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OMPDeclareSimdDeclAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclareSimdDeclAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclareSimdDeclAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclareSimdDeclAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return OMPDeclareSimdDeclAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kOMPDeclareSimdDeclAttrDerivedKinds[] = {
    OMPDeclareSimdDeclAttr::static_kind(),
};

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case OMPDeclareSimdDeclAttr::static_kind():
      return reinterpret_cast<const OMPDeclareSimdDeclAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OMPDeclareSimdDeclAttr> e = OMPDeclareSimdDeclAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareSimdDeclAttr> e = OMPDeclareSimdDeclAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareSimdDeclAttr> e = OMPDeclareSimdDeclAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const Reference &r) {
  return OMPDeclareSimdDeclAttr::from(r.as_attribute());
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const TokenContext &t) {
  return OMPDeclareSimdDeclAttr::from(t.as_attribute());
}

OMPDeclareSimdDeclAttrBranchStateTy OMPDeclareSimdDeclAttr::branch_state(void) const {
  return static_cast<OMPDeclareSimdDeclAttrBranchStateTy>(impl->reader.getVal10());
}

Expr OMPDeclareSimdDeclAttr::simdlen(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Expr::from(Stmt(impl->ep->StmtFor(impl->ep, eid))).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
