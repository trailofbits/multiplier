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
class ArcWeakrefUnavailableAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArcWeakrefUnavailableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ArcWeakrefUnavailableAttr> in(const Fragment &frag);
  static gap::generator<ArcWeakrefUnavailableAttr> in(const File &file);
  static gap::generator<ArcWeakrefUnavailableAttr> in(const Index &index);
  static gap::generator<ArcWeakrefUnavailableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArcWeakrefUnavailableAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARC_WEAKREF_UNAVAILABLE;
  }

  static std::optional<ArcWeakrefUnavailableAttr> from(const Attr &parent);

  inline static std::optional<ArcWeakrefUnavailableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArcWeakrefUnavailableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArcWeakrefUnavailableAttr> from(const Reference &r);
  static std::optional<ArcWeakrefUnavailableAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArcWeakrefUnavailableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
