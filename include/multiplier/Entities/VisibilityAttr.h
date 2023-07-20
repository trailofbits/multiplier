// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "VisibilityAttrVisibilityType.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class Token;
class VisibilityAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VisibilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<VisibilityAttr> in(const Index &index);
  static gap::generator<VisibilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VisibilityAttr> by_id(const Index &, EntityId);
  static gap::generator<VisibilityAttr> in(const Fragment &frag);
  static gap::generator<VisibilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::VISIBILITY;
  }

  static std::optional<VisibilityAttr> from(const Attr &parent);

  inline static std::optional<VisibilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return VisibilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VisibilityAttr> from(const Reference &r);
  static std::optional<VisibilityAttr> from(const TokenContext &t);

  VisibilityAttrVisibilityType visibility(void) const;
};

static_assert(sizeof(VisibilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
