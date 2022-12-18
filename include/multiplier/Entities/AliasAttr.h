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
class AliasAttr;
class Attr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AliasAttrRange = DerivedEntityRange<AttrIterator, AliasAttr>;
using AliasAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AliasAttr>;
class AliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static AliasAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AliasAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AliasAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIAS;
  }

  static std::optional<AliasAttr> from(const TokenContext &c);
  static std::optional<AliasAttr> from(const Attr &parent);

  inline static std::optional<AliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view aliasee(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(AliasAttr) == sizeof(Attr));

#endif
} // namespace mx
