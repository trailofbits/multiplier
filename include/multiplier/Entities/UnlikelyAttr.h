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
#include "StmtAttr.h"

namespace mx {
class Attr;
class StmtAttr;
class UnlikelyAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UnlikelyAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnlikelyAttr>;
class UnlikelyAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  inline static gap::generator<UnlikelyAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static UnlikelyAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnlikelyAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UNLIKELY;
  }

  static std::optional<UnlikelyAttr> from(const TokenContext &c);
  static std::optional<UnlikelyAttr> from(const StmtAttr &parent);

  inline static std::optional<UnlikelyAttr> from(const std::optional<StmtAttr> &parent) {
    if (parent) {
      return UnlikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnlikelyAttr> from(const Attr &parent);

  inline static std::optional<UnlikelyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UnlikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(UnlikelyAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
