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
class Attr;
class File;
class InheritableAttr;
class Token;
class WorkGroupSizeHintAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT WorkGroupSizeHintAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WorkGroupSizeHintAttr> in(const Index &index);
  static gap::generator<WorkGroupSizeHintAttr> in(const Fragment &frag);
  static gap::generator<WorkGroupSizeHintAttr> in(const File &file);
  static gap::generator<WorkGroupSizeHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WORK_GROUP_SIZE_HINT;
  }

  static std::optional<WorkGroupSizeHintAttr> by_id(const Index &, EntityId);

  static std::optional<WorkGroupSizeHintAttr> from_base(const Attr &parent);
  inline static std::optional<WorkGroupSizeHintAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<WorkGroupSizeHintAttr> from(const std::optional<Attr> &parent);
  static std::optional<WorkGroupSizeHintAttr> from(const Reference &r);
  static std::optional<WorkGroupSizeHintAttr> from(const VariantEntity &e);
  static std::optional<WorkGroupSizeHintAttr> from(const TokenContext &t);

  uint32_t x_dim(void) const;
  uint32_t y_dim(void) const;
  uint32_t z_dim(void) const;
};

static_assert(sizeof(WorkGroupSizeHintAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
