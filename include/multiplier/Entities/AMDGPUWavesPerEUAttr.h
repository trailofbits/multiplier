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
class AMDGPUWavesPerEUAttr;
class Attr;
class Expr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AMDGPUWavesPerEUAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUWavesPerEUAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUWavesPerEUAttr> in(const File &file);
  static gap::generator<AMDGPUWavesPerEUAttr> in(const Index &index);
  static gap::generator<AMDGPUWavesPerEUAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AMDGPUWavesPerEUAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_WAVES_PER_EU;
  }

  static std::optional<AMDGPUWavesPerEUAttr> from(const Attr &parent);

  inline static std::optional<AMDGPUWavesPerEUAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AMDGPUWavesPerEUAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AMDGPUWavesPerEUAttr> from(const Reference &r);
  static std::optional<AMDGPUWavesPerEUAttr> from(const TokenContext &t);

  Expr max(void) const;
  Expr min(void) const;
};

static_assert(sizeof(AMDGPUWavesPerEUAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
