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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class OpenCLGlobalHostAddressSpaceAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OpenCLGlobalHostAddressSpaceAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OpenCLGlobalHostAddressSpaceAttr>;
class OpenCLGlobalHostAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static gap::generator<OpenCLGlobalHostAddressSpaceAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static OpenCLGlobalHostAddressSpaceAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OpenCLGlobalHostAddressSpaceAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE;
  }

  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const TokenContext &c);
  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const TypeAttr &parent);

  inline static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return OpenCLGlobalHostAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLGlobalHostAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLGlobalHostAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(OpenCLGlobalHostAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
