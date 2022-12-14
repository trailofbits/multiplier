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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"
#include "MipsInterruptAttrInterruptType.h"

namespace mx {
class Attr;
class InheritableAttr;
class MipsInterruptAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MipsInterruptAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, MipsInterruptAttr>;
class MipsInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<MipsInterruptAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static MipsInterruptAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MipsInterruptAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS_INTERRUPT;
  }

  static std::optional<MipsInterruptAttr> from(const TokenContext &c);
  static std::optional<MipsInterruptAttr> from(const InheritableAttr &parent);

  inline static std::optional<MipsInterruptAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return MipsInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MipsInterruptAttr> from(const Attr &parent);

  inline static std::optional<MipsInterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MipsInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  MipsInterruptAttrInterruptType interrupt(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(MipsInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
