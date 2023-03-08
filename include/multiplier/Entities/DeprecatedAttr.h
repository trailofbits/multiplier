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
class DeprecatedAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeprecatedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DeprecatedAttr> in(const Fragment &frag);
  static gap::generator<DeprecatedAttr> in(const File &file);
  static gap::generator<DeprecatedAttr> in(const Index &index);
  static gap::generator<DeprecatedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeprecatedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DEPRECATED;
  }

  static std::optional<DeprecatedAttr> from(const Attr &parent);

  inline static std::optional<DeprecatedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DeprecatedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DeprecatedAttr> from(const Reference &r) {
    return DeprecatedAttr::from(r.as_attribute());
  }

  inline static std::optional<DeprecatedAttr> from(const TokenContext &t) {
    return DeprecatedAttr::from(t.as_attribute());
  }

  std::string_view message(void) const;
  std::string_view replacement(void) const;
};

static_assert(sizeof(DeprecatedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
