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
class NoBuiltinAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoBuiltinAttrRange = DerivedEntityRange<AttrIterator, NoBuiltinAttr>;
using NoBuiltinAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoBuiltinAttr>;
class NoBuiltinAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static NoBuiltinAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoBuiltinAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NoBuiltinAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_BUILTIN;
  }

  static std::optional<NoBuiltinAttr> from(const TokenContext &c);
  static std::optional<NoBuiltinAttr> from(const Attr &parent);

  inline static std::optional<NoBuiltinAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoBuiltinAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NoBuiltinAttr) == sizeof(Attr));

#endif
} // namespace mx
