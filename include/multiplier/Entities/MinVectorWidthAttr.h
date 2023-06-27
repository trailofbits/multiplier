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
class MinVectorWidthAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MinVectorWidthAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MinVectorWidthAttr> in(const Fragment &frag);
  static gap::generator<MinVectorWidthAttr> in(const File &file);
  static gap::generator<MinVectorWidthAttr> in(const Index &index);
  static gap::generator<MinVectorWidthAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MinVectorWidthAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIN_VECTOR_WIDTH;
  }

  static std::optional<MinVectorWidthAttr> from(const Attr &parent);

  inline static std::optional<MinVectorWidthAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MinVectorWidthAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MinVectorWidthAttr> from(const Reference &r);
  static std::optional<MinVectorWidthAttr> from(const TokenContext &t);

};

static_assert(sizeof(MinVectorWidthAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
