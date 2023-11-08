// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeAttr.h>

#include <multiplier/Entities/AddressSpaceAttr.h>
#include <multiplier/Entities/AnnotateTypeAttr.h>
#include <multiplier/Entities/ArmMveStrictPolymorphismAttr.h>
#include <multiplier/Entities/ArmPreservesZAAttr.h>
#include <multiplier/Entities/ArmSharedZAAttr.h>
#include <multiplier/Entities/ArmStreamingAttr.h>
#include <multiplier/Entities/ArmStreamingCompatibleAttr.h>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/BTFTypeTagAttr.h>
#include <multiplier/Entities/CmseNSCallAttr.h>
#include <multiplier/Entities/HLSLGroupSharedAddressSpaceAttr.h>
#include <multiplier/Entities/NoDerefAttr.h>
#include <multiplier/Entities/ObjCGCAttr.h>
#include <multiplier/Entities/ObjCInertUnsafeUnretainedAttr.h>
#include <multiplier/Entities/ObjCKindOfAttr.h>
#include <multiplier/Entities/OpenCLConstantAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLGenericAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLGlobalAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLGlobalDeviceAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLGlobalHostAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLLocalAddressSpaceAttr.h>
#include <multiplier/Entities/OpenCLPrivateAddressSpaceAttr.h>
#include <multiplier/Entities/Ptr32Attr.h>
#include <multiplier/Entities/Ptr64Attr.h>
#include <multiplier/Entities/SPtrAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeNonNullAttr.h>
#include <multiplier/Entities/TypeNullUnspecifiedAttr.h>
#include <multiplier/Entities/TypeNullableAttr.h>
#include <multiplier/Entities/TypeNullableResultAttr.h>
#include <multiplier/Entities/UPtrAttr.h>
#include <multiplier/Entities/WebAssemblyFuncrefAttr.h>

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
    return TypeAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

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
    ArmPreservesZAAttr::static_kind(),
    ArmSharedZAAttr::static_kind(),
    ArmStreamingAttr::static_kind(),
    ArmStreamingCompatibleAttr::static_kind(),
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

std::optional<TypeAttr> TypeAttr::from(const Attr &parent) {
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
    case ArmPreservesZAAttr::static_kind():
    case ArmSharedZAAttr::static_kind():
    case ArmStreamingAttr::static_kind():
    case ArmStreamingCompatibleAttr::static_kind():
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
      if (std::optional<TypeAttr> e = TypeAttr::from(Attr(std::move(eptr)))) {
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
      if (std::optional<TypeAttr> e = TypeAttr::from(Attr(std::move(eptr)))) {
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
        if (std::optional<TypeAttr> e = TypeAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<TypeAttr> TypeAttr::from(const Reference &r) {
  return TypeAttr::from(r.as_attribute());
}

std::optional<TypeAttr> TypeAttr::from(const TokenContext &t) {
  return TypeAttr::from(t.as_attribute());
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
