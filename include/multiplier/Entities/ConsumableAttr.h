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

#include "ConsumableAttrConsumedState.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ConsumableAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConsumableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConsumableAttr> in(const Fragment &frag);
  static gap::generator<ConsumableAttr> in(const File &file);
  static gap::generator<ConsumableAttr> in(const Index &index);
  static gap::generator<ConsumableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConsumableAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONSUMABLE;
  }

  static std::optional<ConsumableAttr> from(const Attr &parent);

  inline static std::optional<ConsumableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConsumableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ConsumableAttr> from(const Reference &r) {
    return ConsumableAttr::from(r.as_attribute());
  }

  inline static std::optional<ConsumableAttr> from(const TokenContext &t) {
    return ConsumableAttr::from(t.as_attribute());
  }

  ConsumableAttrConsumedState default_state(void) const;
};

static_assert(sizeof(ConsumableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
