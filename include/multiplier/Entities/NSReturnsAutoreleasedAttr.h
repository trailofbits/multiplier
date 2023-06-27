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
class NSReturnsAutoreleasedAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NSReturnsAutoreleasedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NSReturnsAutoreleasedAttr> in(const Fragment &frag);
  static gap::generator<NSReturnsAutoreleasedAttr> in(const File &file);
  static gap::generator<NSReturnsAutoreleasedAttr> in(const Index &index);
  static gap::generator<NSReturnsAutoreleasedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NSReturnsAutoreleasedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_RETURNS_AUTORELEASED;
  }

  static std::optional<NSReturnsAutoreleasedAttr> from(const Attr &parent);

  inline static std::optional<NSReturnsAutoreleasedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSReturnsAutoreleasedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSReturnsAutoreleasedAttr> from(const Reference &r);
  static std::optional<NSReturnsAutoreleasedAttr> from(const TokenContext &t);

};

static_assert(sizeof(NSReturnsAutoreleasedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
