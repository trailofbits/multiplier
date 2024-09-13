// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OMPDeclareTargetDeclAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/Frontend/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const AttrKind kOMPDeclareTargetDeclAttrDerivedKinds[] = {
    OMPDeclareTargetDeclAttr::static_kind(),
};
}  // namespace

gap::generator<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kOMPDeclareTargetDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OMPDeclareTargetDeclAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOMPDeclareTargetDeclAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OMPDeclareTargetDeclAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOMPDeclareTargetDeclAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OMPDeclareTargetDeclAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OMPDeclareTargetDeclAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OMPDeclareTargetDeclAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OMPDeclareTargetDeclAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case OMPDeclareTargetDeclAttr::static_kind():
      return reinterpret_cast<const OMPDeclareTargetDeclAttr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::from(const Reference &r) {
  return OMPDeclareTargetDeclAttr::from(r.as_attribute());
}

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<OMPDeclareTargetDeclAttr> OMPDeclareTargetDeclAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

OMPDeclareTargetDeclAttrDevTypeTy OMPDeclareTargetDeclAttr::dev_type(void) const {
  return static_cast<OMPDeclareTargetDeclAttrDevTypeTy>(impl->reader.getVal13());
}

bool OMPDeclareTargetDeclAttr::indirect(void) const {
  return impl->reader.getVal15();
}

Expr OMPDeclareTargetDeclAttr::indirect_expression(void) const {
  RawEntityId eid = impl->reader.getVal10();
  return Expr::from_base(impl->ep->StmtFor(impl->ep, eid)).value();
}

uint32_t OMPDeclareTargetDeclAttr::level(void) const {
  return impl->reader.getVal12();
}

OMPDeclareTargetDeclAttrMapTypeTy OMPDeclareTargetDeclAttr::map_type(void) const {
  return static_cast<OMPDeclareTargetDeclAttrMapTypeTy>(impl->reader.getVal21());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
