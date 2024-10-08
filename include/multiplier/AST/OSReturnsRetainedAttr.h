// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class OSReturnsRetainedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OSReturnsRetainedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OSReturnsRetainedAttr> in(const Index &index);
  static gap::generator<OSReturnsRetainedAttr> in(const Fragment &frag);
  static gap::generator<OSReturnsRetainedAttr> in(const File &file);
  static gap::generator<OSReturnsRetainedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OS_RETURNS_RETAINED;
  }

  static std::optional<OSReturnsRetainedAttr> by_id(const Index &, EntityId);

  static std::optional<OSReturnsRetainedAttr> from_base(const Attr &parent);
  inline static std::optional<OSReturnsRetainedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OSReturnsRetainedAttr> from(const std::optional<Attr> &parent);
  static std::optional<OSReturnsRetainedAttr> from(const Reference &r);
  static std::optional<OSReturnsRetainedAttr> from(const VariantEntity &e);
  static std::optional<OSReturnsRetainedAttr> from(const TokenContext &t);

};

static_assert(sizeof(OSReturnsRetainedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
