// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableAttr.h"
#include "XRayInstrumentAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class XRayInstrumentAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class XRayInstrumentAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<XRayInstrumentAttr> in(const Fragment &frag);
  static gap::generator<XRayInstrumentAttr> in(const Index &index);
  static gap::generator<XRayInstrumentAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<XRayInstrumentAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X_RAY_INSTRUMENT;
  }

  inline static std::optional<XRayInstrumentAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<XRayInstrumentAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<XRayInstrumentAttr> from(const InheritableAttr &parent);

  inline static std::optional<XRayInstrumentAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return XRayInstrumentAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<XRayInstrumentAttr> from(const Attr &parent);

  inline static std::optional<XRayInstrumentAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return XRayInstrumentAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool always_x_ray_instrument(void) const;
  XRayInstrumentAttrSpelling semantic_spelling(void) const;
  bool never_x_ray_instrument(void) const;
};

static_assert(sizeof(XRayInstrumentAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
