// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ArmStreamingCompatibleAttr;
class Attr;
class File;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ArmStreamingCompatibleAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ArmStreamingCompatibleAttr> in(const Index &index);
  static gap::generator<ArmStreamingCompatibleAttr> in(const Fragment &frag);
  static gap::generator<ArmStreamingCompatibleAttr> in(const File &file);
  static gap::generator<ArmStreamingCompatibleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_STREAMING_COMPATIBLE;
  }

  static std::optional<ArmStreamingCompatibleAttr> by_id(const Index &, EntityId);

  static std::optional<ArmStreamingCompatibleAttr> from_base(const Attr &parent);
  inline static std::optional<ArmStreamingCompatibleAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ArmStreamingCompatibleAttr> from(const std::optional<Attr> &parent);
  static std::optional<ArmStreamingCompatibleAttr> from(const Reference &r);
  static std::optional<ArmStreamingCompatibleAttr> from(const VariantEntity &e);
  static std::optional<ArmStreamingCompatibleAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArmStreamingCompatibleAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
