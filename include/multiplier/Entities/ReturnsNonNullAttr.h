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
class ReturnsNonNullAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReturnsNonNullAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ReturnsNonNullAttr> in(const Fragment &frag);
  static gap::generator<ReturnsNonNullAttr> in(const File &file);
  static gap::generator<ReturnsNonNullAttr> in(const Index &index);
  static gap::generator<ReturnsNonNullAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ReturnsNonNullAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RETURNS_NON_NULL;
  }

  static std::optional<ReturnsNonNullAttr> from(const Attr &parent);

  inline static std::optional<ReturnsNonNullAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReturnsNonNullAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReturnsNonNullAttr> from(const Reference &r);
  static std::optional<ReturnsNonNullAttr> from(const TokenContext &t);

};

static_assert(sizeof(ReturnsNonNullAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
