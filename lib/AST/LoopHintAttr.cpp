// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LoopHintAttr.h>

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/Expr.h>
#include <multiplier/AST/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<LoopHintAttr> LoopHintAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = LoopHintAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool LoopHintAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : LoopHintAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<LoopHintAttr> LoopHintAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<LoopHintAttr> LoopHintAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kLoopHintAttrDerivedKinds[] = {
    LoopHintAttr::static_kind(),
};

}  // namespace

std::optional<LoopHintAttr> LoopHintAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case LoopHintAttr::static_kind():
      return reinterpret_cast<const LoopHintAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<LoopHintAttr> LoopHintAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kLoopHintAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<LoopHintAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LoopHintAttr> LoopHintAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kLoopHintAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<LoopHintAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<LoopHintAttr> LoopHintAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kLoopHintAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<LoopHintAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<LoopHintAttr> LoopHintAttr::from(const Reference &r) {
  return LoopHintAttr::from(r.as_attribute());
}

std::optional<LoopHintAttr> LoopHintAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<LoopHintAttr> LoopHintAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

LoopHintAttrOptionType LoopHintAttr::option(void) const {
  return static_cast<LoopHintAttrOptionType>(impl->reader.getVal10());
}

LoopHintAttrSpelling LoopHintAttr::semantic_spelling(void) const {
  return static_cast<LoopHintAttrSpelling>(impl->reader.getVal14());
}

LoopHintAttrLoopHintState LoopHintAttr::state(void) const {
  return static_cast<LoopHintAttrLoopHintState>(impl->reader.getVal15());
}

std::optional<Expr> LoopHintAttr::value(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from_base(std::move(eptr));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
