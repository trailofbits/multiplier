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
class CalledOnceAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CalledOnceAttrRange = DerivedEntityRange<AttrIterator, CalledOnceAttr>;
using CalledOnceAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CalledOnceAttr>;
class CalledOnceAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static CalledOnceAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CalledOnceAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CalledOnceAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CALLED_ONCE;
  }

  static std::optional<CalledOnceAttr> from(const TokenContext &c);
  static std::optional<CalledOnceAttr> from(const Attr &parent);

  inline static std::optional<CalledOnceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CalledOnceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(CalledOnceAttr) == sizeof(Attr));

#endif
} // namespace mx
