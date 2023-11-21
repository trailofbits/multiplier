// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "XRayInstrumentAttrSpelling.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class Token;
class XRayInstrumentAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class XRayInstrumentAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<XRayInstrumentAttr> in(const Index &index);
  static gap::generator<XRayInstrumentAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<XRayInstrumentAttr> by_id(const Index &, EntityId);
  static gap::generator<XRayInstrumentAttr> in(const Fragment &frag);
  static gap::generator<XRayInstrumentAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X_RAY_INSTRUMENT;
  }

  static std::optional<XRayInstrumentAttr> from_base(const Attr &parent);
  inline static std::optional<XRayInstrumentAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<XRayInstrumentAttr> from(const std::optional<Attr> &parent);
  static std::optional<XRayInstrumentAttr> from(const Reference &r);
  static std::optional<XRayInstrumentAttr> from(const VariantEntity &e);
  static std::optional<XRayInstrumentAttr> from(const TokenContext &t);

  bool always_x_ray_instrument(void) const;
  XRayInstrumentAttrSpelling semantic_spelling(void) const;
  bool never_x_ray_instrument(void) const;
};

static_assert(sizeof(XRayInstrumentAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
