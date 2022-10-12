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
class OSConsumesThisAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OSConsumesThisAttrRange = DerivedEntityRange<AttrIterator, OSConsumesThisAttr>;
using OSConsumesThisAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OSConsumesThisAttr>;
class OSConsumesThisAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static OSConsumesThisAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OSConsumesThisAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OSConsumesThisAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OS_CONSUMES_THIS;
  }

  static std::optional<OSConsumesThisAttr> from(const TokenContext &c);
  static std::optional<OSConsumesThisAttr> from(const InheritableAttr &parent);

  inline static std::optional<OSConsumesThisAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return OSConsumesThisAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OSConsumesThisAttr> from(const Attr &parent);

  inline static std::optional<OSConsumesThisAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OSConsumesThisAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(OSConsumesThisAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
