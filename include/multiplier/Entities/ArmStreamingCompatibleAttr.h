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
class ArmStreamingCompatibleAttr;
class Attr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArmStreamingCompatibleAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ArmStreamingCompatibleAttr> in(const Index &index);
  static gap::generator<ArmStreamingCompatibleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArmStreamingCompatibleAttr> by_id(const Index &, EntityId);
  static gap::generator<ArmStreamingCompatibleAttr> in(const Fragment &frag);
  static gap::generator<ArmStreamingCompatibleAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_STREAMING_COMPATIBLE;
  }

  static std::optional<ArmStreamingCompatibleAttr> from(const Attr &parent);

  inline static std::optional<ArmStreamingCompatibleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArmStreamingCompatibleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArmStreamingCompatibleAttr> from(const Reference &r);
  static std::optional<ArmStreamingCompatibleAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArmStreamingCompatibleAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
