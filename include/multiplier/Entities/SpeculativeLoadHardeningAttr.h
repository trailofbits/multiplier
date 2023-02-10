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

namespace mx {
class Attr;
class InheritableAttr;
class SpeculativeLoadHardeningAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SpeculativeLoadHardeningAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SpeculativeLoadHardeningAttr> in(const Fragment &frag);
  static gap::generator<SpeculativeLoadHardeningAttr> in(const File &file);
  static gap::generator<SpeculativeLoadHardeningAttr> in(const Index &index);
  static gap::generator<SpeculativeLoadHardeningAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SpeculativeLoadHardeningAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SPECULATIVE_LOAD_HARDENING;
  }

  static std::optional<SpeculativeLoadHardeningAttr> from(const Attr &parent);

  inline static std::optional<SpeculativeLoadHardeningAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SpeculativeLoadHardeningAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SpeculativeLoadHardeningAttr> from(const Reference &r) {
    return SpeculativeLoadHardeningAttr::from(r.as_attribute());
  }

  inline static std::optional<SpeculativeLoadHardeningAttr> from(const TokenContext &t) {
    return SpeculativeLoadHardeningAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(SpeculativeLoadHardeningAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
