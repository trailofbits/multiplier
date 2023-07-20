// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "SwiftErrorAttrConventionKind.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SwiftErrorAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftErrorAttr> in(const Index &index);
  static gap::generator<SwiftErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftErrorAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftErrorAttr> in(const Fragment &frag);
  static gap::generator<SwiftErrorAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ERROR;
  }

  static std::optional<SwiftErrorAttr> from(const Attr &parent);

  inline static std::optional<SwiftErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftErrorAttr> from(const Reference &r);
  static std::optional<SwiftErrorAttr> from(const TokenContext &t);

  SwiftErrorAttrConventionKind convention(void) const;
};

static_assert(sizeof(SwiftErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
