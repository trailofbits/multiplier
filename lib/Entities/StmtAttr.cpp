// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/StmtAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/FallThroughAttr.h>
#include <multiplier/Entities/LikelyAttr.h>
#include <multiplier/Entities/MustTailAttr.h>
#include <multiplier/Entities/OpenCLUnrollHintAttr.h>
#include <multiplier/Entities/SuppressAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/UnlikelyAttr.h>

#include "../API.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<StmtAttr> StmtAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = StmtAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool StmtAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : StmtAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<StmtAttr> StmtAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return StmtAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kStmtAttrDerivedKinds[] = {
    SuppressAttr::static_kind(),
    UnlikelyAttr::static_kind(),
    FallThroughAttr::static_kind(),
    LikelyAttr::static_kind(),
    MustTailAttr::static_kind(),
    OpenCLUnrollHintAttr::static_kind(),
};

std::optional<StmtAttr> StmtAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case SuppressAttr::static_kind():
    case UnlikelyAttr::static_kind():
    case FallThroughAttr::static_kind():
    case LikelyAttr::static_kind():
    case MustTailAttr::static_kind():
    case OpenCLUnrollHintAttr::static_kind():
      return reinterpret_cast<const StmtAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<StmtAttr> StmtAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kStmtAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<StmtAttr> e = StmtAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtAttr> StmtAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kStmtAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<StmtAttr> e = StmtAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtAttr> StmtAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kStmtAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<StmtAttr> e = StmtAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<StmtAttr> StmtAttr::from(const Reference &r) {
  return StmtAttr::from(r.as_attribute());
}

std::optional<StmtAttr> StmtAttr::from(const TokenContext &t) {
  return StmtAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
