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
class AMDGPUFlatWorkGroupSizeAttr;
class Attr;
class Expr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AMDGPUFlatWorkGroupSizeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AMDGPUFlatWorkGroupSizeAttr> in(const Index &index);
  static gap::generator<AMDGPUFlatWorkGroupSizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AMDGPUFlatWorkGroupSizeAttr> by_id(const Index &, EntityId);
  static gap::generator<AMDGPUFlatWorkGroupSizeAttr> in(const Fragment &frag);
  static gap::generator<AMDGPUFlatWorkGroupSizeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AMDGPU_FLAT_WORK_GROUP_SIZE;
  }

  static std::optional<AMDGPUFlatWorkGroupSizeAttr> from_base(const Attr &parent);
  inline static std::optional<AMDGPUFlatWorkGroupSizeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AMDGPUFlatWorkGroupSizeAttr> from(const std::optional<Attr> &parent);
  static std::optional<AMDGPUFlatWorkGroupSizeAttr> from(const Reference &r);
  static std::optional<AMDGPUFlatWorkGroupSizeAttr> from(const VariantEntity &e);
  static std::optional<AMDGPUFlatWorkGroupSizeAttr> from(const TokenContext &t);

  Expr max(void) const;
  Expr min(void) const;
};

static_assert(sizeof(AMDGPUFlatWorkGroupSizeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
