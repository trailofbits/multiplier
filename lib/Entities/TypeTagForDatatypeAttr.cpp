// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeTagForDatatypeAttr.h>

#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/InheritableAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/Type.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeTagForDatatypeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeTagForDatatypeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeTagForDatatypeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    return TypeTagForDatatypeAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const AttrKind kTypeTagForDatatypeAttrDerivedKinds[] = {
    TypeTagForDatatypeAttr::static_kind(),
};

std::optional<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::from(const Attr &parent) {
  switch (parent.kind()) {
    case TypeTagForDatatypeAttr::static_kind():
      return reinterpret_cast<const TypeTagForDatatypeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (AttrKind k : kTypeTagForDatatypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<TypeTagForDatatypeAttr> e = TypeTagForDatatypeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kTypeTagForDatatypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<TypeTagForDatatypeAttr> e = TypeTagForDatatypeAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kTypeTagForDatatypeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<TypeTagForDatatypeAttr> e = TypeTagForDatatypeAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::from(const Reference &r) {
  return TypeTagForDatatypeAttr::from(r.as_attribute());
}

std::optional<TypeTagForDatatypeAttr> TypeTagForDatatypeAttr::from(const TokenContext &t) {
  return TypeTagForDatatypeAttr::from(t.as_attribute());
}

bool TypeTagForDatatypeAttr::layout_compatible(void) const {
  return impl->reader.getVal12();
}

Type TypeTagForDatatypeAttr::matching_c_type(void) const {
  RawEntityId eid = impl->reader.getVal8();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

Type TypeTagForDatatypeAttr::matching_c_type_token(void) const {
  RawEntityId eid = impl->reader.getVal16();
  return Type(impl->ep->TypeFor(impl->ep, eid));
}

bool TypeTagForDatatypeAttr::must_be_null(void) const {
  return impl->reader.getVal13();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
