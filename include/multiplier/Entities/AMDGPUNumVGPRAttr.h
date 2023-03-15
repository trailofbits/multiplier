// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AMDGPUNumVGPRAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AMDGPUNumVGPRAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUNumVGPRAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUNumVGPRAttr> in(const File &file);
  static gap::generator<AMDGPUNumVGPRAttr> in(const Index &index);
  static gap::generator<AMDGPUNumVGPRAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AMDGPUNumVGPRAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_NUM_VGPR;
  }

  static std::optional<AMDGPUNumVGPRAttr> from(const Attr &parent);

  inline static std::optional<AMDGPUNumVGPRAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AMDGPUNumVGPRAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AMDGPUNumVGPRAttr> from(const Reference &r);
  static std::optional<AMDGPUNumVGPRAttr> from(const TokenContext &t);

};

static_assert(sizeof(AMDGPUNumVGPRAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
