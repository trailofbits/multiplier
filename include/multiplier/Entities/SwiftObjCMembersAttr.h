// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class SwiftObjCMembersAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftObjCMembersAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<SwiftObjCMembersAttr> in(const Fragment &frag);
  static gap::generator<SwiftObjCMembersAttr> in(const File &file);
  static gap::generator<SwiftObjCMembersAttr> in(const Index &index);
  static gap::generator<SwiftObjCMembersAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftObjCMembersAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_OBJ_C_MEMBERS;
  }

  static std::optional<SwiftObjCMembersAttr> from(const Attr &parent);

  inline static std::optional<SwiftObjCMembersAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftObjCMembersAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftObjCMembersAttr> from(const Reference &r);
  static std::optional<SwiftObjCMembersAttr> from(const TokenContext &t);

};

static_assert(sizeof(SwiftObjCMembersAttr) == sizeof(Attr));

#endif
} // namespace mx
