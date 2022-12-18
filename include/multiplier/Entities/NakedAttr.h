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
class NakedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NakedAttrRange = DerivedEntityRange<AttrIterator, NakedAttr>;
using NakedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NakedAttr>;
class NakedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NakedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NakedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NakedAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NAKED;
  }

  static std::optional<NakedAttr> from(const TokenContext &c);
  static std::optional<NakedAttr> from(const InheritableAttr &parent);

  inline static std::optional<NakedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NakedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NakedAttr> from(const Attr &parent);

  inline static std::optional<NakedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NakedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NakedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
