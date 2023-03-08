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

#include "InheritableAttr.h"

namespace mx {
class AMDGPUNumSGPRAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AMDGPUNumSGPRAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUNumSGPRAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUNumSGPRAttr> in(const File &file);
  static gap::generator<AMDGPUNumSGPRAttr> in(const Index &index);
  static gap::generator<AMDGPUNumSGPRAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AMDGPUNumSGPRAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_NUM_SGPR;
  }

  static std::optional<AMDGPUNumSGPRAttr> from(const Attr &parent);

  inline static std::optional<AMDGPUNumSGPRAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AMDGPUNumSGPRAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AMDGPUNumSGPRAttr> from(const Reference &r) {
    return AMDGPUNumSGPRAttr::from(r.as_attribute());
  }

  inline static std::optional<AMDGPUNumSGPRAttr> from(const TokenContext &t) {
    return AMDGPUNumSGPRAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(AMDGPUNumSGPRAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
