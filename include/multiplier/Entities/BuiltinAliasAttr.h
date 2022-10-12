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
#include "BuiltinAliasAttrSpelling.h"

namespace mx {
class Attr;
class BuiltinAliasAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BuiltinAliasAttrRange = DerivedEntityRange<AttrIterator, BuiltinAliasAttr>;
using BuiltinAliasAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinAliasAttr>;
class BuiltinAliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static BuiltinAliasAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinAliasAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BuiltinAliasAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BUILTIN_ALIAS;
  }

  static std::optional<BuiltinAliasAttr> from(const TokenContext &c);
  static std::optional<BuiltinAliasAttr> from(const Attr &parent);

  inline static std::optional<BuiltinAliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BuiltinAliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BuiltinAliasAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(BuiltinAliasAttr) == sizeof(Attr));

#endif
} // namespace mx
