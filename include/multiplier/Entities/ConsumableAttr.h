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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "ConsumableAttrConsumedState.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ConsumableAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConsumableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConsumableAttr> in(const Fragment &frag);
  static gap::generator<ConsumableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONSUMABLE;
  }

  inline static std::optional<ConsumableAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<ConsumableAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<ConsumableAttr> from(const InheritableAttr &parent);

  inline static std::optional<ConsumableAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ConsumableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConsumableAttr> from(const Attr &parent);

  inline static std::optional<ConsumableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConsumableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ConsumableAttrConsumedState default_state(void) const;
};

static_assert(sizeof(ConsumableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
