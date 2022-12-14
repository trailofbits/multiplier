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
#include "../Use.h"

#include "AcquireCapabilityAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AcquireCapabilityAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<AcquireCapabilityAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<AcquireCapabilityAttr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AcquireCapabilityAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_CAPABILITY;
  }

  static std::optional<AcquireCapabilityAttr> from(const TokenContext &c);
  static std::optional<AcquireCapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquireCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AcquireCapabilityAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
