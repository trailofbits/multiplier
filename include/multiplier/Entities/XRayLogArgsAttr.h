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
class Token;
class XRayLogArgsAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class XRayLogArgsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<XRayLogArgsAttr> in(const Index &index);
  static gap::generator<XRayLogArgsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<XRayLogArgsAttr> by_id(const Index &, EntityId);
  static gap::generator<XRayLogArgsAttr> in(const Fragment &frag);
  static gap::generator<XRayLogArgsAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X_RAY_LOG_ARGS;
  }

  static std::optional<XRayLogArgsAttr> from(const Attr &parent);

  inline static std::optional<XRayLogArgsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return XRayLogArgsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<XRayLogArgsAttr> from(const Reference &r);
  static std::optional<XRayLogArgsAttr> from(const TokenContext &t);

};

static_assert(sizeof(XRayLogArgsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
