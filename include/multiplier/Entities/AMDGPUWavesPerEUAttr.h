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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AMDGPUWavesPerEUAttr;
class Attr;
class Expr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AMDGPUWavesPerEUAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUWavesPerEUAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUWavesPerEUAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_WAVES_PER_EU;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<AMDGPUWavesPerEUAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AMDGPUWavesPerEUAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AMDGPUWavesPerEUAttr> from(const InheritableAttr &parent);

  inline static std::optional<AMDGPUWavesPerEUAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AMDGPUWavesPerEUAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AMDGPUWavesPerEUAttr> from(const Attr &parent);

  inline static std::optional<AMDGPUWavesPerEUAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AMDGPUWavesPerEUAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr max(void) const;
  Expr min(void) const;
};

static_assert(sizeof(AMDGPUWavesPerEUAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
