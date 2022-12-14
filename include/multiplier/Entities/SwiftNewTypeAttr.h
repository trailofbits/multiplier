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
#include "InheritableAttr.h"
#include "SwiftNewTypeAttrNewtypeKind.h"
#include "SwiftNewTypeAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class SwiftNewTypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SwiftNewTypeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwiftNewTypeAttr>;
class SwiftNewTypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<SwiftNewTypeAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static SwiftNewTypeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : SwiftNewTypeAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_NEW_TYPE;
  }

  static std::optional<SwiftNewTypeAttr> from(const TokenContext &c);
  static std::optional<SwiftNewTypeAttr> from(const InheritableAttr &parent);

  inline static std::optional<SwiftNewTypeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return SwiftNewTypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftNewTypeAttr> from(const Attr &parent);

  inline static std::optional<SwiftNewTypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftNewTypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  SwiftNewTypeAttrNewtypeKind newtype_kind(void) const;
  SwiftNewTypeAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(SwiftNewTypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
