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
#include "SwiftErrorAttrConventionKind.h"

namespace mx {
class Attr;
class InheritableAttr;
class SwiftErrorAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SwiftErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SwiftErrorAttr> in(const Fragment &frag);
  static gap::generator<SwiftErrorAttr> in(const File &file);
  static gap::generator<SwiftErrorAttr> in(const Index &index);
  static gap::generator<SwiftErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SwiftErrorAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SWIFT_ERROR;
  }

  static std::optional<SwiftErrorAttr> from(const Attr &parent);

  inline static std::optional<SwiftErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SwiftErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SwiftErrorAttr> from(const Reference &r) {
    return SwiftErrorAttr::from(r.as_attribute());
  }

  inline static std::optional<SwiftErrorAttr> from(const TokenContext &t) {
    return SwiftErrorAttr::from(t.as_attribute());
  }

  SwiftErrorAttrConventionKind convention(void) const;
};

static_assert(sizeof(SwiftErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
