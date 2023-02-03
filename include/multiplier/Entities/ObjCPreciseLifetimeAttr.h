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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class ObjCPreciseLifetimeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCPreciseLifetimeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<ObjCPreciseLifetimeAttr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCPreciseLifetimeAttr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCPreciseLifetimeAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
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

};

static_assert(sizeof(ObjCPreciseLifetimeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
