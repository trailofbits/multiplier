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
class FormatArgAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FormatArgAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<FormatArgAttr> in(const Fragment &frag);
  static gap::generator<FormatArgAttr> in(const File &file);
  static gap::generator<FormatArgAttr> in(const Index &index);
  static gap::generator<FormatArgAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FormatArgAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FORMAT_ARG;
  }

  static std::optional<FormatArgAttr> from(const Attr &parent);

  inline static std::optional<FormatArgAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return FormatArgAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FormatArgAttr> from(const Reference &r);
  static std::optional<FormatArgAttr> from(const TokenContext &t);

};

static_assert(sizeof(FormatArgAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
