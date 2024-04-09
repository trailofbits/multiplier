// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/HLSLParamModifierAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/TypeAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const AttrKind kHLSLParamModifierAttrDerivedKinds[] = {
    HLSLParamModifierAttr::static_kind(),
};
}  // namespace

gap::generator<HLSLParamModifierAttr> HLSLParamModifierAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLParamModifierAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLParamModifierAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLParamModifierAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLParamModifierAttr::static_kind():
      return reinterpret_cast<const HLSLParamModifierAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<HLSLParamModifierAttr> HLSLParamModifierAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLParamModifierAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLParamModifierAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLParamModifierAttr> HLSLParamModifierAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLParamModifierAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLParamModifierAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLParamModifierAttr> HLSLParamModifierAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLParamModifierAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLParamModifierAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::from(const Reference &r) {
  return HLSLParamModifierAttr::from(r.as_attribute());
}

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<HLSLParamModifierAttr> HLSLParamModifierAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool HLSLParamModifierAttr::merged_spelling(void) const {
  return impl->reader.getVal11();
}

HLSLParamModifierAttrSpelling HLSLParamModifierAttr::semantic_spelling(void) const {
  return static_cast<HLSLParamModifierAttrSpelling>(impl->reader.getVal10());
}

bool HLSLParamModifierAttr::is_any_in(void) const {
  return impl->reader.getVal12();
}

bool HLSLParamModifierAttr::is_any_out(void) const {
  return impl->reader.getVal13();
}

bool HLSLParamModifierAttr::is_in(void) const {
  return impl->reader.getVal14();
}

bool HLSLParamModifierAttr::is_in_out(void) const {
  return impl->reader.getVal15();
}

bool HLSLParamModifierAttr::is_out(void) const {
  return impl->reader.getVal16();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx