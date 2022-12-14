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
class Attr;
class IBActionAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IBActionAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, IBActionAttr>;
class IBActionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<IBActionAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static IBActionAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : IBActionAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::IB_ACTION;
  }

  static std::optional<IBActionAttr> from(const TokenContext &c);
  static std::optional<IBActionAttr> from(const InheritableAttr &parent);

  inline static std::optional<IBActionAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return IBActionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IBActionAttr> from(const Attr &parent);

  inline static std::optional<IBActionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return IBActionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(IBActionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
