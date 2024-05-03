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
class ArmNewAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ArmNewAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ArmNewAttr> in(const Index &index);
  static gap::generator<ArmNewAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArmNewAttr> by_id(const Index &, EntityId);
  static gap::generator<ArmNewAttr> in(const Fragment &frag);
  static gap::generator<ArmNewAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_NEW;
  }

  static std::optional<ArmNewAttr> from_base(const Attr &parent);
  inline static std::optional<ArmNewAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ArmNewAttr> from(const std::optional<Attr> &parent);
  static std::optional<ArmNewAttr> from(const Reference &r);
  static std::optional<ArmNewAttr> from(const VariantEntity &e);
  static std::optional<ArmNewAttr> from(const TokenContext &t);

  bool is_new_za(void) const;
  bool is_new_zt0(void) const;
};

static_assert(sizeof(ArmNewAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
