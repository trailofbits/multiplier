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

namespace mx {
class Attr;
class InheritableAttr;
class ObjCPreciseLifetimeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCPreciseLifetimeAttrRange = DerivedEntityRange<AttrIterator, ObjCPreciseLifetimeAttr>;
using ObjCPreciseLifetimeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCPreciseLifetimeAttr>;
class ObjCPreciseLifetimeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ObjCPreciseLifetimeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCPreciseLifetimeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCPreciseLifetimeAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_PRECISE_LIFETIME;
  }

  static std::optional<ObjCPreciseLifetimeAttr> from(const TokenContext &c);
  static std::optional<ObjCPreciseLifetimeAttr> from(const InheritableAttr &parent);

  inline static std::optional<ObjCPreciseLifetimeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ObjCPreciseLifetimeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCPreciseLifetimeAttr> from(const Attr &parent);

  inline static std::optional<ObjCPreciseLifetimeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCPreciseLifetimeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCPreciseLifetimeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
