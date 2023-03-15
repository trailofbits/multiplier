// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "MipsInterruptAttrInterruptType.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class MipsInterruptAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MipsInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MipsInterruptAttr> in(const Fragment &frag);
  static gap::generator<MipsInterruptAttr> in(const File &file);
  static gap::generator<MipsInterruptAttr> in(const Index &index);
  static gap::generator<MipsInterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MipsInterruptAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS_INTERRUPT;
  }

  static std::optional<MipsInterruptAttr> from(const Attr &parent);

  inline static std::optional<MipsInterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MipsInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MipsInterruptAttr> from(const Reference &r);
  static std::optional<MipsInterruptAttr> from(const TokenContext &t);

  MipsInterruptAttrInterruptType interrupt(void) const;
};

static_assert(sizeof(MipsInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
