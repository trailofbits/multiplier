// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SwiftAttrAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAttrAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAttrAttr> in(const Fragment &frag);
  static gap::generator<SwiftAttrAttr> in(const File &file);
  static gap::generator<SwiftAttrAttr> in(const Index &index);
  static gap::generator<SwiftAttrAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAttrAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ATTR;
  }

  static std::optional<SwiftAttrAttr> from(const Attr &parent);

  inline static std::optional<SwiftAttrAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAttrAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAttrAttr> from(const Reference &r);
  static std::optional<SwiftAttrAttr> from(const TokenContext &t);

  std::string_view attribute(void) const;
};

static_assert(sizeof(SwiftAttrAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
