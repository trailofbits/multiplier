// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExternalSourceSymbolAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ExternalSourceSymbolAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ExternalSourceSymbolAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ExternalSourceSymbolAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return ExternalSourceSymbolAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kExternalSourceSymbolAttrDerivedKinds[] = {
    ExternalSourceSymbolAttr::static_kind(),
};

std::optional<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case ExternalSourceSymbolAttr::static_kind():
      return reinterpret_cast<const ExternalSourceSymbolAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kExternalSourceSymbolAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<ExternalSourceSymbolAttr> e = ExternalSourceSymbolAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kExternalSourceSymbolAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<ExternalSourceSymbolAttr> e = ExternalSourceSymbolAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kExternalSourceSymbolAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<ExternalSourceSymbolAttr> e = ExternalSourceSymbolAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::from(const Reference &r) {
  return ExternalSourceSymbolAttr::from(r.as_attribute());
}

std::optional<ExternalSourceSymbolAttr> ExternalSourceSymbolAttr::from(const TokenContext &t) {
  return ExternalSourceSymbolAttr::from(t.as_attribute());
}

std::string_view ExternalSourceSymbolAttr::defined_in(void) const {
  capnp::Text::Reader data = impl->reader.getVal9();
  return std::string_view(data.cStr(), data.size());
}

bool ExternalSourceSymbolAttr::generated_declaration(void) const {
  return impl->reader.getVal12();
}

std::string_view ExternalSourceSymbolAttr::language(void) const {
  capnp::Text::Reader data = impl->reader.getVal17();
  return std::string_view(data.cStr(), data.size());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
