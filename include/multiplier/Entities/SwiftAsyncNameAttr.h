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
class SwiftAsyncNameAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncNameAttr> in(const Index &index);
  static gap::generator<SwiftAsyncNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAsyncNameAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftAsyncNameAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncNameAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_NAME;
  }

  static std::optional<SwiftAsyncNameAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftAsyncNameAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftAsyncNameAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftAsyncNameAttr> from(const Reference &r);
  static std::optional<SwiftAsyncNameAttr> from(const VariantEntity &e);
  static std::optional<SwiftAsyncNameAttr> from(const TokenContext &t);

  std::string_view name(void) const;
};

static_assert(sizeof(SwiftAsyncNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
