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
class CFReturnsNotRetainedAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CFReturnsNotRetainedAttrRange = DerivedEntityRange<AttrIterator, CFReturnsNotRetainedAttr>;
using CFReturnsNotRetainedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CFReturnsNotRetainedAttr>;
class CFReturnsNotRetainedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static CFReturnsNotRetainedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CFReturnsNotRetainedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CFReturnsNotRetainedAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_RETURNS_NOT_RETAINED;
  }

  static std::optional<CFReturnsNotRetainedAttr> from(const TokenContext &c);
  static std::optional<CFReturnsNotRetainedAttr> from(const InheritableAttr &parent);

  inline static std::optional<CFReturnsNotRetainedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CFReturnsNotRetainedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFReturnsNotRetainedAttr> from(const Attr &parent);

  inline static std::optional<CFReturnsNotRetainedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFReturnsNotRetainedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CFReturnsNotRetainedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
