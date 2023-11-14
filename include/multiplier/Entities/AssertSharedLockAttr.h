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
class AssertSharedLockAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssertSharedLockAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssertSharedLockAttr> in(const Index &index);
  static gap::generator<AssertSharedLockAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AssertSharedLockAttr> by_id(const Index &, EntityId);
  static gap::generator<AssertSharedLockAttr> in(const Fragment &frag);
  static gap::generator<AssertSharedLockAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSERT_SHARED_LOCK;
  }

  static std::optional<AssertSharedLockAttr> from_base(const Attr &parent);
  inline static std::optional<AssertSharedLockAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AssertSharedLockAttr> from(const std::optional<Attr> &parent);
  static std::optional<AssertSharedLockAttr> from(const Reference &r);
  static std::optional<AssertSharedLockAttr> from(const VariantEntity &e);
  static std::optional<AssertSharedLockAttr> from(const TokenContext &t);

};

static_assert(sizeof(AssertSharedLockAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
