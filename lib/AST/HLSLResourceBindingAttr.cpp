// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/HLSLResourceBindingAttr.h>
#include <multiplier/AST/Attr.h>
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
static const AttrKind kHLSLResourceBindingAttrDerivedKinds[] = {
    HLSLResourceBindingAttr::static_kind(),
};
}  // namespace

gap::generator<HLSLResourceBindingAttr> HLSLResourceBindingAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kHLSLResourceBindingAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<HLSLResourceBindingAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLResourceBindingAttr> HLSLResourceBindingAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kHLSLResourceBindingAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<HLSLResourceBindingAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<HLSLResourceBindingAttr> HLSLResourceBindingAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kHLSLResourceBindingAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<HLSLResourceBindingAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<HLSLResourceBindingAttr> HLSLResourceBindingAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = HLSLResourceBindingAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool HLSLResourceBindingAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : HLSLResourceBindingAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case HLSLResourceBindingAttr::static_kind():
      return reinterpret_cast<const HLSLResourceBindingAttr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::from(const Reference &r) {
  return HLSLResourceBindingAttr::from(r.as_attribute());
}

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<HLSLResourceBindingAttr> HLSLResourceBindingAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

std::string_view HLSLResourceBindingAttr::slot(void) const {
  capnp::Text::Reader data = impl->reader.getVal11();
  return std::string_view(data.cStr(), data.size());
}

uint32_t HLSLResourceBindingAttr::slot_length(void) const {
  return impl->reader.getVal12();
}

std::string_view HLSLResourceBindingAttr::space(void) const {
  capnp::Text::Reader data = impl->reader.getVal24();
  return std::string_view(data.cStr(), data.size());
}

uint32_t HLSLResourceBindingAttr::space_length(void) const {
  return impl->reader.getVal25();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
