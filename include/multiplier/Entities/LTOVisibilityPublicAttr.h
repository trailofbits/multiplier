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
class Attr;
class InheritableAttr;
class LTOVisibilityPublicAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LTOVisibilityPublicAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<LTOVisibilityPublicAttr> in(const Fragment &frag);
  static gap::generator<LTOVisibilityPublicAttr> in(const File &file);
  static gap::generator<LTOVisibilityPublicAttr> in(const Index &index);
  static gap::generator<LTOVisibilityPublicAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LTOVisibilityPublicAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LTO_VISIBILITY_PUBLIC;
  }

  static std::optional<LTOVisibilityPublicAttr> from(const Attr &parent);

  inline static std::optional<LTOVisibilityPublicAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LTOVisibilityPublicAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<LTOVisibilityPublicAttr> from(const Reference &r) {
    return LTOVisibilityPublicAttr::from(r.as_attribute());
  }

  inline static std::optional<LTOVisibilityPublicAttr> from(const TokenContext &t) {
    return LTOVisibilityPublicAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(LTOVisibilityPublicAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
