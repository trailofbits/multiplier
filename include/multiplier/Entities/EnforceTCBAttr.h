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
class EnforceTCBAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnforceTCBAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<EnforceTCBAttr> in(const Fragment &frag);
  static gap::generator<EnforceTCBAttr> in(const File &file);
  static gap::generator<EnforceTCBAttr> in(const Index &index);
  static gap::generator<EnforceTCBAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EnforceTCBAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENFORCE_TCB;
  }

  static std::optional<EnforceTCBAttr> from(const Attr &parent);

  inline static std::optional<EnforceTCBAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return EnforceTCBAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnforceTCBAttr> from(const Reference &r);
  static std::optional<EnforceTCBAttr> from(const TokenContext &t);

  std::string_view tcb_name(void) const;
};

static_assert(sizeof(EnforceTCBAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
