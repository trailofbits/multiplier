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
class Attr;
class InheritableAttr;
class Token;
class WorkGroupSizeHintAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WorkGroupSizeHintAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<WorkGroupSizeHintAttr> in(const Fragment &frag);
  static gap::generator<WorkGroupSizeHintAttr> in(const File &file);
  static gap::generator<WorkGroupSizeHintAttr> in(const Index &index);
  static gap::generator<WorkGroupSizeHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<WorkGroupSizeHintAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WORK_GROUP_SIZE_HINT;
  }

  static std::optional<WorkGroupSizeHintAttr> from(const Attr &parent);

  inline static std::optional<WorkGroupSizeHintAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WorkGroupSizeHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<WorkGroupSizeHintAttr> from(const Reference &r);
  static std::optional<WorkGroupSizeHintAttr> from(const TokenContext &t);

};

static_assert(sizeof(WorkGroupSizeHintAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
