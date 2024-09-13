// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenCLIntelReqdSubGroupSizeAttr.h>
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
static const AttrKind kOpenCLIntelReqdSubGroupSizeAttrDerivedKinds[] = {
    OpenCLIntelReqdSubGroupSizeAttr::static_kind(),
};
}  // namespace

gap::generator<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kOpenCLIntelReqdSubGroupSizeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<OpenCLIntelReqdSubGroupSizeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kOpenCLIntelReqdSubGroupSizeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<OpenCLIntelReqdSubGroupSizeAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kOpenCLIntelReqdSubGroupSizeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<OpenCLIntelReqdSubGroupSizeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = OpenCLIntelReqdSubGroupSizeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool OpenCLIntelReqdSubGroupSizeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : OpenCLIntelReqdSubGroupSizeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case OpenCLIntelReqdSubGroupSizeAttr::static_kind():
      return reinterpret_cast<const OpenCLIntelReqdSubGroupSizeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::from(const Reference &r) {
  return OpenCLIntelReqdSubGroupSizeAttr::from(r.as_attribute());
}

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<OpenCLIntelReqdSubGroupSizeAttr> OpenCLIntelReqdSubGroupSizeAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

uint32_t OpenCLIntelReqdSubGroupSizeAttr::sub_group_size(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
