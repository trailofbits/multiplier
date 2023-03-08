// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "EnumExtensibilityAttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class EnumExtensibilityAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnumExtensibilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<EnumExtensibilityAttr> in(const Fragment &frag);
  static gap::generator<EnumExtensibilityAttr> in(const File &file);
  static gap::generator<EnumExtensibilityAttr> in(const Index &index);
  static gap::generator<EnumExtensibilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EnumExtensibilityAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENUM_EXTENSIBILITY;
  }

  static std::optional<EnumExtensibilityAttr> from(const Attr &parent);

  inline static std::optional<EnumExtensibilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return EnumExtensibilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumExtensibilityAttr> from(const Reference &r);
  static std::optional<EnumExtensibilityAttr> from(const TokenContext &t);

  EnumExtensibilityAttrKind extensibility(void) const;
};

static_assert(sizeof(EnumExtensibilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
