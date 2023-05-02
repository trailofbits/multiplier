// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AlwaysInlineAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/DeclOrStmtAttr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AlwaysInlineAttr> AlwaysInlineAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AlwaysInlineAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AlwaysInlineAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AlwaysInlineAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AlwaysInlineAttr> AlwaysInlineAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return AlwaysInlineAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kAlwaysInlineAttrDerivedKinds[] = {
    AlwaysInlineAttr::static_kind(),
};

std::optional<AlwaysInlineAttr> AlwaysInlineAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case AlwaysInlineAttr::static_kind():
      return reinterpret_cast<const AlwaysInlineAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AlwaysInlineAttr> AlwaysInlineAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kAlwaysInlineAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AlwaysInlineAttr> e = AlwaysInlineAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AlwaysInlineAttr> AlwaysInlineAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAlwaysInlineAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AlwaysInlineAttr> e = AlwaysInlineAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AlwaysInlineAttr> AlwaysInlineAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAlwaysInlineAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AlwaysInlineAttr> e = AlwaysInlineAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AlwaysInlineAttr> AlwaysInlineAttr::from(const Reference &r) {
  return AlwaysInlineAttr::from(r.as_attribute());
}

std::optional<AlwaysInlineAttr> AlwaysInlineAttr::from(const TokenContext &t) {
  return AlwaysInlineAttr::from(t.as_attribute());
}

AlwaysInlineAttrSpelling AlwaysInlineAttr::semantic_spelling(void) const {
  return static_cast<AlwaysInlineAttrSpelling>(impl->reader.getVal10());
}

bool AlwaysInlineAttr::is_clang_always_inline(void) const {
  return impl->reader.getVal12();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
