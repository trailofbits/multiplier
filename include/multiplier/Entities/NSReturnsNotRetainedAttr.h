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
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class NSReturnsNotRetainedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NSReturnsNotRetainedAttrRange = DerivedEntityRange<AttrIterator, NSReturnsNotRetainedAttr>;
using NSReturnsNotRetainedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NSReturnsNotRetainedAttr>;
class NSReturnsNotRetainedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NSReturnsNotRetainedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NSReturnsNotRetainedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : NSReturnsNotRetainedAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_RETURNS_NOT_RETAINED;
  }

  static std::optional<NSReturnsNotRetainedAttr> from(const TokenContext &c);
  static std::optional<NSReturnsNotRetainedAttr> from(const InheritableAttr &parent);

  inline static std::optional<NSReturnsNotRetainedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NSReturnsNotRetainedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSReturnsNotRetainedAttr> from(const Attr &parent);

  inline static std::optional<NSReturnsNotRetainedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSReturnsNotRetainedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NSReturnsNotRetainedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
