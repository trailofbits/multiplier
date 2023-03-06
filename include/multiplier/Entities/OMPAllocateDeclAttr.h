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
#include "OMPAllocateDeclAttrAllocatorTypeTy.h"

namespace mx {
class Attr;
class Expr;
class InheritableAttr;
class OMPAllocateDeclAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPAllocateDeclAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OMPAllocateDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPAllocateDeclAttr> in(const File &file);
  static gap::generator<OMPAllocateDeclAttr> in(const Index &index);
  static gap::generator<OMPAllocateDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPAllocateDeclAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_ALLOCATE_DECL;
  }

  static std::optional<OMPAllocateDeclAttr> from(const Attr &parent);

  inline static std::optional<OMPAllocateDeclAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPAllocateDeclAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OMPAllocateDeclAttr> from(const Reference &r) {
    return OMPAllocateDeclAttr::from(r.as_attribute());
  }

  inline static std::optional<OMPAllocateDeclAttr> from(const TokenContext &t) {
    return OMPAllocateDeclAttr::from(t.as_attribute());
  }

  Expr alignment(void) const;
  Expr allocator(void) const;
  OMPAllocateDeclAttrAllocatorTypeTy allocator_type(void) const;
};

static_assert(sizeof(OMPAllocateDeclAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
