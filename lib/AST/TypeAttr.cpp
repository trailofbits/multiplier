// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/AddressSpaceAttr.h>
#include <multiplier/AST/AnnotateTypeAttr.h>
#include <multiplier/AST/ArmMveStrictPolymorphismAttr.h>
#include <multiplier/AST/ArmStreamingAttr.h>
#include <multiplier/AST/BTFTypeTagAttr.h>
#include <multiplier/AST/CmseNSCallAttr.h>
#include <multiplier/AST/HLSLGroupSharedAddressSpaceAttr.h>
#include <multiplier/AST/NoDerefAttr.h>
#include <multiplier/AST/ObjCGCAttr.h>
#include <multiplier/AST/ObjCInertUnsafeUnretainedAttr.h>
#include <multiplier/AST/ObjCKindOfAttr.h>
#include <multiplier/AST/OpenCLConstantAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLGenericAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLGlobalAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLGlobalDeviceAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLGlobalHostAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLLocalAddressSpaceAttr.h>
#include <multiplier/AST/OpenCLPrivateAddressSpaceAttr.h>
#include <multiplier/AST/Ptr32Attr.h>
#include <multiplier/AST/Ptr64Attr.h>
#include <multiplier/AST/SPtrAttr.h>
#include <multiplier/AST/TypeNonNullAttr.h>
#include <multiplier/AST/TypeNullUnspecifiedAttr.h>
#include <multiplier/AST/TypeNullableAttr.h>
#include <multiplier/AST/TypeNullableResultAttr.h>
#include <multiplier/AST/UPtrAttr.h>
#include <multiplier/AST/WebAssemblyFuncrefAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<TypeAttr> TypeAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = TypeAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool TypeAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : TypeAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<TypeAttr> TypeAttr::by_id(const Index &index, EntityId eid) {
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

std::optional<TypeAttr> TypeAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

namespace {
static const AttrKind kTypeAttrDerivedKinds[] = {
    TypeNonNullAttr::static_kind(),
    TypeNullUnspecifiedAttr::static_kind(),
    TypeNullableAttr::static_kind(),
    TypeNullableResultAttr::static_kind(),
    UPtrAttr::static_kind(),
    WebAssemblyFuncrefAttr::static_kind(),
    AddressSpaceAttr::static_kind(),
    AnnotateTypeAttr::static_kind(),
    ArmMveStrictPolymorphismAttr::static_kind(),
    ArmStreamingAttr::static_kind(),
    BTFTypeTagAttr::static_kind(),
    CmseNSCallAttr::static_kind(),
    HLSLGroupSharedAddressSpaceAttr::static_kind(),
    NoDerefAttr::static_kind(),
    ObjCGCAttr::static_kind(),
    ObjCInertUnsafeUnretainedAttr::static_kind(),
    ObjCKindOfAttr::static_kind(),
    OpenCLConstantAddressSpaceAttr::static_kind(),
    OpenCLGenericAddressSpaceAttr::static_kind(),
    OpenCLGlobalAddressSpaceAttr::static_kind(),
    OpenCLGlobalDeviceAddressSpaceAttr::static_kind(),
    OpenCLGlobalHostAddressSpaceAttr::static_kind(),
    OpenCLLocalAddressSpaceAttr::static_kind(),
    OpenCLPrivateAddressSpaceAttr::static_kind(),
    Ptr32Attr::static_kind(),
    Ptr64Attr::static_kind(),
    SPtrAttr::static_kind(),
};

}  // namespace

std::optional<TypeAttr> TypeAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case TypeNonNullAttr::static_kind():
    case TypeNullUnspecifiedAttr::static_kind():
    case TypeNullableAttr::static_kind():
    case TypeNullableResultAttr::static_kind():
    case UPtrAttr::static_kind():
    case WebAssemblyFuncrefAttr::static_kind():
    case AddressSpaceAttr::static_kind():
    case AnnotateTypeAttr::static_kind():
    case ArmMveStrictPolymorphismAttr::static_kind():
    case ArmStreamingAttr::static_kind():
    case BTFTypeTagAttr::static_kind():
    case CmseNSCallAttr::static_kind():
    case HLSLGroupSharedAddressSpaceAttr::static_kind():
    case NoDerefAttr::static_kind():
    case ObjCGCAttr::static_kind():
    case ObjCInertUnsafeUnretainedAttr::static_kind():
    case ObjCKindOfAttr::static_kind():
    case OpenCLConstantAddressSpaceAttr::static_kind():
    case OpenCLGenericAddressSpaceAttr::static_kind():
    case OpenCLGlobalAddressSpaceAttr::static_kind():
    case OpenCLGlobalDeviceAddressSpaceAttr::static_kind():
    case OpenCLGlobalHostAddressSpaceAttr::static_kind():
    case OpenCLLocalAddressSpaceAttr::static_kind():
    case OpenCLPrivateAddressSpaceAttr::static_kind():
    case Ptr32Attr::static_kind():
    case Ptr64Attr::static_kind():
    case SPtrAttr::static_kind():
      return reinterpret_cast<const TypeAttr &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<TypeAttr> TypeAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<TypeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAttr> TypeAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kTypeAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<TypeAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<TypeAttr> TypeAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kTypeAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<TypeAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeAttr> TypeAttr::from(const Reference &r) {
  return TypeAttr::from(r.as_attribute());
}

std::optional<TypeAttr> TypeAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<TypeAttr> TypeAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
