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
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using InheritableAttrRange = DerivedEntityRange<AttrIterator, InheritableAttr>;
using InheritableAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, InheritableAttr>;
class InheritableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static InheritableAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static InheritableAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : InheritableAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<InheritableAttr> from(const TokenContext &c);
  static std::optional<InheritableAttr> from(const Attr &parent);

  inline static std::optional<InheritableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool should_inherit_even_if_already_present(void) const;
};

static_assert(sizeof(InheritableAttr) == sizeof(Attr));

#endif
} // namespace mx
