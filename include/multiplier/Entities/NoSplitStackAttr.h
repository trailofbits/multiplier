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
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class NoSplitStackAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoSplitStackAttrRange = DerivedEntityRange<AttrIterator, NoSplitStackAttr>;
using NoSplitStackAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoSplitStackAttr>;
class NoSplitStackAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NoSplitStackAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoSplitStackAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NoSplitStackAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_SPLIT_STACK;
  }

  static std::optional<NoSplitStackAttr> from(const TokenContext &c);
  static std::optional<NoSplitStackAttr> from(const InheritableAttr &parent);

  inline static std::optional<NoSplitStackAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NoSplitStackAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoSplitStackAttr> from(const Attr &parent);

  inline static std::optional<NoSplitStackAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoSplitStackAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NoSplitStackAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
