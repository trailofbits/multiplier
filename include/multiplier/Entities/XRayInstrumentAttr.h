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
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"
#include "XRayInstrumentAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class XRayInstrumentAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using XRayInstrumentAttrRange = DerivedEntityRange<AttrIterator, XRayInstrumentAttr>;
using XRayInstrumentAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, XRayInstrumentAttr>;
class XRayInstrumentAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static XRayInstrumentAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static XRayInstrumentAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : XRayInstrumentAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X_RAY_INSTRUMENT;
  }

  static std::optional<XRayInstrumentAttr> from(const TokenContext &c);
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
  std::string_view spelling(void) const;
  bool never_x_ray_instrument(void) const;
};

static_assert(sizeof(XRayInstrumentAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
