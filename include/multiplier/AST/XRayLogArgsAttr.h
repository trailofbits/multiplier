// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class Token;
class XRayLogArgsAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT XRayLogArgsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<XRayLogArgsAttr> in(const Index &index);
  static gap::generator<XRayLogArgsAttr> in(const Fragment &frag);
  static gap::generator<XRayLogArgsAttr> in(const File &file);
  static gap::generator<XRayLogArgsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X_RAY_LOG_ARGS;
  }

  static std::optional<XRayLogArgsAttr> by_id(const Index &, EntityId);

  static std::optional<XRayLogArgsAttr> from_base(const Attr &parent);
  inline static std::optional<XRayLogArgsAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<XRayLogArgsAttr> from(const std::optional<Attr> &parent);
  static std::optional<XRayLogArgsAttr> from(const Reference &r);
  static std::optional<XRayLogArgsAttr> from(const VariantEntity &e);
  static std::optional<XRayLogArgsAttr> from(const TokenContext &t);

  uint32_t argument_count(void) const;
};

static_assert(sizeof(XRayLogArgsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
