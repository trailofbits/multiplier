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
class InheritableAttr;
class NoReturnAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoReturnAttr> in(const Fragment &frag);
  static gap::generator<NoReturnAttr> in(const File &file);
  static gap::generator<NoReturnAttr> in(const Index &index);
  static gap::generator<NoReturnAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoReturnAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_RETURN;
  }

  static std::optional<NoReturnAttr> from(const Attr &parent);

  inline static std::optional<NoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoReturnAttr> from(const Reference &r);
  static std::optional<NoReturnAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
