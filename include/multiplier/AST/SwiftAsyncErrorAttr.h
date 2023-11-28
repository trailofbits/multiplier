// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/SwiftAsyncErrorAttrConventionKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class SwiftAsyncErrorAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftAsyncErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncErrorAttr> in(const Index &index);
  static gap::generator<SwiftAsyncErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftAsyncErrorAttr> by_id(const Index &, EntityId);
  static gap::generator<SwiftAsyncErrorAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncErrorAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC_ERROR;
  }

  static std::optional<SwiftAsyncErrorAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftAsyncErrorAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftAsyncErrorAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftAsyncErrorAttr> from(const Reference &r);
  static std::optional<SwiftAsyncErrorAttr> from(const VariantEntity &e);
  static std::optional<SwiftAsyncErrorAttr> from(const TokenContext &t);

  SwiftAsyncErrorAttrConventionKind convention(void) const;
};

static_assert(sizeof(SwiftAsyncErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
