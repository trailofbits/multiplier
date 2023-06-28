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
class SwiftNameAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftNameAttr> in(const Fragment &frag);
  static gap::generator<SwiftNameAttr> in(const File &file);
  static gap::generator<SwiftNameAttr> in(const Index &index);
  static gap::generator<SwiftNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftNameAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_NAME;
  }

  static std::optional<SwiftNameAttr> from(const Attr &parent);

  inline static std::optional<SwiftNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SwiftNameAttr> from(const Reference &r);
  static std::optional<SwiftNameAttr> from(const TokenContext &t);

  std::string_view name(void) const;
};

static_assert(sizeof(SwiftNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
