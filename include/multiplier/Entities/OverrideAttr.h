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
class OverrideAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OverrideAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OverrideAttr> in(const Fragment &frag);
  static gap::generator<OverrideAttr> in(const File &file);
  static gap::generator<OverrideAttr> in(const Index &index);
  static gap::generator<OverrideAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OverrideAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OVERRIDE;
  }

  static std::optional<OverrideAttr> from(const Attr &parent);

  inline static std::optional<OverrideAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OverrideAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OverrideAttr> from(const Reference &r);
  static std::optional<OverrideAttr> from(const TokenContext &t);

};

static_assert(sizeof(OverrideAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
