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
#include "VisibilityAttrVisibilityType.h"

namespace mx {
class Attr;
class InheritableAttr;
class VisibilityAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VisibilityAttrRange = DerivedEntityRange<AttrIterator, VisibilityAttr>;
using VisibilityAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, VisibilityAttr>;
class VisibilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static VisibilityAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VisibilityAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : VisibilityAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::VISIBILITY;
  }

  static std::optional<VisibilityAttr> from(const TokenContext &c);
  static std::optional<VisibilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<VisibilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return VisibilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VisibilityAttr> from(const Attr &parent);

  inline static std::optional<VisibilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return VisibilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  VisibilityAttrVisibilityType visibility(void) const;
};

static_assert(sizeof(VisibilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
