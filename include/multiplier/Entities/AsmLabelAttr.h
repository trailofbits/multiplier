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

namespace mx {
class AsmLabelAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AsmLabelAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AsmLabelAttr>;
class AsmLabelAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<AsmLabelAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static AsmLabelAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AsmLabelAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASM_LABEL;
  }

  static std::optional<AsmLabelAttr> from(const TokenContext &c);
  static std::optional<AsmLabelAttr> from(const InheritableAttr &parent);

  inline static std::optional<AsmLabelAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AsmLabelAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AsmLabelAttr> from(const Attr &parent);

  inline static std::optional<AsmLabelAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AsmLabelAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_literal_label(void) const;
  std::string_view label(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(AsmLabelAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
