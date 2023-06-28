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
class EnforceTCBLeafAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnforceTCBLeafAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<EnforceTCBLeafAttr> in(const Fragment &frag);
  static gap::generator<EnforceTCBLeafAttr> in(const File &file);
  static gap::generator<EnforceTCBLeafAttr> in(const Index &index);
  static gap::generator<EnforceTCBLeafAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EnforceTCBLeafAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENFORCE_TCB_LEAF;
  }

  static std::optional<EnforceTCBLeafAttr> from(const Attr &parent);

  inline static std::optional<EnforceTCBLeafAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return EnforceTCBLeafAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnforceTCBLeafAttr> from(const Reference &r);
  static std::optional<EnforceTCBLeafAttr> from(const TokenContext &t);

  std::string_view tcb_name(void) const;
};

static_assert(sizeof(EnforceTCBLeafAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
