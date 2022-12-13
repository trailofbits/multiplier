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
#include "OpenCLConstantAddressSpaceAttrSpelling.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class OpenCLConstantAddressSpaceAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OpenCLConstantAddressSpaceAttrRange = DerivedEntityRange<AttrIterator, OpenCLConstantAddressSpaceAttr>;
using OpenCLConstantAddressSpaceAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OpenCLConstantAddressSpaceAttr>;
class OpenCLConstantAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static OpenCLConstantAddressSpaceAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OpenCLConstantAddressSpaceAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OpenCLConstantAddressSpaceAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_CONSTANT_ADDRESS_SPACE;
  }

  static std::optional<OpenCLConstantAddressSpaceAttr> from(const TokenContext &c);
  static std::optional<OpenCLConstantAddressSpaceAttr> from(const TypeAttr &parent);

  inline static std::optional<OpenCLConstantAddressSpaceAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return OpenCLConstantAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OpenCLConstantAddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<OpenCLConstantAddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OpenCLConstantAddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OpenCLConstantAddressSpaceAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(OpenCLConstantAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
