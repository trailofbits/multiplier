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
class NoDestroyAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoDestroyAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoDestroyAttr> in(const Fragment &frag);
  static gap::generator<NoDestroyAttr> in(const File &file);
  static gap::generator<NoDestroyAttr> in(const Index &index);
  static gap::generator<NoDestroyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoDestroyAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_DESTROY;
  }

  static std::optional<NoDestroyAttr> from(const Attr &parent);

  inline static std::optional<NoDestroyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoDestroyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoDestroyAttr> from(const Reference &r);
  static std::optional<NoDestroyAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoDestroyAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
