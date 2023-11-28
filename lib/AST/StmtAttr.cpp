// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StmtAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/FallThroughAttr.h>
#include <multiplier/AST/LikelyAttr.h>
#include <multiplier/AST/MustTailAttr.h>
#include <multiplier/AST/OpenCLUnrollHintAttr.h>
#include <multiplier/AST/SuppressAttr.h>
#include <multiplier/AST/UnlikelyAttr.h>

#include "../EntityProvider.h"
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
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<StmtAttr> StmtAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kStmtAttrDerivedKinds[] = {
    SuppressAttr::static_kind(),
    UnlikelyAttr::static_kind(),
    FallThroughAttr::static_kind(),
    LikelyAttr::static_kind(),
    MustTailAttr::static_kind(),
    OpenCLUnrollHintAttr::static_kind(),
};

}  // namespace

std::optional<StmtAttr> StmtAttr::from_base(const Attr &parent) {
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
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kStmtAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<StmtAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtAttr> StmtAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kStmtAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<StmtAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<StmtAttr> StmtAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kStmtAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<StmtAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<StmtAttr> StmtAttr::from(const Reference &r) {
  return StmtAttr::from(r.as_attribute());
}

std::optional<StmtAttr> StmtAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<StmtAttr> StmtAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
