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
class DestructorAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DestructorAttrRange = DerivedEntityRange<AttrIterator, DestructorAttr>;
using DestructorAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, DestructorAttr>;
class DestructorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static DestructorAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DestructorAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DestructorAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DESTRUCTOR;
  }

  static std::optional<DestructorAttr> from(const TokenContext &c);
  static std::optional<DestructorAttr> from(const InheritableAttr &parent);

  inline static std::optional<DestructorAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return DestructorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DestructorAttr> from(const Attr &parent);

  inline static std::optional<DestructorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DestructorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(DestructorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
