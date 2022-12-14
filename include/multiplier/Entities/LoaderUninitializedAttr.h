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
class LoaderUninitializedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LoaderUninitializedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, LoaderUninitializedAttr>;
class LoaderUninitializedAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<LoaderUninitializedAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static LoaderUninitializedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LoaderUninitializedAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOADER_UNINITIALIZED;
  }

  static std::optional<LoaderUninitializedAttr> from(const TokenContext &c);
  static std::optional<LoaderUninitializedAttr> from(const Attr &parent);

  inline static std::optional<LoaderUninitializedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LoaderUninitializedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(LoaderUninitializedAttr) == sizeof(Attr));

#endif
} // namespace mx
