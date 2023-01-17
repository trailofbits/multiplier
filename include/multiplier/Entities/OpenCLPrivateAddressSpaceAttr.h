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
#include "OpenCLPrivateAddressSpaceAttrSpelling.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class OpenCLPrivateAddressSpaceAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLPrivateAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static gap::generator<OpenCLPrivateAddressSpaceAttr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OpenCLPrivateAddressSpaceAttr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OpenCLPrivateAddressSpaceAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_PRIVATE_ADDRESS_SPACE;
  }

  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const TokenContext &c);
  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const TypeAttr &parent);

  inline static std::optional<OpenCLPrivateAddressSpaceAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return OpenCLPrivateAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLPrivateAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLPrivateAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLPrivateAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OpenCLPrivateAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLPrivateAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
