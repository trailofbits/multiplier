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

#include "AttrKind.h"
#include "StmtAttr.h"

namespace mx {
class Attr;
class LikelyAttr;
class StmtAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LikelyAttrRange = DerivedEntityRange<AttrIterator, LikelyAttr>;
using LikelyAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, LikelyAttr>;
class LikelyAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  inline static LikelyAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LikelyAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LikelyAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LIKELY;
  }

  static std::optional<LikelyAttr> from(const TokenContext &c);
  static std::optional<LikelyAttr> from(const StmtAttr &parent);

  inline static std::optional<LikelyAttr> from(const std::optional<StmtAttr> &parent) {
    if (parent) {
      return LikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LikelyAttr> from(const Attr &parent);

  inline static std::optional<LikelyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(LikelyAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
