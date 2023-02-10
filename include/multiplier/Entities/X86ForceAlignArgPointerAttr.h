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
class X86ForceAlignArgPointerAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class X86ForceAlignArgPointerAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<X86ForceAlignArgPointerAttr> in(const Fragment &frag);
  static gap::generator<X86ForceAlignArgPointerAttr> in(const File &file);
  static gap::generator<X86ForceAlignArgPointerAttr> in(const Index &index);
  static gap::generator<X86ForceAlignArgPointerAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<X86ForceAlignArgPointerAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::X86_FORCE_ALIGN_ARG_POINTER;
  }

  static std::optional<X86ForceAlignArgPointerAttr> from(const Attr &parent);

  inline static std::optional<X86ForceAlignArgPointerAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return X86ForceAlignArgPointerAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<X86ForceAlignArgPointerAttr> from(const Reference &r) {
    return X86ForceAlignArgPointerAttr::from(r.as_attribute());
  }

  inline static std::optional<X86ForceAlignArgPointerAttr> from(const TokenContext &t) {
    return X86ForceAlignArgPointerAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(X86ForceAlignArgPointerAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
