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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "OpenCLGenericAddressSpaceAttrSpelling.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class OpenCLGenericAddressSpaceAttr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLGenericAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLGenericAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLGenericAddressSpaceAttr> in(const File &file);
  static gap::generator<OpenCLGenericAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLGenericAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLGenericAddressSpaceAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_GENERIC_ADDRESS_SPACE;
  }

  static std::optional<OpenCLGenericAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLGenericAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLGenericAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OpenCLGenericAddressSpaceAttr> from(const Reference &r) {
    return OpenCLGenericAddressSpaceAttr::from(r.as_attribute());
  }

  inline static std::optional<OpenCLGenericAddressSpaceAttr> from(const TokenContext &t) {
    return OpenCLGenericAddressSpaceAttr::from(t.as_attribute());
  }

  OpenCLGenericAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLGenericAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
