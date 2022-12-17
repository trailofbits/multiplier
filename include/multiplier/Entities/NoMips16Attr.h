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
class NoMips16Attr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoMips16AttrRange = DerivedEntityRange<AttrIterator, NoMips16Attr>;
using NoMips16AttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoMips16Attr>;
class NoMips16Attr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NoMips16AttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoMips16AttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : NoMips16Attr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_MIPS16;
  }

  static std::optional<NoMips16Attr> from(const TokenContext &c);
  static std::optional<NoMips16Attr> from(const InheritableAttr &parent);

  inline static std::optional<NoMips16Attr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NoMips16Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoMips16Attr> from(const Attr &parent);

  inline static std::optional<NoMips16Attr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoMips16Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NoMips16Attr) == sizeof(InheritableAttr));

#endif
} // namespace mx
