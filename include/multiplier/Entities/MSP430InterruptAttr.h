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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class MSP430InterruptAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MSP430InterruptAttrRange = DerivedEntityRange<AttrIterator, MSP430InterruptAttr>;
using MSP430InterruptAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSP430InterruptAttr>;
class MSP430InterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static MSP430InterruptAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSP430InterruptAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : MSP430InterruptAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MSP430_INTERRUPT;
  }

  static std::optional<MSP430InterruptAttr> from(const TokenContext &c);
  static std::optional<MSP430InterruptAttr> from(const InheritableAttr &parent);

  inline static std::optional<MSP430InterruptAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return MSP430InterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSP430InterruptAttr> from(const Attr &parent);

  inline static std::optional<MSP430InterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MSP430InterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MSP430InterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
