// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class NSReturnsRetainedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NSReturnsRetainedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NSReturnsRetainedAttr> in(const Index &index);
  static gap::generator<NSReturnsRetainedAttr> in(const Fragment &frag);
  static gap::generator<NSReturnsRetainedAttr> in(const File &file);
  static gap::generator<NSReturnsRetainedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_RETURNS_RETAINED;
  }

  static std::optional<NSReturnsRetainedAttr> by_id(const Index &, EntityId);

  static std::optional<NSReturnsRetainedAttr> from_base(const Attr &parent);
  inline static std::optional<NSReturnsRetainedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NSReturnsRetainedAttr> from(const std::optional<Attr> &parent);
  static std::optional<NSReturnsRetainedAttr> from(const Reference &r);
  static std::optional<NSReturnsRetainedAttr> from(const VariantEntity &e);
  static std::optional<NSReturnsRetainedAttr> from(const TokenContext &t);

};

static_assert(sizeof(NSReturnsRetainedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
