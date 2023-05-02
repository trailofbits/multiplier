// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BlocksAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<BlocksAttr> BlocksAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = BlocksAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool BlocksAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : BlocksAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<BlocksAttr> BlocksAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return BlocksAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kBlocksAttrDerivedKinds[] = {
    BlocksAttr::static_kind(),
};

std::optional<BlocksAttr> BlocksAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case BlocksAttr::static_kind():
      return reinterpret_cast<const BlocksAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<BlocksAttr> BlocksAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kBlocksAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<BlocksAttr> e = BlocksAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlocksAttr> BlocksAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kBlocksAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<BlocksAttr> e = BlocksAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<BlocksAttr> BlocksAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kBlocksAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<BlocksAttr> e = BlocksAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<BlocksAttr> BlocksAttr::from(const Reference &r) {
  return BlocksAttr::from(r.as_attribute());
}

std::optional<BlocksAttr> BlocksAttr::from(const TokenContext &t) {
  return BlocksAttr::from(t.as_attribute());
}

BlocksAttrBlockType BlocksAttr::type(void) const {
  return static_cast<BlocksAttrBlockType>(impl->reader.getVal10());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
