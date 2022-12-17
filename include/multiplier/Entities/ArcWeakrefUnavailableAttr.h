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
class ArcWeakrefUnavailableAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArcWeakrefUnavailableAttrRange = DerivedEntityRange<AttrIterator, ArcWeakrefUnavailableAttr>;
using ArcWeakrefUnavailableAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArcWeakrefUnavailableAttr>;
class ArcWeakrefUnavailableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ArcWeakrefUnavailableAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArcWeakrefUnavailableAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ArcWeakrefUnavailableAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARC_WEAKREF_UNAVAILABLE;
  }

  static std::optional<ArcWeakrefUnavailableAttr> from(const TokenContext &c);
  static std::optional<ArcWeakrefUnavailableAttr> from(const InheritableAttr &parent);

  inline static std::optional<ArcWeakrefUnavailableAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ArcWeakrefUnavailableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArcWeakrefUnavailableAttr> from(const Attr &parent);

  inline static std::optional<ArcWeakrefUnavailableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArcWeakrefUnavailableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ArcWeakrefUnavailableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
