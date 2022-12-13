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
#include "SwiftAsyncErrorAttrConventionKind.h"

namespace mx {
class Attr;
class InheritableAttr;
class SwiftAsyncErrorAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SwiftAsyncErrorAttrRange = DerivedEntityRange<AttrIterator, SwiftAsyncErrorAttr>;
using SwiftAsyncErrorAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwiftAsyncErrorAttr>;
class SwiftAsyncErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static SwiftAsyncErrorAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SwiftAsyncErrorAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : SwiftAsyncErrorAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_ERROR;
  }

  static std::optional<SwiftAsyncErrorAttr> from(const TokenContext &c);
  static std::optional<SwiftAsyncErrorAttr> from(const InheritableAttr &parent);

  inline static std::optional<SwiftAsyncErrorAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return SwiftAsyncErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncErrorAttr> from(const Attr &parent);

  inline static std::optional<SwiftAsyncErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAsyncErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  SwiftAsyncErrorAttrConventionKind convention(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(SwiftAsyncErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
