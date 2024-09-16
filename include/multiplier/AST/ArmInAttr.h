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
class ArmInAttr;
class Attr;
class File;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ArmInAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ArmInAttr> in(const Index &index);
  static gap::generator<ArmInAttr> in(const Fragment &frag);
  static gap::generator<ArmInAttr> in(const File &file);
  static gap::generator<ArmInAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_IN;
  }

  static std::optional<ArmInAttr> by_id(const Index &, EntityId);

  static std::optional<ArmInAttr> from_base(const Attr &parent);
  inline static std::optional<ArmInAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ArmInAttr> from(const std::optional<Attr> &parent);
  static std::optional<ArmInAttr> from(const Reference &r);
  static std::optional<ArmInAttr> from(const VariantEntity &e);
  static std::optional<ArmInAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArmInAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
