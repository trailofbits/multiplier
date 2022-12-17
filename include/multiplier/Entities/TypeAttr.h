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
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeAttrRange = DerivedEntityRange<AttrIterator, TypeAttr>;
using TypeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeAttr>;
class TypeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static TypeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : TypeAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<TypeAttr> from(const TokenContext &c);
  static std::optional<TypeAttr> from(const Attr &parent);

  inline static std::optional<TypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TypeAttr) == sizeof(Attr));

#endif
} // namespace mx
