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
class Ptr32Attr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using Ptr32AttrRange = DerivedEntityRange<AttrIterator, Ptr32Attr>;
using Ptr32AttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, Ptr32Attr>;
class Ptr32Attr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static Ptr32AttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static Ptr32AttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : Ptr32Attr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PTR32;
  }

  static std::optional<Ptr32Attr> from(const TokenContext &c);
  static std::optional<Ptr32Attr> from(const TypeAttr &parent);

  inline static std::optional<Ptr32Attr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return Ptr32Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<Ptr32Attr> from(const Attr &parent);

  inline static std::optional<Ptr32Attr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return Ptr32Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(Ptr32Attr) == sizeof(TypeAttr));

#endif
} // namespace mx
