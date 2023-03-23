// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class AddressSpaceAttr;
class AnnotateTypeAttr;
class ArmMveStrictPolymorphismAttr;
class Attr;
class BTFTypeTagAttr;
class CmseNSCallAttr;
class HLSLGroupSharedAddressSpaceAttr;
class NoDerefAttr;
class ObjCGCAttr;
class ObjCInertUnsafeUnretainedAttr;
class ObjCKindOfAttr;
class OpenCLConstantAddressSpaceAttr;
class OpenCLGenericAddressSpaceAttr;
class OpenCLGlobalAddressSpaceAttr;
class OpenCLGlobalDeviceAddressSpaceAttr;
class OpenCLGlobalHostAddressSpaceAttr;
class OpenCLLocalAddressSpaceAttr;
class OpenCLPrivateAddressSpaceAttr;
class Ptr32Attr;
class Ptr64Attr;
class SPtrAttr;
class Token;
class TypeAttr;
class TypeNonNullAttr;
class TypeNullUnspecifiedAttr;
class TypeNullableAttr;
class TypeNullableResultAttr;
class UPtrAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<TypeAttr> in(const Fragment &frag);
  static gap::generator<TypeAttr> in(const File &file);
  static gap::generator<TypeAttr> in(const Index &index);
  static gap::generator<TypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeAttr> by_id(const Index &, EntityId);

  static std::optional<TypeAttr> from(const Attr &parent);

  inline static std::optional<TypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAttr> from(const Reference &r);
  static std::optional<TypeAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeAttr) == sizeof(Attr));

#endif
} // namespace mx
