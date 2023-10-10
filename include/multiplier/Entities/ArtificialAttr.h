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
class ArtificialAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArtificialAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ArtificialAttr> in(const Index &index);
  static gap::generator<ArtificialAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArtificialAttr> by_id(const Index &, EntityId);
  static gap::generator<ArtificialAttr> in(const Fragment &frag);
  static gap::generator<ArtificialAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARTIFICIAL;
  }

  static std::optional<ArtificialAttr> from(const Attr &parent);

  inline static std::optional<ArtificialAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArtificialAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArtificialAttr> from(const Reference &r);
  static std::optional<ArtificialAttr> from(const TokenContext &t);

};

static_assert(sizeof(ArtificialAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
