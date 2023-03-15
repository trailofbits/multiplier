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
class SwiftBridgeAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftBridgeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftBridgeAttr> in(const Fragment &frag);
  static gap::generator<SwiftBridgeAttr> in(const File &file);
  static gap::generator<SwiftBridgeAttr> in(const Index &index);
  static gap::generator<SwiftBridgeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftBridgeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_BRIDGE;
  }

  static std::optional<SwiftBridgeAttr> from(const Attr &parent);

  inline static std::optional<SwiftBridgeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftBridgeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftBridgeAttr> from(const Reference &r);
  static std::optional<SwiftBridgeAttr> from(const TokenContext &t);

  std::string_view swift_type(void) const;
};

static_assert(sizeof(SwiftBridgeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
