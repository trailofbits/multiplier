// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AlignedAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<AlignedAttr> AlignedAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = AlignedAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool AlignedAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : AlignedAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<AlignedAttr> AlignedAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return AlignedAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kAlignedAttrDerivedKinds[] = {
    AlignedAttr::static_kind(),
};

std::optional<AlignedAttr> AlignedAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case AlignedAttr::static_kind():
      return reinterpret_cast<const AlignedAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<AlignedAttr> AlignedAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kAlignedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<AlignedAttr> e = AlignedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AlignedAttr> AlignedAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kAlignedAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<AlignedAttr> e = AlignedAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<AlignedAttr> AlignedAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kAlignedAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<AlignedAttr> e = AlignedAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<AlignedAttr> AlignedAttr::from(const Reference &r) {
  return AlignedAttr::from(r.as_attribute());
}

std::optional<AlignedAttr> AlignedAttr::from(const TokenContext &t) {
  return AlignedAttr::from(t.as_attribute());
}

std::optional<Expr> AlignedAttr::alignment_expression(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal8();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

std::optional<Type> AlignedAttr::alignment_type(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal16();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->TypeFor(impl->ep, eid)) {
      return Type(std::move(eptr));
    }
  }
  return std::nullopt;
}

std::optional<uint32_t> AlignedAttr::cached_alignment_value(void) const {
  if (!impl->reader.getVal12()) {
    return std::nullopt;
  } else {
    return static_cast<uint32_t>(impl->reader.getVal20());
  }
  return std::nullopt;
}

AlignedAttrSpelling AlignedAttr::semantic_spelling(void) const {
  return static_cast<AlignedAttrSpelling>(impl->reader.getVal10());
}

bool AlignedAttr::is_alignas(void) const {
  return impl->reader.getVal13();
}

bool AlignedAttr::is_alignment_dependent(void) const {
  return impl->reader.getVal19();
}

bool AlignedAttr::is_alignment_error_dependent(void) const {
  return impl->reader.getVal21();
}

bool AlignedAttr::is_alignment_expression(void) const {
  return impl->reader.getVal22();
}

bool AlignedAttr::is_c11(void) const {
  return impl->reader.getVal23();
}

bool AlignedAttr::is_declspec(void) const {
  return impl->reader.getVal24();
}

bool AlignedAttr::is_gnu(void) const {
  return impl->reader.getVal25();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
