// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/SwiftAsyncAttrKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class SwiftAsyncAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SwiftAsyncAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftAsyncAttr> in(const Index &index);
  static gap::generator<SwiftAsyncAttr> in(const Fragment &frag);
  static gap::generator<SwiftAsyncAttr> in(const File &file);
  static gap::generator<SwiftAsyncAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ASYNC;
  }

  static std::optional<SwiftAsyncAttr> by_id(const Index &, EntityId);

  static std::optional<SwiftAsyncAttr> from_base(const Attr &parent);
  inline static std::optional<SwiftAsyncAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<SwiftAsyncAttr> from(const std::optional<Attr> &parent);
  static std::optional<SwiftAsyncAttr> from(const Reference &r);
  static std::optional<SwiftAsyncAttr> from(const VariantEntity &e);
  static std::optional<SwiftAsyncAttr> from(const TokenContext &t);

  SwiftAsyncAttrKind attribute_kind(void) const;
};

static_assert(sizeof(SwiftAsyncAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
