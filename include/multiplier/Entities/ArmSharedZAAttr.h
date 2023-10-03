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
class ArmSharedZAAttr;
class Attr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArmSharedZAAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ArmSharedZAAttr> in(const Index &index);
  static gap::generator<ArmSharedZAAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArmSharedZAAttr> by_id(const Index &, EntityId);
  static gap::generator<ArmSharedZAAttr> in(const Fragment &frag);
  static gap::generator<ArmSharedZAAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_SHARED_ZA;
  }

  static std::optional<ArmSharedZAAttr> from(const Attr &parent);

  inline static std::optional<ArmSharedZAAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArmSharedZAAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArmSharedZAAttr> from(const Reference &r);
  static std::optional<ArmSharedZAAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArmSharedZAAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
