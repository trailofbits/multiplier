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
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class NonNullAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NonNullAttrRange = DerivedEntityRange<AttrIterator, NonNullAttr>;
using NonNullAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NonNullAttr>;
class NonNullAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NonNullAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NonNullAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NonNullAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NON_NULL;
  }

  static std::optional<NonNullAttr> from(const TokenContext &c);
  static std::optional<NonNullAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<NonNullAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return NonNullAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NonNullAttr> from(const InheritableAttr &parent);

  inline static std::optional<NonNullAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NonNullAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NonNullAttr> from(const Attr &parent);

  inline static std::optional<NonNullAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NonNullAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NonNullAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
