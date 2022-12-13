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

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class EnforceTCBAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EnforceTCBAttrRange = DerivedEntityRange<AttrIterator, EnforceTCBAttr>;
using EnforceTCBAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnforceTCBAttr>;
class EnforceTCBAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static EnforceTCBAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnforceTCBAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : EnforceTCBAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENFORCE_TCB;
  }

  static std::optional<EnforceTCBAttr> from(const TokenContext &c);
  static std::optional<EnforceTCBAttr> from(const InheritableAttr &parent);

  inline static std::optional<EnforceTCBAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return EnforceTCBAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnforceTCBAttr> from(const Attr &parent);

  inline static std::optional<EnforceTCBAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return EnforceTCBAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  std::string_view tcb_name(void) const;
};

static_assert(sizeof(EnforceTCBAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
