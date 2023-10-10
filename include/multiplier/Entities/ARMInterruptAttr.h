// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ARMInterruptAttrInterruptType.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class ARMInterruptAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ARMInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ARMInterruptAttr> in(const Index &index);
  static gap::generator<ARMInterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ARMInterruptAttr> by_id(const Index &, EntityId);
  static gap::generator<ARMInterruptAttr> in(const Fragment &frag);
  static gap::generator<ARMInterruptAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARM_INTERRUPT;
  }

  static std::optional<ARMInterruptAttr> from(const Attr &parent);

  inline static std::optional<ARMInterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ARMInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ARMInterruptAttr> from(const Reference &r);
  static std::optional<ARMInterruptAttr> from(const TokenContext &t);

  ARMInterruptAttrInterruptType interrupt(void) const;
};

static_assert(sizeof(ARMInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
