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
class AddressSpaceAttr;
class Attr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AddressSpaceAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AddressSpaceAttr>;
class AddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static gap::generator<AddressSpaceAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static AddressSpaceAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AddressSpaceAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ADDRESS_SPACE;
  }

  static std::optional<AddressSpaceAttr> from(const TokenContext &c);
  static std::optional<AddressSpaceAttr> from(const TypeAttr &parent);

  inline static std::optional<AddressSpaceAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return AddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AddressSpaceAttr> from(const Attr &parent);

  inline static std::optional<AddressSpaceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AddressSpaceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(AddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
