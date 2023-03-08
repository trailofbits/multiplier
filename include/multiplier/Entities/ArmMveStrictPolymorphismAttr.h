// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeAttr.h"

namespace mx {
class EntityProvider;
class Index;
class ArmMveStrictPolymorphismAttr;
class Attr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArmMveStrictPolymorphismAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ArmMveStrictPolymorphismAttr> in(const Fragment &frag);
  static gap::generator<ArmMveStrictPolymorphismAttr> in(const File &file);
  static gap::generator<ArmMveStrictPolymorphismAttr> in(const Index &index);
  static gap::generator<ArmMveStrictPolymorphismAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArmMveStrictPolymorphismAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_MVE_STRICT_POLYMORPHISM;
  }

  static std::optional<ArmMveStrictPolymorphismAttr> from(const Attr &parent);

  inline static std::optional<ArmMveStrictPolymorphismAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArmMveStrictPolymorphismAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArmMveStrictPolymorphismAttr> from(const Reference &r);
  static std::optional<ArmMveStrictPolymorphismAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArmMveStrictPolymorphismAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
