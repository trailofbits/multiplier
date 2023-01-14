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
class NSReturnsAutoreleasedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NSReturnsAutoreleasedAttrRange = DerivedEntityRange<AttrIterator, NSReturnsAutoreleasedAttr>;
using NSReturnsAutoreleasedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NSReturnsAutoreleasedAttr>;
class NSReturnsAutoreleasedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NSReturnsAutoreleasedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NSReturnsAutoreleasedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NSReturnsAutoreleasedAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_RETURNS_AUTORELEASED;
  }

  static std::optional<NSReturnsAutoreleasedAttr> from(const TokenContext &c);
  static std::optional<NSReturnsAutoreleasedAttr> from(const InheritableAttr &parent);

  inline static std::optional<NSReturnsAutoreleasedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NSReturnsAutoreleasedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSReturnsAutoreleasedAttr> from(const Attr &parent);

  inline static std::optional<NSReturnsAutoreleasedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSReturnsAutoreleasedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(NSReturnsAutoreleasedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
