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
class AlignNaturalAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignNaturalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AlignNaturalAttr> in(const Fragment &frag);
  static gap::generator<AlignNaturalAttr> in(const File &file);
  static gap::generator<AlignNaturalAttr> in(const Index &index);
  static gap::generator<AlignNaturalAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlignNaturalAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_NATURAL;
  }

  static std::optional<AlignNaturalAttr> from(const Attr &parent);

  inline static std::optional<AlignNaturalAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignNaturalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AlignNaturalAttr> from(const Reference &r) {
    return AlignNaturalAttr::from(r.as_attribute());
  }

  inline static std::optional<AlignNaturalAttr> from(const TokenContext &t) {
    return AlignNaturalAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(AlignNaturalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
