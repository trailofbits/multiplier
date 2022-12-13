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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class IFuncAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IFuncAttrRange = DerivedEntityRange<AttrIterator, IFuncAttr>;
using IFuncAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, IFuncAttr>;
class IFuncAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static IFuncAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IFuncAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : IFuncAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::I_FUNC;
  }

  static std::optional<IFuncAttr> from(const TokenContext &c);
  static std::optional<IFuncAttr> from(const Attr &parent);

  inline static std::optional<IFuncAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return IFuncAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view resolver(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(IFuncAttr) == sizeof(Attr));

#endif
} // namespace mx
