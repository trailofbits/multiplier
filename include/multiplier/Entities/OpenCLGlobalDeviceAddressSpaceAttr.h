// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class OpenCLGlobalDeviceAddressSpaceAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OpenCLGlobalDeviceAddressSpaceAttrRange = DerivedEntityRange<AttrIterator, OpenCLGlobalDeviceAddressSpaceAttr>;
using OpenCLGlobalDeviceAddressSpaceAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OpenCLGlobalDeviceAddressSpaceAttr>;
class OpenCLGlobalDeviceAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static OpenCLGlobalDeviceAddressSpaceAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OpenCLGlobalDeviceAddressSpaceAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OpenCLGlobalDeviceAddressSpaceAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE;
  }

  static std::optional<OpenCLGlobalDeviceAddressSpaceAttr> from(const TokenContext &c);
  static std::optional<OpenCLGlobalDeviceAddressSpaceAttr> from(const TypeAttr &parent);

  inline static std::optional<OpenCLGlobalDeviceAddressSpaceAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return OpenCLGlobalDeviceAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLGlobalDeviceAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLGlobalDeviceAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLGlobalDeviceAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(OpenCLGlobalDeviceAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
