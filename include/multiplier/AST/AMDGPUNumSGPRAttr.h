// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AMDGPUNumSGPRAttr;
class Attr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AMDGPUNumSGPRAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUNumSGPRAttr> in(const Index &index);
  static gap::generator<AMDGPUNumSGPRAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUNumSGPRAttr> in(const File &file);
  static gap::generator<AMDGPUNumSGPRAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_NUM_SGPR;
  }

  static std::optional<AMDGPUNumSGPRAttr> by_id(const Index &, EntityId);

  static std::optional<AMDGPUNumSGPRAttr> from_base(const Attr &parent);
  inline static std::optional<AMDGPUNumSGPRAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AMDGPUNumSGPRAttr> from(const std::optional<Attr> &parent);
  static std::optional<AMDGPUNumSGPRAttr> from(const Reference &r);
  static std::optional<AMDGPUNumSGPRAttr> from(const VariantEntity &e);
  static std::optional<AMDGPUNumSGPRAttr> from(const TokenContext &t);

  uint32_t num_sgpr(void) const;
};

static_assert(sizeof(AMDGPUNumSGPRAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
