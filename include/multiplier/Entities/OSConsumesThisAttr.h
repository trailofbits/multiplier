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
class OSConsumesThisAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OSConsumesThisAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OSConsumesThisAttr> in(const Fragment &frag);
  static gap::generator<OSConsumesThisAttr> in(const File &file);
  static gap::generator<OSConsumesThisAttr> in(const Index &index);
  static gap::generator<OSConsumesThisAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OSConsumesThisAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OS_CONSUMES_THIS;
  }

  static std::optional<OSConsumesThisAttr> from(const Attr &parent);

  inline static std::optional<OSConsumesThisAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OSConsumesThisAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OSConsumesThisAttr> from(const Reference &r);
  static std::optional<OSConsumesThisAttr> from(const TokenContext &t);

};

static_assert(sizeof(OSConsumesThisAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
