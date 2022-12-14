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
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class NSConsumedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NSConsumedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NSConsumedAttr>;
class NSConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<NSConsumedAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static NSConsumedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NSConsumedAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_CONSUMED;
  }

  static std::optional<NSConsumedAttr> from(const TokenContext &c);
  static std::optional<NSConsumedAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<NSConsumedAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return NSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSConsumedAttr> from(const InheritableAttr &parent);

  inline static std::optional<NSConsumedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSConsumedAttr> from(const Attr &parent);

  inline static std::optional<NSConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NSConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
