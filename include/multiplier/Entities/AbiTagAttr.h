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
class AbiTagAttr;
class Attr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AbiTagAttrRange = DerivedEntityRange<AttrIterator, AbiTagAttr>;
using AbiTagAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AbiTagAttr>;
class AbiTagAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static AbiTagAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AbiTagAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : AbiTagAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ABI_TAG;
  }

  static std::optional<AbiTagAttr> from(const TokenContext &c);
  static std::optional<AbiTagAttr> from(const Attr &parent);

  inline static std::optional<AbiTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AbiTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(AbiTagAttr) == sizeof(Attr));

#endif
} // namespace mx
