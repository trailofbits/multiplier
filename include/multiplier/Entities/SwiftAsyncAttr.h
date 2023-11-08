// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "SwiftAsyncAttrKind.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SwiftAsyncAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncAttr> in(const Index &index);
  static gap::generator<SwiftAsyncAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAsyncAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftAsyncAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC;
  }

  static std::optional<SwiftAsyncAttr> from(const Attr &parent);

  inline static std::optional<SwiftAsyncAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAsyncAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncAttr> from(const Reference &r);
  static std::optional<SwiftAsyncAttr> from(const TokenContext &t);

  SwiftAsyncAttrKind attribute_kind(void) const;
};

static_assert(sizeof(SwiftAsyncAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
