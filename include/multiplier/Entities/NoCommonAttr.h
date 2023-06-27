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
class NoCommonAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoCommonAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoCommonAttr> in(const Fragment &frag);
  static gap::generator<NoCommonAttr> in(const File &file);
  static gap::generator<NoCommonAttr> in(const Index &index);
  static gap::generator<NoCommonAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoCommonAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_COMMON;
  }

  static std::optional<NoCommonAttr> from(const Attr &parent);

  inline static std::optional<NoCommonAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoCommonAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoCommonAttr> from(const Reference &r);
  static std::optional<NoCommonAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoCommonAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
