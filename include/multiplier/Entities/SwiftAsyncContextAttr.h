// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ParameterABIAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class SwiftAsyncContextAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncContextAttr : public ParameterABIAttr {
 private:
  friend class FragmentImpl;
  friend class ParameterABIAttr;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncContextAttr> in(const Index &index);
  static gap::generator<SwiftAsyncContextAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAsyncContextAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftAsyncContextAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncContextAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_CONTEXT;
  }

  static std::optional<SwiftAsyncContextAttr> from(const Attr &parent);

  inline static std::optional<SwiftAsyncContextAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftAsyncContextAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftAsyncContextAttr> from(const Reference &r);
  static std::optional<SwiftAsyncContextAttr> from(const TokenContext &t);

};

static_assert(sizeof(SwiftAsyncContextAttr) == sizeof(ParameterABIAttr));

#endif
} // namespace mx
