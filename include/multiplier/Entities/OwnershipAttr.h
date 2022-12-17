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
#include "OwnershipAttrOwnershipKind.h"
#include "OwnershipAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class OwnershipAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OwnershipAttrRange = DerivedEntityRange<AttrIterator, OwnershipAttr>;
using OwnershipAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OwnershipAttr>;
class OwnershipAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static OwnershipAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OwnershipAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : OwnershipAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OWNERSHIP;
  }

  static std::optional<OwnershipAttr> from(const TokenContext &c);
  static std::optional<OwnershipAttr> from(const InheritableAttr &parent);

  inline static std::optional<OwnershipAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return OwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OwnershipAttr> from(const Attr &parent);

  inline static std::optional<OwnershipAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OwnershipAttrOwnershipKind own_kind(void) const;
  OwnershipAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  bool is_holds(void) const;
  bool is_returns(void) const;
  bool is_takes(void) const;
};

static_assert(sizeof(OwnershipAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
