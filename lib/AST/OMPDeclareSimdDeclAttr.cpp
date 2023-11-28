// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPDeclareSimdDeclAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
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
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kOMPDeclareSimdDeclAttrDerivedKinds[] = {
    OMPDeclareSimdDeclAttr::static_kind(),
};

}  // namespace

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case OMPDeclareSimdDeclAttr::static_kind():
      return reinterpret_cast<const OMPDeclareSimdDeclAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OMPDeclareSimdDeclAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareSimdDeclAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOMPDeclareSimdDeclAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareSimdDeclAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const Reference &r) {
  return OMPDeclareSimdDeclAttr::from(r.as_attribute());
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<OMPDeclareSimdDeclAttr> OMPDeclareSimdDeclAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

OMPDeclareSimdDeclAttrBranchStateTy OMPDeclareSimdDeclAttr::branch_state(void) const {
  return static_cast<OMPDeclareSimdDeclAttrBranchStateTy>(impl->reader.getVal10());
}

Expr OMPDeclareSimdDeclAttr::simdlen(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
