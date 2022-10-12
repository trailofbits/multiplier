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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class OverloadableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OverloadableAttrRange = DerivedEntityRange<AttrIterator, OverloadableAttr>;
using OverloadableAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OverloadableAttr>;
class OverloadableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static OverloadableAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OverloadableAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OverloadableAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OVERLOADABLE;
  }

  static std::optional<OverloadableAttr> from(const TokenContext &c);
  static std::optional<OverloadableAttr> from(const Attr &parent);

  inline static std::optional<OverloadableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OverloadableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(OverloadableAttr) == sizeof(Attr));

#endif
} // namespace mx
