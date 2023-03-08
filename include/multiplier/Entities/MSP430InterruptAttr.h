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
class MSP430InterruptAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSP430InterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSP430InterruptAttr> in(const Fragment &frag);
  static gap::generator<MSP430InterruptAttr> in(const File &file);
  static gap::generator<MSP430InterruptAttr> in(const Index &index);
  static gap::generator<MSP430InterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSP430InterruptAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MSP430_INTERRUPT;
  }

  static std::optional<MSP430InterruptAttr> from(const Attr &parent);

  inline static std::optional<MSP430InterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MSP430InterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<MSP430InterruptAttr> from(const Reference &r) {
    return MSP430InterruptAttr::from(r.as_attribute());
  }

  inline static std::optional<MSP430InterruptAttr> from(const TokenContext &t) {
    return MSP430InterruptAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(MSP430InterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
