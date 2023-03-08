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
class AssertExclusiveLockAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssertExclusiveLockAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssertExclusiveLockAttr> in(const Fragment &frag);
  static gap::generator<AssertExclusiveLockAttr> in(const File &file);
  static gap::generator<AssertExclusiveLockAttr> in(const Index &index);
  static gap::generator<AssertExclusiveLockAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssertExclusiveLockAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSERT_EXCLUSIVE_LOCK;
  }

  static std::optional<AssertExclusiveLockAttr> from(const Attr &parent);

  inline static std::optional<AssertExclusiveLockAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssertExclusiveLockAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssertExclusiveLockAttr> from(const Reference &r);
  static std::optional<AssertExclusiveLockAttr> from(const TokenContext &t);

};

static_assert(sizeof(AssertExclusiveLockAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
